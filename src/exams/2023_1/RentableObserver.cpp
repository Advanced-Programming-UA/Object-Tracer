/**
 * @file
 * Implementation for the class RentableObserver.
 * @author Thomas Avé
 */

#include "RentableObserver.h"
#include "utils/tracer.h"

namespace tracing_exam_2023_1 {

RentableObserver::RentableObserver() { MEMBER_TRACER; }

RentableObserver::~RentableObserver() { MEMBER_TRACER; }

void RentableObserver::update(Rentable*, Event e) {
    MEMBER_TRACER;
    switch (e) {
        case Event::BuildingRented:
            LOG_TRACER("Observed a Building being rented");
            break;
        default:
            break;
    }
}

void RentableObserver::attach(Rentable* r) {
    MEMBER_TRACER;
    r->attach(shared_from_this(), Event::BuildingRented);
}

} // namespace tracing_exam_2023_1
