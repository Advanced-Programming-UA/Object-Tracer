/**
 * @file
 * Implementation for the class RoadObserver.
 * @author Thomas Avé
 */

#include "RoadObserver.h"
#include "utils/tracer.h"

namespace tracing_exam_2023_1 {

RoadObserver::RoadObserver() { MEMBER_TRACER; }

RoadObserver::~RoadObserver() { MEMBER_TRACER; }

void RoadObserver::update(Road*, Event e) {
    MEMBER_TRACER;
    switch (e) {
        case Event::BuildingAdded:
            LOG_TRACER("Observed a building being added");
            break;
        case Event::BuildingRemoved:
            LOG_TRACER("Observed a building being removed");
        default:
            break;
    }
}

void RoadObserver::attach(Road* r) {
    MEMBER_TRACER;
    r->attach(shared_from_this(), Event::BuildingAdded);
}

} // namespace tracing_exam_2023_1
