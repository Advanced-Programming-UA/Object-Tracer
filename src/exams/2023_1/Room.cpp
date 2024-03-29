/**
 * @file
 * Implementation for the class Room.
 * @author Thomas Avé
 */

#include "Room.h"
#include "utils/tracer.h"

namespace tracing_exam_2023_1 {

Room::Room() { MEMBER_TRACER; }

Room::Room(const Room&) { MEMBER_TRACER; }

Room::Room(Room&&) { MEMBER_TRACER; }

Room::~Room() { MEMBER_TRACER; }

Room& Room::operator=(const Room&)
{
        MEMBER_TRACER;
        return *this;
}

Room& Room::operator=(Room&&)
{
        MEMBER_TRACER;
        return *this;
}

void Room::info() const
{
        MEMBER_TRACER;
        LOG_TRACER("Generic Room");
}

} // namespace tracing_exam_2023_1
