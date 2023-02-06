/**
 * @file
 * Tracing Exam January 2023
 * @author Thomas Avé (IDLab/UA)
 */

#include "exams/2023_1/HolidayHome.h"

using namespace tracing_exam_2023_1;

Person& getBob() {
    FUNCTION_TRACER;
    static Person p("Bob");
    return p;
}

int app_exam_2023_1()
{
    FUNCTION_TRACER;
    {
        BLOCK_TRACER("Block 1");

        LOG_TRACER("statement: auto b1 = std::make_unique<HolidayHome>(getBob());");
        auto b1 = std::make_unique<HolidayHome>(getBob());

        LOG_TRACER("statement: auto b2 = &*b1;;");
        auto b2 = &*b1;

        LOG_TRACER("statement: *b1 = *b2;");
        *b1 = *b2;

        LOG_TRACER("statement: House b3 = *b2;");
        House b3 = *b2;

        LOG_TRACER("statement: House* b4 = &b3;");
        House* b4 = &b3;

        LOG_TRACER("statement: b4 = b2;");
        b4 = b2;

        LOG_TRACER("statement: b5 = &b4");
        auto b5 = &b4;

        LOG_TRACER("statement: *b5 = &*b1;");
        *b5 = &*b1;

        LOG_TRACER("statement: **b5 = std::move(b3);");
        **b5 = std::move(b3);

        LOG_TRACER("statement: Building b6 = std::move(*b4);");
        Building b6 = std::move(*b4);

        LOG_TRACER("End of the first block");
    }

    {
        BLOCK_TRACER("Block 2");

        LOG_TRACER("statement: Building b1(getBob());");
        Building b1(getBob());

        LOG_TRACER("statement: Rentable r;");
        Rentable r;

        LOG_TRACER("statement: bool use_bob = true;");
        bool use_bob = true;

        LOG_TRACER("statement: auto rent = [=, &r]() {...};");
        auto rent = [=, &r]() {
            FUNCTION_TRACER;

            LOG_TRACER("statement: Person alice(\"Alice\");");
            Person alice("Alice");

            LOG_TRACER("statement: r.rent(...)");
            if (use_bob) {
                r.rent(b1.getOwner());
            } else {
                r.rent(alice);
            }

            LOG_TRACER("Building rented successfully");
        };

        try {
            BLOCK_TRACER("Try block");

            LOG_TRACER("statement: rent();");
            rent();

            LOG_TRACER("statement: use_bob = false;");
            use_bob = false;

            LOG_TRACER("statement: rent();");
            rent();

        } catch (std::runtime_error& e) {
            LOG_TRACER(e.what());
        }

        LOG_TRACER("End of the second block");
    }

    LOG_TRACER("statement: return 0;");
    return 0;
}
