#include "demos.h"
#include "vehicles/Body.h"
#include "vehicles/Motorcycle.h"
#include "vehicles/Unicycle.h"
#include "utils/tracer.h"
#include <iostream>

using namespace std;
using namespace Vehicles;

/**
 * Demo prog for features of ctor/dtor.
 * @return      status
 * @exception   None.
 */
int app_essentialops()
{
        FUNCTION_TRACER;
        {
                BLOCK_TRACER("First block");

                LOG_TRACER(" statement: shared_ptr<Engine> e1(new Engine(50));");
                shared_ptr<Engine> e1(new Engine(50));

                LOG_TRACER(" statement: Unicycle u1();");
                Unicycle u1;

                LOG_TRACER(" statement: Motorcycle m1(&e1);");
                Motorcycle m1(e1);
        }
        {
                BLOCK_TRACER("Second block");

                LOG_TRACER(" statement: Motorcycle m1;");
                Motorcycle m1;

                LOG_TRACER(" statement: m.accelerate(1.0);");
                m1.accelerate(1.0);

                LOG_TRACER(" statement: Motorcycle m2(m1);");
                Motorcycle m2(m1);

                LOG_TRACER(" statement: Motorcycle m3(std::move(m1));");
                Motorcycle m3(std::move(m1));

                LOG_TRACER(" statement: m3 = std::move(m2);");
                m3 = std::move(m2);
        }
        {
                BLOCK_TRACER("Block for free store ctor/dtor");

                LOG_TRACER(" statement: shared_ptr<Engine> ep1(new Engine(80));");
                shared_ptr<Engine> ep1(new Engine(80));

                LOG_TRACER(" statement: auto mp1 = new Motorcycle(ep1);");
                auto mp1 = new Motorcycle(ep1);

                LOG_TRACER(" statement: delete mp1;");
                delete mp1;
        }

        LOG_TRACER(" statement: return 0;");
        return 0;
}
