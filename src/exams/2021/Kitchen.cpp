/**
 * @file
 * Implementation for the class Kitchen.
 * @author Thomas Avé
 */

#include "Kitchen.h"
#include "utils/tracer.h"

namespace tracing_exam_2021 {

Kitchen::Kitchen() { MEMBER_TRACER; }

Kitchen::Kitchen(const Kitchen& k) : Room(k) { MEMBER_TRACER; }

Kitchen::Kitchen(Kitchen&& k) : Room(std::move(k)) { MEMBER_TRACER; }

Kitchen::~Kitchen() { MEMBER_TRACER; }

Kitchen& Kitchen::operator=(const Kitchen& other) {
    MEMBER_TRACER;
    if (this != &other) {
        Room::operator=(other);
    }
    return *this;
}

Kitchen& Kitchen::operator=(Kitchen&& other) {
    MEMBER_TRACER;
    if (this != &other) {
        Room::operator=(std::move(other));
    }
    return *this;
}

void Kitchen::info() const {
    MEMBER_TRACER;
    LOG_TRACER("Kitchen");
}

} // namespace tracing_exam_2021
