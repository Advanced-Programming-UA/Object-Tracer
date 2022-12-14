#pragma once

#include "WaterVehicle.h"
#include <string>

namespace Vehicles {
/**
 * A simple SailBoat class.
 */
class SailBoat : public WaterVehicle {
public:
    /// Parametrized constructor initializes the name of the boat.
    explicit SailBoat(std::string name);

    /// Copy constructor.
    SailBoat(const SailBoat& ori);

    /// Move constructor.
    SailBoat(SailBoat&& ori) noexcept;

    /// Copy assignment.
    SailBoat& operator=(const SailBoat& rhs);

    /// Move assignment.
    SailBoat& operator=(SailBoat&& rhs) noexcept;

    /// Destructor.
    ~SailBoat() override;

    /// Return identification info.
    void info() const override;

    /// Sailboat motion.
    void move(double speed, std::vector<double> direction) override;

private:
    std::string m_name;
    bool m_sails_up;
};

} // namespace Vehicles
