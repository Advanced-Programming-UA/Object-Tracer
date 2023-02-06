#pragma once
#ifndef RENTABLE_OBSERVER_H
#define RENTABLE_OBSERVER_H

/**
 * @file
 * Header for the RentableObserver class.
 * @author Thomas Avé
 */

#include "utils/tracer.h"
#include "Observer.h"
#include "Rentable.h"

namespace tracing_exam_2023_1 {

    class RentableObserver: public Observer<Rentable>, public std::enable_shared_from_this<RentableObserver>
    {
        public:
            RentableObserver();

            virtual ~RentableObserver();

            void update(Rentable*, Event) override;

            void attach(Rentable*) override;
    };

} // namespace tracing_exam_2023_1

#endif // RENTABLE_OBSERVER_H
