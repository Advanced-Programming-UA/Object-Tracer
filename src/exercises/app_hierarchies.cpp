#include "utils/tracer.h"
#include "vehicles/Bicycle.h"
#include "vehicles/SailBoat.h"

using namespace Vehicles;
using namespace std;

/**
 * Demo prog for ctor/dtor features in class derivation.
 * @return      status
 * @exception   None.
 */
int app_hierarchies()
{
        FUNCTION_TRACER;

        LOG_TRACER(" statement: Bicycle m1(\"Honda\", \"red\");");
        Bicycle m1("Honda", "red");

        LOG_TRACER(" statement: m1.displayInfo();");
        m1.info();

        LOG_TRACER(" statement: Bicycle m2(m1);");
        Bicycle m2(m1);

        LOG_TRACER(" statement: m2.addPassenger();");
        m2.add_passenger();

        LOG_TRACER(" statement: m2.displayInfo();");
        m2.info();

        LOG_TRACER(" statement: Bicycle* m3Ptr = new Bicycle(m2);");
        auto m3Ptr = new Bicycle(m2);

        LOG_TRACER(" statement: m3Ptr->displayInfo()");
        m3Ptr->info();

        LOG_TRACER(" statement: m2 = m1;");
        m2 = m1;

        LOG_TRACER(" statement: delete m3Ptr;");
        delete m3Ptr;

        LOG_TRACER(" statement: SailBoat s1(\"Marina\");");
        SailBoat s1("Marina");

        LOG_TRACER(" statement: SailBoat s1(\"Freddy\");");
        SailBoat s2("Freddy");

        vector<double> direction(2);
        direction[0] = 1.0;
        direction[1] = -1.0;
        LOG_TRACER(" statement: s1.move(4, direction);");
        s1.move(4, direction);

        LOG_TRACER(" statement: s1.startSinking();");
        s1.start_sinking();

        LOG_TRACER(" statement: s1.displayInfo();");
        s1.info();

        LOG_TRACER(" statement: Vehicle* v1Ptr = &s1;");
        Vehicle* v1Ptr = &s1;

        LOG_TRACER(" statement: v1Ptr->displayInfo();");
        v1Ptr->info();

        LOG_TRACER(" statement: s2 = s1;");
        s2 = s1;

        LOG_TRACER(" statement: s2.displayInfo();");
        s2.info();

        // The following won't compile because WaterVehicle has pure virtual
        // functions.
        // WaterVehicle wv1(s1);

        LOG_TRACER(" statement: return 0;");
        return 0;
}
