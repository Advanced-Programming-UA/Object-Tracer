#pragma once
#ifndef HOUSE_H
#define HOUSE_H

#include <memory>

#include "BathRoom.h"
#include "Building.h"
#include "Kitchen.h"

/**
 * @file
 * Header for the House class.
 * @author Thomas Avé
 */

namespace tracing_example_exam {

class House : public Building
{
public:
        /// Constructor
        House(Person owner, unsigned int bedrooms);

        /// Destructor.
        virtual ~House();

        /// Copy Constructor
        House(const House& h);

        /// Move Constructor
        House(House&& h);

        /// Copy-assignment of a House:
        House& operator=(const House&);

        /// Move-assignment of a House:
        House& operator=(House&&);

        /// Returns the name of the Building
        virtual std::string getName() const override;

        /// Adds a House to the list of neighbours of the current House
        /// It does not take ownership of this neighbouring House
        virtual void addNeighbour(House* neighbour);

private:
        std::shared_ptr<const BathRoom> m_bathroom = std::make_shared<const BathRoom>();
        Kitchen m_kitchen;
};

} // namespace tracing_example_exam

#endif // HOUSE_H
