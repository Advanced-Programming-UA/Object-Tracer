/**
 * @file
 * Implementation for the class Visitor.
 * @author Thomas Avé
 */

#include "Visitor.h"
#include "HolidayHome.h"
#include "utils/tracer.h"

namespace tracing_exam_2022_1 {

Visitor::Visitor() {
    MEMBER_TRACER;
}

template<>
void Visitor::visit(HolidayHome* h) {
    MEMBER_TRACER;
    LOG_TRACER("Visiting a " + h->getName());
    h->rent(Person("The Visitor"));
}

} // namespace tracing_exam_2022_1
