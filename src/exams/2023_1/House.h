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

namespace tracing_exam_2023_1 {

class House : public Building
{
public:
        /// Constructor
        House(Person& owner);

        /// Constructor
        House(Person&& owner, unsigned int bedrooms);

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

        /// Accept the Visitor to this House
        void welcome(Visitor& v) override;

private:
        std::unique_ptr<Kitchen> m_kitchen = std::make_unique<Kitchen>();
        BathRoom* m_bathroom;
};

} // namespace tracing_exam_2023_1

#endif // HOUSE_H
