/**
 * @file
 * Implementation for the class BedRoom.
 * @author Thomas Avé
 */

#include "BedRoom.h"
#include "utils/tracer.h"

namespace tracing_exam_2021 {

BedRoom::BedRoom() { MEMBER_TRACER; }

BedRoom::BedRoom(const BedRoom& b) : Room(b) { MEMBER_TRACER; }

BedRoom::BedRoom(BedRoom&& b) : Room(std::move(b)) { MEMBER_TRACER; }

BedRoom::~BedRoom() { MEMBER_TRACER; }

BedRoom& BedRoom::operator=(const BedRoom& other) {
    MEMBER_TRACER;
    if (this != &other) {
        Room::operator=(other);
    }
    return *this;
}

BedRoom& BedRoom::operator=(BedRoom&& other) {
    MEMBER_TRACER;
    if (this != &other) {
        Room::operator=(std::move(other));
    }
    return *this;
}

void BedRoom::info() const {
    MEMBER_TRACER;
    LOG_TRACER("BedRoom");
}

} // namespace tracing_exam_2021
