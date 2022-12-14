#pragma once

#include "PassengerRoadVehicle.h"
#include <string>

namespace Vehicles {

/**
 * Represents a simple Bicycle.
 */
class Bicycle : public PassengerRoadVehicle {
public:
    /// Default constructor.
    Bicycle();

    /// Parametrized contructor, initialize model and color.
    Bicycle(std::string model, std::string color);

    /// Copy constructor.
    Bicycle(const Bicycle& ori);

    /// Move constructor.
    Bicycle(Bicycle&& ori) noexcept;

    /// Copy assignment.
    Bicycle& operator=(const Bicycle& rhs);

    /// Move assignment.
    Bicycle& operator=(Bicycle&& rhs) noexcept;

    /// Destructor.
    ~Bicycle() override;

    /// Return the model of the bike.
    std::string getModel() const;

    /// Return the color of the bike.
    std::string getColor() const;

    /// Set the model of the bike.
    void setModel(std::string model);

    /// Set the color of the bike.
    void setColor(std::string color);

    /// Display info on model and color of the bike.
    void info() const override;

private:
    std::string m_model;
    std::string m_color;
};

} // namespace Vehicles
