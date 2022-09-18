/**
 * @file
 * Tracing exam, August 2021
 * @author Thomas Avé (IDLab/UA)
 */

#include "demos.h"
#include "utils/tracer.h"
#include <iostream>
#include <memory>
#include <stdexcept>

#include "buildings/Building.h"
#include "buildings/HolidayHome.h"
#include "buildings/Person.h"

using namespace tracing_example_exam;

namespace {
void f(HolidayHome&) { FUNCTION_TRACER; }

void f(const HolidayHome&) { FUNCTION_TRACER; }
void f(House&) { FUNCTION_TRACER; }
void f(const House&) { FUNCTION_TRACER; }

// Make sure you provide the actual type T for each template instantiation
// For example:   ---> function body: T copy(const T&) [with T = tracing_exam::Person]
template <typename T>
T copy(const T& t) {
    FUNCTION_TRACER;
    return T(t);
}
} // namespace

int app_example_exam_2021_2() {
    FUNCTION_TRACER;
    {
        BLOCK_TRACER("First block");

        LOG_TRACER("statement: const Person p1(\"Steve\");");
        Person p1("Steve"); // Note that this is tracing_example_exam::Person, not Vehicle::Person!

        LOG_TRACER("statement: Building b1(p1);");
        Building b1(p1);

        LOG_TRACER("statement: Building b2(*std::make_shared<Person>(std::move(p1)));");
        Building b2(*std::make_shared<Person>(std::move(p1)));

        LOG_TRACER("statement: Building* b3 = copy(new Building(Person(b2.getOwner())));");
        Building* b3 = copy(new Building(Person(b2.getOwner())));

        LOG_TRACER("statement: Building* b4 = b3;");
        Building* b4 = b3;

        LOG_TRACER("statement: b2 = *b3;");
        b2 = *b3;

        LOG_TRACER("statement: b3 = &b1;");
        b3 = &b1;

        LOG_TRACER("statement: b1 = b2;");
        b1 = b2;

        LOG_TRACER("statement: delete b4;");
        delete b4;

        LOG_TRACER("End of the first block");
    }
    {
        BLOCK_TRACER("Second block");

        try {
            BLOCK_TRACER("Try block");

            LOG_TRACER("statement: Person p1(\"Dave\");");
            Person p1("Dave");

            LOG_TRACER("statement: Person p2(\"Peter\");");
            Person p2("Peter");

            LOG_TRACER("statement: Person p3(\"Harry\");");
            Person p3("Harry");

            LOG_TRACER("statement: HolidayHome* h1 = new HolidayHome(p1, 2);");
            HolidayHome* h1 = new HolidayHome(p1, 2);

            LOG_TRACER("statement: const HolidayHome* h2 = h1;");
            const HolidayHome* h2 = h1;

            LOG_TRACER("statement: House h3 = copy(*h1);");
            House h3 = copy(*h1);

            LOG_TRACER("statement: auto h4 = copy(h2);");
            auto h4 = copy(h2);

            LOG_TRACER("statement: auto h5 = copy<const House*>(h2);");
            auto h5 = copy<const House*>(h2);

            LOG_TRACER("statement: f(*h1);");
            f(*h1);

            LOG_TRACER("statement: f(*h2);");
            f(*h2);

            LOG_TRACER("statement: f(h3);");
            f(h3);

            LOG_TRACER("statement: f(House(h3));");
            f(House(h3));

            LOG_TRACER("statement: h1->rent(p2);");
            h1->rent(p2);

            LOG_TRACER("statement: h1->rent(p3);");
            h1->rent(p3);

            LOG_TRACER("statement: h3.info();");
            h3.info();

            LOG_TRACER("statement: delete h1;");
            delete h1;

        } catch (std::runtime_error& e) {
            LOG_TRACER(e.what());
        }

        LOG_TRACER("End of the second block");
    }
    LOG_TRACER("statement: return 0;");
    return 0;
}
