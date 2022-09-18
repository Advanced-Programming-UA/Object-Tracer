/**
 * @file
 * Implementation for the class House.
 * @author Thomas Avé
 */

#include "House.h"
#include "Visitor.h"
#include "utils/tracer.h"

#include "BedRoom.h"
#include <ios>
#include <memory>
#include <utility>

namespace tracing_exam_2022_1 {

House::House(Person owner, unsigned int bedrooms) : Building(std::move(owner)), m_kitchen()
{
        MEMBER_TRACER;

        for (unsigned int i = 0; i < bedrooms; i++) {
                m_rooms.emplace_back(std::make_shared<const BedRoom>());
        }
        m_rooms.emplace_back(m_bathroom);
}

House::House(const House& h) : Building(h), m_bathroom(h.m_bathroom), m_kitchen(h.m_kitchen)
{
        MEMBER_TRACER;
}

House::House(House&& h) : Building(std::move(h)), m_bathroom(std::move(h.m_bathroom)), m_kitchen(std::move(h.m_kitchen))
{
        MEMBER_TRACER;
}

House& House::operator=(const House& other)
{
        MEMBER_TRACER;
        if (this != &other) {
                Building::operator=(other);
                m_bathroom = other.m_bathroom;
                m_kitchen = other.m_kitchen;
        }
        return *this;
}

House& House::operator=(House&& other)
{
        MEMBER_TRACER;
        if (this != &other) {
                Building::operator=(std::move(other));
                m_bathroom = std::move(other.m_bathroom);
                m_kitchen = std::move(other.m_kitchen);
        }
        return *this;
}

House::~House() { MEMBER_TRACER; }

std::string House::getName() const
{
        MEMBER_TRACER;
        return "House";
}

void House::addNeighbour(House* neighbour)
{
        MEMBER_TRACER;
        if (neighbour != this) {
                m_neighbours.emplace_back(neighbour);
        }
}

void House::welcome(Visitor& v) {
        MEMBER_TRACER;
        v.visit(this);
}

} // namespace tracing_exam_2022_1
