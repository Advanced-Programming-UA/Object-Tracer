#include "Person.h"
#include "utils/tracer.h"

namespace Vehicles {
using std::string;

Person::Person(std::string name) : m_name(std::move(name)) { MEMBER_TRACER; }

Person::~Person() { MEMBER_TRACER; }

string Person::get_name() const {
    MEMBER_TRACER;
    return m_name;
}
} // namespace Vehicles
