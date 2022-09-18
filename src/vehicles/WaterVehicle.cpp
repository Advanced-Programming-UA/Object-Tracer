#include "WaterVehicle.h"
#include "utils/tracer.h"

namespace Vehicles {

using namespace std;

WaterVehicle::WaterVehicle() : Vehicle(), m_sinking(false) { MEMBER_TRACER; }

WaterVehicle::WaterVehicle(const WaterVehicle& ori) : Vehicle(ori), m_sinking(ori.m_sinking) { MEMBER_TRACER; }

WaterVehicle::WaterVehicle(WaterVehicle&& ori) noexcept : Vehicle(ori), m_sinking(ori.m_sinking) { MEMBER_TRACER; }

WaterVehicle& WaterVehicle::operator=(const WaterVehicle& rhs) {
    MEMBER_TRACER;
    if (this != &rhs) {
        Vehicle::operator=(rhs);
        m_sinking = rhs.m_sinking;
    }
    return *this;
}

WaterVehicle& WaterVehicle::operator=(WaterVehicle&& rhs) noexcept {
    MEMBER_TRACER;
    if (this != &rhs) {
        Vehicle::operator=(rhs);
        m_sinking = rhs.m_sinking;
    }
    return *this;
}

WaterVehicle::~WaterVehicle() { MEMBER_TRACER; }

void WaterVehicle::info() const {
    MEMBER_TRACER;
    string s{"I'm a generic Water vehicle"};
    if (m_sinking) {
        s.append(" and I'm sinking!");
    }
    LOG_TRACER(s);
}

void WaterVehicle::start_sinking() {
    MEMBER_TRACER;
    m_sinking = true;
}

void WaterVehicle::stop_sinking() {
    MEMBER_TRACER;
    m_sinking = false;
}

} // namespace Vehicles
