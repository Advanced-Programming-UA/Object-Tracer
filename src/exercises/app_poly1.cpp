#include "utils/tracer.h"
#include "vehicles/Bicycle.h"
#include "vehicles/PassengerRoadVehicle.h"
#include "vehicles/SailBoat.h"

#include <iostream>
#include <list>
#include <memory>

using namespace std;
using namespace Vehicles;

namespace {

void display_all(list<shared_ptr<Vehicle>> l) {
    FUNCTION_TRACER;
    for (const auto& p : l) {
        p->info();
    }
}

} // namespace

/**
 * Demonstrates late binding.
 * @return      status
 * @exception   None.
 */
int app_poly1() {
    FUNCTION_TRACER;

    TRACER_OUTPUT_OFF; // Setting the log output ON/OFF
    list<shared_ptr<Vehicle>> l1{make_shared<RoadVehicle>(), make_shared<RoadVehicle>(),
                                 make_shared<PassengerRoadVehicle>(5)};

    TRACER_OUTPUT_ON; // Setting the log output ON/OFF
    LOG_TRACER("invocation for l1:");
    display_all(l1);
    LOG_TRACER("done with l1.");

    TRACER_OUTPUT_OFF; // Setting the log output ON/OFF
    list<shared_ptr<Vehicle>> l2{make_shared<RoadVehicle>(), make_shared<Bicycle>("Honda", "black"),
                                 make_shared<SailBoat>("Freddy")};

    TRACER_OUTPUT_ON; // Setting the log output ON/OFF
    LOG_TRACER("invocation for l2:");
    display_all(l2);
    LOG_TRACER("done with l2.");

    LOG_TRACER(">>>> statement: return 0;");
    return 0;
}
