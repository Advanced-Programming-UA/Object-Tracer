#pragma once

#include <string>
#include <vector>

namespace Vehicles {

/**
 * This Vehicle interface class.
 */
class Vehicle
{
public:
        /// Destructor.
        virtual ~Vehicle() = default;

        /// Return vehicle information.
        virtual void info() const = 0;

        /// Motion of vehicle.
        virtual void move(double speed, std::vector<double> direction) = 0;
};

} // namespace Vehicles
