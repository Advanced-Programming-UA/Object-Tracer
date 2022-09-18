#include "RoadVehicle.h"
#include "utils/tracer.h"

namespace Vehicles {

using namespace std;

RoadVehicle::RoadVehicle() : LandVehicle() { MEMBER_TRACER; }

RoadVehicle::RoadVehicle(const RoadVehicle& ori) : LandVehicle(ori) { MEMBER_TRACER; }

RoadVehicle::RoadVehicle(RoadVehicle&& ori) noexcept : LandVehicle(std::move(ori)) { MEMBER_TRACER; }

RoadVehicle& RoadVehicle::operator=(const RoadVehicle& rhs) {
    MEMBER_TRACER;
    if (this != &rhs) {
        LandVehicle::operator=(rhs);
    }
    return *this;
}

RoadVehicle& RoadVehicle::operator=(RoadVehicle&& rhs) noexcept {
    MEMBER_TRACER;
    if (this != &rhs) {
        LandVehicle::operator=(rhs);
    }
    return *this;
}

RoadVehicle::~RoadVehicle() { MEMBER_TRACER; }

void RoadVehicle::info() const {
    MEMBER_TRACER;
    const string s{"I'm a generic Road vehicle"};
    LOG_TRACER(s);
}

void RoadVehicle::move(double, vector<double>) { MEMBER_TRACER; }

} // namespace Vehicles
