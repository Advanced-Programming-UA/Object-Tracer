#pragma once

#include "RoadVehicle.h"

namespace Vehicles {

/**
 * A PassengerRoadVehicle transports one or more passengers.
 */
class PassengerRoadVehicle : public RoadVehicle {
public:
    /// Parametrized constructor, initializes number of seats.
    explicit PassengerRoadVehicle(int numSeats);

    /// Copy constructor.
    PassengerRoadVehicle(PassengerRoadVehicle const& ori);

    /// Move constructor.
    PassengerRoadVehicle(PassengerRoadVehicle&& ori) noexcept;

    /// Copy assignment.
    PassengerRoadVehicle& operator=(PassengerRoadVehicle const& rhs);

    /// Move assignment.
    PassengerRoadVehicle& operator=(PassengerRoadVehicle&& rhs) noexcept;

    /// Destructor.
    ~PassengerRoadVehicle() override;

    /// Take an additional passenger on board, if possible.
    bool add_passenger();

    /// Remove a passenger, if possible.
    bool remove_passenger();

    /// Return the number of seats on the vehicle.
    int get_capacity() const;

    /// Return the number of seats still free.
    int get_free() const;

    /// Return identification info.
    void info() const override;

private:
    int m_capacity;
    int m_free;
};

} // namespace Vehicles
