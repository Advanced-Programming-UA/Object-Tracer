#pragma once
#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @file
 * Header for the Observer class.
 * @author Thomas Avé
 */

#include "utils/tracer.h"

namespace tracing_exam_2023_1 {

    enum Event {
        BuildingAdded,
        BuildingRemoved,
        BuildingRented,
    };

    template <typename T>
    class Observer
    {
        public:
            Observer() {
                MEMBER_TRACER;
            }
            virtual ~Observer() {
                MEMBER_TRACER;
            }
            virtual void update(T *subject, Event e) = 0;

            virtual void attach(T *subject) = 0;
    };

} // namespace tracing_exam_2023_1

#endif // OBSERVER_H
