/**
 * @file
 * Implementation for the class BathRoom.
 * @author Thomas Avé
 */

#include "BathRoom.h"
#include "utils/tracer.h"

namespace tracing_example_exam {

BathRoom::BathRoom() { MEMBER_TRACER; }

BathRoom::BathRoom(const BathRoom& b) : Room(b) { MEMBER_TRACER; }

BathRoom::BathRoom(BathRoom&& b) : Room(std::move(b)) { MEMBER_TRACER; }

BathRoom::~BathRoom() { MEMBER_TRACER; }

BathRoom& BathRoom::operator=(const BathRoom& other) {
    MEMBER_TRACER;
    if (this != &other) {
        Room::operator=(other);
    }
    return *this;
}

BathRoom& BathRoom::operator=(BathRoom&& other) {
    MEMBER_TRACER;
    if (this != &other) {
        Room::operator=(std::move(other));
    }
    return *this;
}

void BathRoom::info() const {
    MEMBER_TRACER;
    LOG_TRACER("BathRoom");
}

} // namespace tracing_example_exam
