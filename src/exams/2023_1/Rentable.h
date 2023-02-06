#pragma once
#ifndef RENTABLE_H
#define RENTABLE_H

#include "Person.h"
#include "Subject.h"

#include <memory>
#include <string>

/**
 * @file
 * Header for the Rentable class.
 * @author Thomas Avé
 */

namespace tracing_exam_2023_1 {

class Rentable: public Subject<Rentable>
{
public:
        /// Constructor
        Rentable();

        /// Copy Constructor
        Rentable(const Rentable& r);

        /// Move Constructor
        Rentable(Rentable&& r);

        /// Destructor.
        virtual ~Rentable();

        /// Copy-assignment of a Rentable:
        Rentable& operator=(const Rentable&);

        /// Move-assignment of a Rentable:
        Rentable& operator=(Rentable&&);

        /// Rent this Rentable
        void rent(const Person& renter);

        /// Rent this Rentable
        void rent(Person&& renter);

private:
        std::shared_ptr<Person> m_renter;
};

} // namespace tracing_exam_2023_1

#endif // RENTABLE_H
