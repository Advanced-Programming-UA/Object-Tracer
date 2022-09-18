#include "utils/tracer.h"
#include "vehicles/Bicycle.h"
#include "vehicles/PassengerRoadVehicle.h"
#include "vehicles/SailBoat.h"

using namespace std;
using namespace Vehicles;

namespace {

void display(Vehicle* p) {
    FUNCTION_TRACER;
    p->info();
}

void displayBis(Vehicle& b) {
    FUNCTION_TRACER;
    b.info();
}

} // namespace

/**
 * Demonstrates late binding.
 * @return      status
 * @exception   None.
 */
int app_poly2() {
    FUNCTION_TRACER;

    // Setting the log output ON/OFF
    TRACER_OUTPUT_OFF;

    LOG_TRACER(">>>> statement: RoadVehicle rv1;");
    RoadVehicle rv1;

    LOG_TRACER(">>>> statement: Bicycle m1(\"Honda\", \"black\");");
    Bicycle m1("Honda", "black");

    LOG_TRACER(">>>> statement: PassengerRoadVehicle prv1(5);");
    PassengerRoadVehicle prv1(5);

    LOG_TRACER(">>>> statement: SailBoat b1(\"Freddy\");");
    SailBoat b1("Freddy");

    // Setting the log output ON/OFF
    TRACER_OUTPUT_ON;

    LOG_TRACER(">>>> statement: displayBis(rv1);");
    displayBis(rv1);

    LOG_TRACER(">>>> statement: displayBis(m1);");
    displayBis(m1);

    LOG_TRACER(">>>> statement: displayBis(prv1);");
    displayBis(prv1);

    LOG_TRACER(">>>> statement: displayBis(b1);");
    displayBis(b1);

    LOG_TRACER(">>>> statement: auto rv2Ptr = new RoadVehicle();");
    auto rv2Ptr = new RoadVehicle();

    LOG_TRACER(" statement: Bicycle* m1Ptr = &m1;");
    Bicycle* m1Ptr = &m1;

    LOG_TRACER(" statement: auto prv2Ptr = new PassengerRoadVehicle(10);");
    auto prv2Ptr = new PassengerRoadVehicle(10);

    LOG_TRACER(">>>> statement: SailBoat* b1Ptr = &b1;");
    auto b1Ptr = &b1;

    LOG_TRACER(">>>> statement: display(rv2Ptr);");
    display(rv2Ptr);

    LOG_TRACER(">>>> statement: display(m1Ptr);");
    display(m1Ptr);

    LOG_TRACER(">>>> statement: displayBis(m1);");
    displayBis(m1);

    LOG_TRACER(">>>> statement: display(prv2Ptr);");
    display(prv2Ptr);

    LOG_TRACER(">>>> statement: display(b1Ptr);");
    display(b1Ptr);

    // delete b1Ptr;
    // Runtime error because of assignment b1Ptr = &b1;
    // So b1Ptr points to local variable that should not be deleted
    // Should have been:
    // delete b1Ptr; b1Ptr = &b1s;
    // in the code a couple of lines earlier.

    // Notice the dynamically allocated object do NOT get destructed: memory
    // leakage.

    LOG_TRACER(">>>> statement: return 0;");
    return 0;
}
