#pragma once
#ifndef HOLIDAY_HOME_H
#define HOLIDAY_HOME_H

#include "House.h"
#include "Rentable.h"

/**
 * @file
 * Header for the HolidayHome class.
 * @author Thomas Avé
 */

namespace tracing_example_exam {

class HolidayHome : public House, public Rentable
{
public:
        /// Constructor
        HolidayHome(Person& owner, unsigned int bedrooms);

        /// Copy Constructor
        HolidayHome(const HolidayHome& h);

        /// Move Constructor
        HolidayHome(HolidayHome&& h);

        /// Destructor.
        virtual ~HolidayHome();

        /// Copy-assignment of a HolidayHome:
        HolidayHome& operator=(const HolidayHome&);

        /// Move-assignment of a HolidayHome:
        HolidayHome& operator=(HolidayHome&&);

        /// Returns the name of the Building
        virtual std::string getName() const override;

        /// Adds a HolidayHome to the list of neighbours of the current House
        /// It does not take ownership of this neighbouring HolidayHome
        virtual void addNeighbour(HolidayHome* neighbour);
};

} // namespace tracing_example_exam

#endif // HOLIDAY_HOME_H
