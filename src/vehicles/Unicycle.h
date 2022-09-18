#pragma once
#include "Wheel.h"

namespace Vehicles {

/**
 * Unicycle interface.
 */
class Unicycle {
public:
    /// Default constructor does not initialize association with engine and owner.
    Unicycle();

    /// Copy constructor.
    Unicycle(const Unicycle& ori);

    /// Move constructor.
    Unicycle(Unicycle&& ori) noexcept;

    /// Copy assignment
    Unicycle& operator=(const Unicycle& rhs);

    /// Copy assignment
    Unicycle& operator=(Unicycle&& rhs) noexcept;

    /// Destructor.
    ~Unicycle();

    /// Accelerate up to given speed.
    void accelerate(double speed);

    /// Brake until given speed.
    void brake(double speed);

    // Turn with given number of degrees.
    void turn(double degrees);

private:
    Wheel m_wheel;
    double m_speed;
    double m_direction;
};

} // namespace Vehicles
