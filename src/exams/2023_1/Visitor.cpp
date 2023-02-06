/**
 * @file
 * Implementation for the class Visitor.
 * @author Thomas Avé
 */

#include "Visitor.h"
#include "HolidayHome.h"
#include "utils/tracer.h"

namespace tracing_exam_2023_1 {

Visitor::Visitor() {
    MEMBER_TRACER;
}

Visitor::~Visitor() {
    MEMBER_TRACER;
}

template<>
void Visitor::visit(Rentable* h) {
    MEMBER_TRACER;
    LOG_TRACER("Visiting a Rentable");
    h->rent(Person("The Visitor"));
}

} // namespace tracing_exam_2023_1
