#include "PassengerRoadVehicle.h"
#include "utils/tracer.h"
#include <iostream>
#include <sstream>

namespace Vehicles {

using namespace std;

PassengerRoadVehicle::PassengerRoadVehicle(int numSeats) : RoadVehicle(), m_capacity(numSeats), m_free(numSeats) {
    MEMBER_TRACER;
}

PassengerRoadVehicle::PassengerRoadVehicle(const PassengerRoadVehicle& ori)
    : RoadVehicle(ori), m_capacity(ori.m_capacity), m_free(ori.m_free) {
    MEMBER_TRACER;
}

PassengerRoadVehicle::PassengerRoadVehicle(PassengerRoadVehicle&& ori) noexcept
    : RoadVehicle(std::move(ori)), m_capacity(ori.m_capacity), m_free(ori.m_free) {
    MEMBER_TRACER;
}

PassengerRoadVehicle& PassengerRoadVehicle::operator=(const PassengerRoadVehicle& rhs) {
    MEMBER_TRACER;
    if (this != &rhs) {
        RoadVehicle::operator=(rhs);
        m_capacity = rhs.m_capacity;
        m_free = rhs.m_free;
    }
    return *this;
}

PassengerRoadVehicle& PassengerRoadVehicle::operator=(PassengerRoadVehicle&& rhs) noexcept {
    MEMBER_TRACER;
    if (this != &rhs) {
        RoadVehicle::operator=(rhs);
        m_capacity = rhs.m_capacity;
        m_free = rhs.m_free;
    }
    return *this;
}

PassengerRoadVehicle::~PassengerRoadVehicle() { MEMBER_TRACER; }

bool PassengerRoadVehicle::add_passenger() {
    MEMBER_TRACER;
    bool added = false;
    if (m_free > 0) {
        m_free--;
        added = true;
    }
    return added;
}

bool PassengerRoadVehicle::remove_passenger() {
    MEMBER_TRACER;
    bool removed = false;
    if (m_free < m_capacity) {
        m_free++;
        removed = true;
    }
    return removed;
}

int PassengerRoadVehicle::get_capacity() const {
    MEMBER_TRACER;
    return m_capacity;
}

int PassengerRoadVehicle::get_free() const {
    MEMBER_TRACER;
    return m_free;
}

void PassengerRoadVehicle::info() const {
    MEMBER_TRACER;
    const string s{"I'm a PassengerRoadVehicle: #seats = " + std::to_string(m_capacity) +
                   ", #free seats = " + std::to_string(m_free)};
    LOG_TRACER(s);
}

} // namespace Vehicles
