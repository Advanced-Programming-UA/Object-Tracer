#include "Body.h"
#include "utils/tracer.h"
#include <iostream>

namespace Vehicles {
using namespace std;

Body::Body(std::string color) : m_color(std::move(color)) { MEMBER_TRACER; }

Body::Body(Body const& ori) : m_color(ori.m_color) { MEMBER_TRACER; }

Body::Body(Body&& ori) noexcept : m_color(std::move(ori.m_color)) { MEMBER_TRACER; }

Body& Body::operator=(Body const& rhs)
{
        MEMBER_TRACER;
        if (this != &rhs) {
                m_color = rhs.m_color;
        }
        return *this;
}

Body& Body::operator=(Body&& rhs) noexcept
{
        MEMBER_TRACER;
        if (this != &rhs) {
                m_color = std::move(rhs.m_color);
                rhs.m_color = nullptr;
        }
        return *this;
}

Body::~Body() { MEMBER_TRACER; }

Body Body::operator+(const Body& b)
{
        MEMBER_TRACER;
        return Body(m_color + b.m_color);
}
} // namespace Vehicles
