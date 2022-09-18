#include "SailBoat.h"
#include "utils/tracer.h"

namespace Vehicles {

SailBoat::SailBoat(std::string name) : WaterVehicle(), m_name(std::move(name)), m_sails_up(false) { MEMBER_TRACER; }

SailBoat::SailBoat(const SailBoat& ori) : WaterVehicle(ori), m_name(ori.m_name), m_sails_up(ori.m_sails_up) {
    MEMBER_TRACER;
}

SailBoat::SailBoat(SailBoat&& ori) noexcept
    : WaterVehicle(std::move(ori)), m_name(std::move(ori.m_name)), m_sails_up(ori.m_sails_up) {
    MEMBER_TRACER;
}

SailBoat& SailBoat::operator=(const SailBoat& rhs) {
    MEMBER_TRACER;
    if (this != &rhs) {
        WaterVehicle::operator=(rhs);
        m_name = rhs.m_name;
        m_sails_up = rhs.m_sails_up;
    }
    return *this;
}

SailBoat& SailBoat::operator=(SailBoat&& rhs) noexcept {
    MEMBER_TRACER;
    if (this != &rhs) {
        WaterVehicle::operator=(rhs);
        m_name = std::move(rhs.m_name);
        m_sails_up = rhs.m_sails_up;
    }
    return *this;
}

SailBoat::~SailBoat() { MEMBER_TRACER; }

void SailBoat::info() const {
    MEMBER_TRACER;
    std::string s{"I'm a sailboat named \"" + m_name + "\" and my sails are "};
    if (m_sails_up) {
        s.append("up.");
    } else {
        s.append("down.");
    }
    LOG_TRACER(s);
}

void SailBoat::move(double, std::vector<double>) {
    MEMBER_TRACER;
    m_sails_up = true;
}

} // namespace Vehicles
