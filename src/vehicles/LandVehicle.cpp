#include "LandVehicle.h"
#include "utils/tracer.h"

namespace Vehicles {

using namespace std;

LandVehicle::LandVehicle() : Vehicle() { MEMBER_TRACER; }

LandVehicle::LandVehicle(const LandVehicle& ori) : Vehicle(ori) { MEMBER_TRACER; }

LandVehicle::LandVehicle(LandVehicle&& ori) noexcept : Vehicle(ori) { MEMBER_TRACER; }

LandVehicle& LandVehicle::operator=(const LandVehicle& rhs) {
    MEMBER_TRACER;
    if (this != &rhs) {
        Vehicle::operator=(rhs);
    }
    return *this;
}

LandVehicle& LandVehicle::operator=(LandVehicle&& rhs) noexcept {
    MEMBER_TRACER;
    if (this != &rhs) {
        Vehicle::operator=(rhs);
    }
    return *this;
}

LandVehicle::~LandVehicle() { MEMBER_TRACER; }

void LandVehicle::info() const {
    MEMBER_TRACER;
    const string s{"I'm a generic Land vehicle"};
    LOG_TRACER(s);
}

} // namespace Vehicles
