#include "utils/tracer.h"
#include "vehicles/Bicycle.h"
#include "vehicles/Exception.h"
#include "vehicles/SailBoat.h"
#include <iostream>

using namespace Vehicles;
using namespace std;

/**
 * Demo prog for ctor/dtor features in class derivation.
 * @return      status
 * @exception   None.
 */
int app_exception() {
    FUNCTION_TRACER;
    try {
        BLOCK_TRACER("Try block");

        LOG_TRACER(" statement: Bicycle m1(\"Honda\", \"red\");");
        Bicycle m1("Honda", "red");

        LOG_TRACER(" statement: m1.get_nfo();");
        m1.info();

        LOG_TRACER(" statement: SailBoat s1(\"Marina\");");
        SailBoat s1("Marina");
        ;

        vector<double> direction(2);
        direction[0] = 1.0;
        direction[1] = -1.0;
        LOG_TRACER(" statement: s1.move(4, direction);");
        s1.move(4, direction);

        if (direction[0] == 1.0) {
            throw SailingException("Help");
        }

        LOG_TRACER(" statement: s1.startSinking();");
        s1.start_sinking();

        LOG_TRACER(" statement: s1.displayInfo();");
        s1.info();
    } catch (LoadingException& e) {
        LOG_TRACER(" catch clause with LoadingException");
        e.info();
    } catch (SailingException& e) {
        LOG_TRACER(" catch clause with SailingException");
        e.info();
    } catch (Exception& e) {
        LOG_TRACER(" catch clause with Exception");
        e.info();
        LOG_TRACER(e.what());
    }
    LOG_TRACER(" statement: return 0;");
    return 0;
}
