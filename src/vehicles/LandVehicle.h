#pragma once

#include "Vehicle.h"

namespace Vehicles {
/**
 * A LandVehicle drives on land.
 */
class LandVehicle : public Vehicle {
public:
    /// default constructor.
    LandVehicle();

    /// Copy constructor.
    LandVehicle(const LandVehicle& ori);

    /// Move constructor.
    LandVehicle(LandVehicle&& ori) noexcept;

    /// Copy assignment.
    LandVehicle& operator=(const LandVehicle& rhs);

    /// Move assignment.
    LandVehicle& operator=(LandVehicle&& rhs) noexcept;

    /// Destructor.
    ~LandVehicle() override;

    /// Return identification info.
    void info() const override;

    /// Pure virtual function: motion for the LandVehicle.
    void move(double speed, std::vector<double> direction) override = 0;
};

} // namespace Vehicles
