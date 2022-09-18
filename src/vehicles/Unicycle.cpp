#include "Unicycle.h"
#include "utils/tracer.h"

namespace Vehicles {
using std::string;

Unicycle::Unicycle() : m_wheel(), m_speed(0.0), m_direction(0.0) { MEMBER_TRACER; }

// Perform a deep copy of the engine and a shallow copy of the owner
Unicycle::Unicycle(Unicycle const& ori) : m_wheel(ori.m_wheel), m_speed(ori.m_speed), m_direction(ori.m_direction)
{
        MEMBER_TRACER;
}

// Perform a deep copy of the engine and a shallow copy of the owner
Unicycle::Unicycle(Unicycle&& ori) noexcept
    : m_wheel(std::move(ori.m_wheel)), m_speed(ori.m_speed), m_direction(ori.m_direction)
{
        MEMBER_TRACER;
}

// Copy constructor does what the synthesized constructor would do..
Unicycle& Unicycle::operator=(const Unicycle& rhs)
{
        MEMBER_TRACER;
        if (this != &rhs) {
                m_wheel = rhs.m_wheel;
                m_speed = rhs.m_speed;
                m_direction = rhs.m_direction;
        }
        return *this;
}

// Move constructor does what the synthesized constructor would do..
Unicycle& Unicycle::operator=(Unicycle&& rhs) noexcept
{
        MEMBER_TRACER;
        if (this != &rhs) {
                m_wheel = std::move(rhs.m_wheel);
                m_speed = rhs.m_speed;
                m_direction = rhs.m_direction;
        }
        return *this;
}

// Nothing to do here..
Unicycle::~Unicycle() { MEMBER_TRACER; }

void Unicycle::accelerate(double speed)
{
        MEMBER_TRACER;
        m_speed = speed;
}

void Unicycle::brake(double speed)
{
        MEMBER_TRACER;
        m_speed = speed;
}

void Unicycle::turn(double degrees)
{
        MEMBER_TRACER;
        if (m_speed > 0.0) {
                m_direction += degrees;
        }
}

} // namespace Vehicles
