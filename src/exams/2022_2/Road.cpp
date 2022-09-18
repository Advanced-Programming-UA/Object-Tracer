/**
 * @file
 * Implementation for the class Road.
 * @author Thomas Avé
 */

#include "Road.h"
#include "utils/tracer.h"

#include <memory>
#include <stdexcept>

namespace tracing_exam_2022_2 {

Road::Road() : m_buildings() { MEMBER_TRACER; }

Road::~Road() { MEMBER_TRACER; }

Road::Road(const Road& other): m_buildings() {
    MEMBER_TRACER;
    for (auto const& [key, val]: other.m_buildings) {
        m_buildings[key] = std::make_unique<Building>(*val);
    }
}

Road::Road(Road&& other) : m_buildings(std::move(other.m_buildings)) { MEMBER_TRACER; }

Road& Road::operator=(const Road& other)
{
    MEMBER_TRACER;
    if (this != &other) {
        m_buildings.clear();
        for (auto const& [key, val]: other.m_buildings) {
            m_buildings[key] = std::make_unique<Building>(*val);
        }
    }
    return *this;
}

Road& Road::operator=(Road&& other)
{
    MEMBER_TRACER;
    if (this != &other) {
        m_buildings = std::move(other.m_buildings);
    }
    return *this;
}

void Road::addBuilding(std::unique_ptr<Building> b, unsigned int number) {
    MEMBER_TRACER;
    if (hasBuilding(number)) {
        throw std::runtime_error("A Building already exists at this number!");
    }
    for (int a: {-1, 1}){
        int neighbour_number = number + (a*2);
        if (hasBuilding(neighbour_number)) {
            m_buildings.at(neighbour_number)->addNeighbour(b.get());
            b->addNeighbour(m_buildings.at(neighbour_number).get());
        }
    }
    m_buildings.insert(std::make_pair(number, std::move(b)));
    notify(Event::BuildingAdded);
}

void Road::removeBuilding(unsigned int number) {
    MEMBER_TRACER;
    if (!hasBuilding(number)) {
        throw std::runtime_error("This Road does not contain a Building at the given number!");
    }
    m_buildings.erase(number);
    notify(Event::BuildingRemoved);
}

Building& Road::getBuilding(unsigned int number) {
    MEMBER_TRACER;
    if (!hasBuilding(number)) {
        throw std::runtime_error("This Road does not contain a Building at the given number!");
    }
    return *m_buildings.at(number);
}

bool Road::hasBuilding(int number) const {
    MEMBER_TRACER;
    return m_buildings.count(number);
}

void Road::welcome(Visitor& v) {
    MEMBER_TRACER;
    for (auto const& [key, val]: m_buildings) {
        val->welcome(v);
    }
}

} // namespace tracing_exam_2022_2
