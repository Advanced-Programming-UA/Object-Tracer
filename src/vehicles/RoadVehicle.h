#pragma once

#include "LandVehicle.h"
#include <vector>

namespace Vehicles {

/**
 * A RoadVehicle is any kind of vehicle that moves on the road.
 */
class RoadVehicle : public LandVehicle {
public:
    /// Default constructor.
    RoadVehicle();

    /// Copy constructor.
    RoadVehicle(const RoadVehicle& ori);

    /// Move constructor.
    RoadVehicle(RoadVehicle&& ori) noexcept;

    /// Copy assignment operator.
    RoadVehicle& operator=(const RoadVehicle& rhs);

    /// Move assignment operator.
    RoadVehicle& operator=(RoadVehicle&& rhs) noexcept;

    /// Destructor.
    ~RoadVehicle() override;

    /// Return identification info.
    void info() const override;

    /// Motion of the vehicle.
    void move(double speed, std::vector<double> direction) override;
};

} // namespace Vehicles
