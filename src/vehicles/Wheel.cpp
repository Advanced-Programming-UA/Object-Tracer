#include "Wheel.h"
#include "utils/tracer.h"

namespace Vehicles {
using std::string;

Wheel::Wheel() : m_speed(0.0), m_rotating(false) { MEMBER_TRACER; }

Wheel::Wheel(const Wheel& ori) : m_speed(ori.m_speed), m_rotating(ori.m_rotating) { MEMBER_TRACER; }

Wheel::Wheel(Wheel&& ori) noexcept : m_speed(ori.m_speed), m_rotating(ori.m_rotating) { MEMBER_TRACER; }

Wheel& Wheel::operator=(Wheel const& rhs)
{
        MEMBER_TRACER;
        if (this != &rhs) {
                m_speed = rhs.m_speed;
                m_rotating = rhs.m_rotating;
        }
        return *this;
}

Wheel& Wheel::operator=(Wheel&& rhs) noexcept
{
        MEMBER_TRACER;
        if (this != &rhs) {
                m_speed = rhs.m_speed;
                m_rotating = rhs.m_rotating;
        }
        return *this;
}

Wheel::~Wheel() { MEMBER_TRACER; }

void Wheel::start()
{
        MEMBER_TRACER;
        if (!m_rotating) {
                m_rotating = true;
        }
}

void Wheel::stop()
{
        MEMBER_TRACER;
        if (m_rotating) {
                m_rotating = false;
        }
}

bool Wheel::is_rotating() const
{
        MEMBER_TRACER;
        return m_rotating;
}

} // namespace Vehicles
