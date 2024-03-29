#pragma once
#ifndef BUILDING_H
#define BUILDING_H

#include <memory>
#include <vector>

#include "Person.h"
#include "Room.h"
#include "Subject.h"

/**
 * @file
 * Header for the Building class.
 * @author Thomas Avé
 */

namespace tracing_exam_2023_1 {
class Visitor;

class Building
{
public:
        /// Constructor
        Building(Person& owner);

        /// Copy Constructor
        Building(const Building& b);

        /// Move Constructor
        Building(Building&& b);

        /// Copy-assignment of a Building:
        Building& operator=(const Building&);

        /// Move-assignment of a Building:
        Building& operator=(Building&&);

        /// Destructor.
        virtual ~Building();

        /// Prints building information.
        virtual void info() const;

        /// Returns the name of the Building
        virtual std::string getName() const;

        /// Returns the Person who owns the building
        virtual const Person& getOwner() const;

        /// Adds a Building to the list of neighbours of the current building
        /// It does not take ownership of this neighbouring Building
        virtual void addNeighbour(Building* neighbour);

        /// Accept the Visitor to this Building
        virtual void welcome(Visitor& v);

protected:
        Person& m_owner;
        std::vector<Building*> m_neighbours;
        std::vector<std::unique_ptr<Room>> m_rooms;
};

} // namespace tracing_exam_2023_1

#endif // BUILDING_H
