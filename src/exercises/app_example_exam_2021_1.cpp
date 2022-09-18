/**
 * @file
 * Example tracing exam
 * @author Thomas Avé (IDLab/UA)
 */

#include "demos.h"
#include "utils/tracer.h"
#include <iostream>
#include <stdexcept>

#include "buildings/HolidayHome.h"
#include "buildings/Person.h"

using namespace tracing_example_exam;

int app_example_exam_2021_1() {
    FUNCTION_TRACER;
    {
        BLOCK_TRACER("First block");
        LOG_TRACER("statement: Person p1(\"Steve\");");
        Person p1("Steve"); // Note that this is tracing_exam::Person, not ODemo::Person!

        LOG_TRACER("statement: Person p2(\"Peter\");");
        Person p2("Peter");

        LOG_TRACER("statement: HolidayHome h1(p1, 1);");
        HolidayHome h1(p1, 1);

        LOG_TRACER("statement: HolidayHome* h2 = new HolidayHome(p2, 2)");
        HolidayHome* h2 = new HolidayHome(p2, 2);

        LOG_TRACER("statement: h1 = *h2;");
        h1 = *h2;

        LOG_TRACER("statement: Building* h3 = &h1;");
        Building* h3 = &h1;

        LOG_TRACER("statement: h3 = h2;");
        h3 = h2;

        LOG_TRACER("statement: h3->addNeighbour(&h1);");
        h3->addNeighbour(&h1);

        LOG_TRACER("statement: h1.addNeighbour(h2);");
        h1.addNeighbour(h2);

        LOG_TRACER("statement: h1.info();");
        h1.info();

        LOG_TRACER("statement: h1 = std::move(*h2);");
        h1 = std::move(*h2);

        LOG_TRACER("statement: delete h2;");
        delete h2;

        LOG_TRACER("End of the first block");
    }
    {
        BLOCK_TRACER("Second block");
        try {
            BLOCK_TRACER("Try block");

            TRACER_OUTPUT_OFF;    // Temporarily setting  the  log  output OFF
            Person p1("Steve");   // Should not produce any logs
            Person p2("Peter");   // Should not produce any logs
            Person p3("Harry");   // Should not produce any logs
            HolidayHome h(p1, 1); // Should not produce any logs
            TRACER_OUTPUT_ON;     // Setting  the  log  output back ON,
                                  // including for objects created when it was OFF

            LOG_TRACER("statement: h.rent(p2);");
            h.rent(p2);

            LOG_TRACER("statement: h.rent(p3);");
            h.rent(p3);

            LOG_TRACER("statement: h.info();");
            h.info();

        } catch (std::runtime_error& e) {
            LOG_TRACER(e.what());
        }

        LOG_TRACER("End of the second block");
    }
    LOG_TRACER("statement: return 0;");
    return 0;
}
