/**
 * @file
 * Example tracing exam
 * @author Thomas Avé (IDLab/UA)
 */

#include "utils/tracer.h"
#include <iostream>
#include <memory>
#include <stdexcept>

#include "exams/2022_1/HolidayHome.h"
#include "exams/2022_1/Person.h"
#include "exams/2022_1/Road.h"

using namespace tracing_exam_2022_1;

int app_exam_2022_1()
{
    FUNCTION_TRACER;

    LOG_TRACER("statement: Person p1(\"Steve\");");
    Person p1("Steve");

    LOG_TRACER("statement: Person p1(\"Peter\");");
    Person p2("Peter");


    LOG_TRACER("statement: auto b1 = std::make_unique<HolidayHome>(p1, 2);");
    auto b1 = std::make_unique<HolidayHome>(p1, 2);

    LOG_TRACER("statement: auto b2 = std::make_unique<House>(p2, 1);");
    auto b2 = std::make_unique<House>(p2, 1);

    LOG_TRACER("statement: *b2 = *b1;");
    *b2 = *b1;


    LOG_TRACER("statement: Road r1;");
    Road r1;

    LOG_TRACER("statement: r1.addBuilding(std::move(b1), 3);");
    r1.addBuilding(std::move(b1), 3);

    LOG_TRACER("statement: r1.addBuilding(std::move(b2), 1);");
    r1.addBuilding(std::move(b2), 1);

    LOG_TRACER("statement: Visitor v;");
    Visitor v;

    LOG_TRACER("statement: r1.welcome(v);");
    r1.welcome(v);


    LOG_TRACER("statement: Building& b3 = r1.getBuilding(1);");
    Building& b3 = r1.getBuilding(1);

    LOG_TRACER("statement: Building* b4 = &r1.getBuilding(3);");
    Building* b4 = &r1.getBuilding(3);

    LOG_TRACER("statement: b4 = &b3;");
    b4 = &b3;

    LOG_TRACER("statement: b4->welcome(v);");
    b4->welcome(v);


    LOG_TRACER("statement: r1.removeBuilding(3);");
    r1.removeBuilding(3);

    LOG_TRACER("statement: Road r2 = r1;");
    Road r2 = r1;

    LOG_TRACER("statement: r2.welcome(v);");
    r2.welcome(v);

    LOG_TRACER("statement: return 0;");
    return 0;
}
