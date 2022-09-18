#pragma once
#ifndef RENTABLE_H
#define RENTABLE_H

#include "Person.h"

#include <memory>
#include <string>

/**
 * @file
 * Header for the Rentable class.
 * @author Thomas Avé
 */

namespace tracing_example_exam {

class Rentable
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
        void rent(Person& renter);

private:
        std::shared_ptr<Person> m_renter;
};

} // namespace tracing_example_exam

#endif // RENTABLE_H
