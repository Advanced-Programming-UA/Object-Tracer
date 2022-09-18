/**
 * @file
 * Tracing Exam September 2022
 * @author Thomas Avé (IDLab/UA)
 */

#include "exams/2022_2/RoadObserver.h"
#include "exams/2022_2/RentableObserver.h"
#include "exams/2022_2/Road.h"
#include "exams/2022_2/Visitor.h"
#include "exams/2022_2/HolidayHome.h"
#include "exams/2022_2/Person.h"

#include <stdexcept>

using namespace tracing_exam_2022_2;

int app_exam_2022_2()
{
    FUNCTION_TRACER;

    try {
        BLOCK_TRACER("Try block");

        LOG_TRACER("statement: Visitor v;");
        Visitor v;

        LOG_TRACER("statement: Person p(\"Steve\");");
        Person p("Steve");

        LOG_TRACER("statement: auto b1 = std::make_unique<HolidayHome>(p, 2);");
        auto b1 = std::make_unique<HolidayHome>(p, 2);

        LOG_TRACER("statement: auto b2 = std::make_unique<House>(*b1);");
        auto b2 = std::make_unique<House>(*b1);

        LOG_TRACER("statement: Road r1;");
        Road r1;

        {
            BLOCK_TRACER("Observer block");

            LOG_TRACER("statement: auto roadObserver = std::make_shared<RoadObserver>();");
            auto roadObserver = std::make_shared<RoadObserver>();

            LOG_TRACER("statement: roadObserver->attach(&r1);");
            roadObserver->attach(&r1);

            LOG_TRACER("statement: auto rentingObserver = std::make_shared<RentableObserver>();");
            auto rentingObserver = std::make_shared<RentableObserver>();

            LOG_TRACER("statement: rentingObserver->attach(b1.get());");
            rentingObserver->attach(b1.get());

        }

        LOG_TRACER("statement: b1->rent(Person(\"Peter\"));");
        b1->rent(Person("Peter"));

        LOG_TRACER("statement: r1.addBuilding(std::move(b1), 1);");
        r1.addBuilding(std::move(b1), 1);

        LOG_TRACER("statement: r1.addBuilding(std::move(b2), 3);");
        r1.addBuilding(std::move(b2), 3);

        LOG_TRACER("statement: Building b3 = r1.getBuilding(3);");
        Building b3 = r1.getBuilding(3);

        LOG_TRACER("statement: Building& b4 = r1.getBuilding(1);");
        Building& b4 = r1.getBuilding(1);

        LOG_TRACER("r1.getBuilding(1) = b3;");
        r1.getBuilding(1) = b3;

        LOG_TRACER("statement: r1.welcome(v);");
        r1.welcome(v);

    } catch (std::runtime_error& e) {
        LOG_TRACER(e.what());
    }

    LOG_TRACER("statement: return 0;");
    return 0;
}
