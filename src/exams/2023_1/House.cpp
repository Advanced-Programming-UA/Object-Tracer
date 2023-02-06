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

namespace tracing_exam_2023_1 {

House::House(Person& owner) : House(std::move(owner), 2) {
    MEMBER_TRACER;
}

House::House(Person&& owner, unsigned int bedrooms) : Building(owner), m_bathroom(new BathRoom())
{
    MEMBER_TRACER;
    for (unsigned int i = 0; i < bedrooms; i++) {
        BLOCK_TRACER("For Loop");
        BedRoom b;
        m_rooms.emplace_back(std::make_unique<BedRoom>(b));
    }
}

House::House(const House& h) : Building(h), m_kitchen(std::make_unique<Kitchen>(*h.m_kitchen)), m_bathroom(new BathRoom(*h.m_bathroom))
{
    MEMBER_TRACER;
}

House::House(House&& h) : Building(std::move(h)), m_kitchen(std::move(h.m_kitchen)), m_bathroom(h.m_bathroom)
{
    MEMBER_TRACER;
    h.m_bathroom = nullptr;
}

House& House::operator=(const House& other)
{
        MEMBER_TRACER;
        if (this != &other) {
                Building::operator=(other);
                *m_bathroom = *other.m_bathroom;
                *m_kitchen = *other.m_kitchen;
        }
        return *this;
}

House& House::operator=(House&& other)
{
        MEMBER_TRACER;
        if (this != &other) {
                Building::operator=(std::move(other));

                if (m_bathroom)
                    delete m_bathroom;

                m_bathroom = other.m_bathroom;
                other.m_bathroom = nullptr;

                m_kitchen = std::move(other.m_kitchen);
        }
        return *this;
}

House::~House() {
    MEMBER_TRACER;
    if (m_bathroom)
        delete m_bathroom;
}

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

} // namespace tracing_exam_2023_1
