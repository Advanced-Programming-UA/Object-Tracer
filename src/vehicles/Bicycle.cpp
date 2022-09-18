#include "Bicycle.h"
#include "utils/tracer.h"

namespace Vehicles {

using namespace std;

Bicycle::Bicycle() : PassengerRoadVehicle(2), m_model("Unknown model"), m_color("Unknown color") { MEMBER_TRACER; }

Bicycle::Bicycle(std::string model, std::string color)
    : PassengerRoadVehicle(2), m_model(std::move(model)), m_color(std::move(color)) {
    MEMBER_TRACER;
}

Bicycle::Bicycle(const Bicycle& ori) : PassengerRoadVehicle(ori), m_model(ori.m_model), m_color(ori.m_color) {
    MEMBER_TRACER;
}

Bicycle::Bicycle(Bicycle&& ori) noexcept
    : PassengerRoadVehicle(std::move(ori)), m_model(std::move(ori.m_model)), m_color(std::move(ori.m_color)) {
    MEMBER_TRACER;
}

Bicycle& Bicycle::operator=(const Bicycle& rhs) {
    MEMBER_TRACER;
    if (this != &rhs) {
        PassengerRoadVehicle::operator=(rhs);
        this->m_model = rhs.m_model;
        this->m_color = rhs.m_color;
    }
    return *this;
}

Bicycle& Bicycle::operator=(Bicycle&& rhs) noexcept {
    MEMBER_TRACER;
    if (this != &rhs) {
        PassengerRoadVehicle::operator=(std::move(rhs));
        m_model = std::move(rhs.m_model);
        m_color = std::move(rhs.m_color);

        // Leave the argument in an indeterminate state.
        rhs.m_model = "";
        rhs.m_color = "";
    }
    return *this;
}

Bicycle::~Bicycle() { MEMBER_TRACER; }

string Bicycle::getModel() const {
    MEMBER_TRACER;
    return m_model;
}

string Bicycle::getColor() const {
    MEMBER_TRACER;
    return m_color;
}

void Bicycle::setModel(string model) {
    MEMBER_TRACER;
    m_model = std::move(model);
}

void Bicycle::setColor(string color) {
    MEMBER_TRACER;
    m_color = std::move(color);
}

void Bicycle::info() const {
    MEMBER_TRACER;
    const string s = {"I'm a bicycle: model = " + m_model + ", color = " + m_color};
    LOG_TRACER(s);
}

} // namespace Vehicles
