#pragma once
#ifndef ROAD_OBSERVER_H
#define ROAD_OBSERVER_H

/**
 * @file
 * Header for the RoadObserver class.
 * @author Thomas Avé
 */

#include "utils/tracer.h"
#include "Observer.h"
#include "Road.h"

namespace tracing_exam_2022_2 {

    class RoadObserver: public Observer<Road>, public std::enable_shared_from_this<RoadObserver>
    {
        public:
            RoadObserver();

            virtual ~RoadObserver();

            void update(Road*, Event) override;

            void attach(Road*) override;
    };

} // namespace tracing_exam_2022_2

#endif // ROAD_OBSERVER_H
