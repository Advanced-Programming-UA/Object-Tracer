#include "Engine.h"
#include "utils/tracer.h"

namespace Vehicles {

Engine::Engine(double power) : m_power(power), m_running(false) { MEMBER_TRACER; }

Engine::Engine(Engine const& ori) : m_power(ori.m_power), m_running(ori.m_running) { MEMBER_TRACER; }

Engine::Engine(Engine&& ori) noexcept : m_power(ori.m_power), m_running(ori.m_running) { MEMBER_TRACER; }

Engine& Engine::operator=(const Engine& rhs)
{
        MEMBER_TRACER;
        if (this != &rhs) {
                m_power = rhs.m_power;
                m_running = rhs.m_running;
        }
        return *this;
}

Engine& Engine::operator=(Engine&& rhs) noexcept
{
        MEMBER_TRACER;
        if (this != &rhs) {
                m_power = rhs.m_power;
                m_running = rhs.m_running;

                // Leave the argument in an indeterminate state.
                rhs.m_power = 0.0;
                rhs.m_running = false;
        }
        return *this;
}

Engine::~Engine() { MEMBER_TRACER; }

void Engine::start()
{
        MEMBER_TRACER;
        if (!m_running) {
                m_running = true;
        }
}

void Engine::stop()
{
        MEMBER_TRACER;
        if (m_running) {
                m_running = false;
        }
}

bool Engine::is_running() const
{
        MEMBER_TRACER;
        return m_running;
}

} // namespace Vehicles
