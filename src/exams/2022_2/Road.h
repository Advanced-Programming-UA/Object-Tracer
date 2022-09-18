#pragma once
#ifndef ROAD_H
#define ROAD_H

#include "Building.h"
#include "Subject.h"
#include "Visitor.h"

#include <memory>
#include <string>
#include <map>

/**
 * @file
 * Header for the Road class.
 * @author Thomas Avé
 */

namespace tracing_exam_2022_2 {

class Road: public Subject<Road>
{
public:
        /// Constructor
        Road();

        /// Copy Constructor
        Road(const Road& r);

        /// Move Constructor
        Road(Road&& r);

        /// Destructor.
        virtual ~Road();

        /// Copy-assignment of a Road:
        Road& operator=(const Road&);

        /// Move-assignment of a Road:
        Road& operator=(Road&&);

        /// Add a Building to this Road at the given number
        void addBuilding(std::unique_ptr<Building> b, unsigned int number);

        /// Remove the Building with the given number from this Road
        void removeBuilding(unsigned int number);

        /// Retrieve the Building with the given number from this Road
        Building& getBuilding(unsigned int number);

        /// Returns whether or not this Road contains a Building at the given number
        bool hasBuilding(int number) const;

        /// Welcome the Visitor to all Buildings in this Road
        void welcome(Visitor& v);

private:
        std::map<unsigned int, std::unique_ptr<Building>> m_buildings;
};

} // namespace tracing_exam_2022_2

#endif // ROAD_H
