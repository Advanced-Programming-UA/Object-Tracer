/**
 * @file
 * Implementation for the class Building.
 * @author Thomas Avé
 */

#include <algorithm>
#include <iostream>

#include "Building.h"
#include "Visitor.h"
#include "utils/tracer.h"

namespace tracing_exam_2022_2 {

Building::Building(Person& owner) : m_rooms(), m_neighbours(), m_owner(owner) { MEMBER_TRACER; }

Building::Building(const Person& owner) : m_rooms(), m_neighbours(), m_owner(owner) { MEMBER_TRACER; }

Building::Building(Person&& owner) : m_rooms(), m_neighbours(), m_owner(std::move(owner)) { MEMBER_TRACER; }

Building::Building(const Building& b) : m_rooms(b.m_rooms), m_neighbours(b.m_neighbours), m_owner(b.m_owner) { MEMBER_TRACER; }

Building::Building(Building&& b) : m_rooms(), m_neighbours(), m_owner(std::move(b.m_owner))
{
        MEMBER_TRACER;
        m_rooms.clear();
        m_neighbours.clear();
        m_rooms = std::move(b.m_rooms);
        m_neighbours = std::move(b.m_neighbours);
}

Building::~Building() { MEMBER_TRACER; }

Building& Building::operator=(const Building& other)
{
        MEMBER_TRACER;
        if (this != &other) {
                m_rooms = other.m_rooms;
                m_neighbours = other.m_neighbours;
                m_owner = Person(other.m_owner);
        }
        return *this;
}

Building& Building::operator=(Building&& other)
{
        MEMBER_TRACER;
        if (this != &other) {
                m_rooms.clear();
                m_neighbours.clear();
                m_neighbours = std::move(other.m_neighbours);
                m_rooms = std::move(other.m_rooms);
                m_owner = std::move(other.m_owner);
        }
        return *this;
}

void Building::info() const
{
        MEMBER_TRACER;
        LOG_TRACER(getName() + " containing " + std::to_string(m_rooms.size()) + " rooms:");
        for (auto room : m_rooms) {
                room->info();
        }
        LOG_TRACER("And " + std::to_string(m_neighbours.size()) + " neighbours");
}

std::string Building::getName() const
{
        MEMBER_TRACER;
        return "Generic Building";
}

Person& Building::getOwner()
{
        MEMBER_TRACER;
        return m_owner;
}

void Building::addNeighbour(Building* neighbour)
{
        MEMBER_TRACER;
        if (neighbour != this) {
                m_neighbours.emplace_back(neighbour);
        }
}

void Building::welcome(Visitor& v) {
        MEMBER_TRACER;
        v.visit(this);
}

} // namespace tracing_exam_2022_2
