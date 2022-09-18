#include "utils/tracer.h"
#include "vehicles/Engine.h"
#include "vehicles/Person.h"
#include "vehicles/Motorcycle.h"

#include <memory>

using namespace std;
using namespace Vehicles;

/**
 * Demo prog to demonstrate deep & shallow copy operations.
 * @return      status
 * @exception   None.
 */
int app_copy()
{
        FUNCTION_TRACER;

        LOG_TRACER(" statement: shared_ptr<Engine> e1Ptr(new Engine(100));");
        shared_ptr<Engine> e1Ptr(new Engine(100));

        LOG_TRACER(" statement: Person* p1Ptr = new Person(\"Owner 1\");");
        auto p1Ptr = new Person("Owner 1");

        LOG_TRACER(" statement: Motorcycle* m1Ptr = new Motorcycle(e1Ptr, p1Ptr);");
        auto m1Ptr = new Motorcycle(e1Ptr, p1Ptr);

        LOG_TRACER(" statement: m1Ptr->startEngine();");
        m1Ptr->startEngine();

        LOG_TRACER(" statement: Motorcycle* m2Ptr = new Motorcycle(*m1Ptr);");
        auto m2Ptr = new Motorcycle(*m1Ptr);

        LOG_TRACER(" statement: Motorcycle m3(shared_ptr<Engine>(new Engine(77)));");
        Motorcycle m3(make_shared<Engine>(77));

        LOG_TRACER(" statement: m3 = *m2Ptr;");
        m3 = *m2Ptr;

        LOG_TRACER(" statement: m3.stopEngine();");
        m3.stopEngine();

        LOG_TRACER(" statement: delete p1Ptr;");
        delete p1Ptr;

        LOG_TRACER(" statement: delete m1Ptr;");
        delete m1Ptr;

        LOG_TRACER(" statement: delete m2Ptr;");
        delete m2Ptr;

        LOG_TRACER(" statement: return 0;");
        return 0;
}
