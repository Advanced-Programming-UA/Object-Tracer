#pragma once

#include "Vehicle.h"

namespace Vehicles {

/**
 * Abstract WaterVehicle class.
 */
class WaterVehicle : public Vehicle {
public:
    /// Default constructor.
    WaterVehicle();

    /// Copy constructor.
    WaterVehicle(const WaterVehicle& ori);

    /// Move constructor.
    WaterVehicle(WaterVehicle&& ori) noexcept;

    /// Copy assignment.
    WaterVehicle& operator=(const WaterVehicle& rhs);

    /// Move assignment.
    WaterVehicle& operator=(WaterVehicle&& rhs) noexcept;

    /// Destructor.
    ~WaterVehicle() override;

    /// Return identification info.
    void info() const override;

    /// Pure virtual method for motion.
    void move(double speed, std::vector<double> direction) override = 0;

    /// Start sinking, even if you are already sinking.
    void start_sinking();

    /// Stop sinking, even if you were not sinking in the first place.
    void stop_sinking();

private:
    bool m_sinking;
};

} // namespace Vehicles
