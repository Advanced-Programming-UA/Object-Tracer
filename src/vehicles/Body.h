#pragma once

#include "PassengerRoadVehicle.h"
#include <string>
#include <utility>

namespace Vehicles {

class Body
{
public:
        /// Constructor.
        explicit Body(std::string color = "blue");

        /// Copy constructor
        Body(Body const& ori);

        /// Move constructor
        Body(Body&& ori) noexcept;

        /// Copy assingment
        Body& operator=(Body const& rhs);

        /// Move assingment
        Body& operator=(Body&& rhs) noexcept;

        /// Destructor
        ~Body();

        /// Weird operation
        Body operator+(const Body& b);

private:
        std::string m_color;
};

} // namespace Vehicles
