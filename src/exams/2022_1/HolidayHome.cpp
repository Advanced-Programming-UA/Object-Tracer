/**
 * @file
 * Implementation for the class HolidayHome.
 * @author Thomas Avé
 */

#include "HolidayHome.h"
#include "Visitor.h"
#include "utils/tracer.h"

namespace tracing_exam_2022_1 {

HolidayHome::HolidayHome(Person& owner, unsigned int bedrooms) : House(owner, bedrooms) { MEMBER_TRACER; }

HolidayHome::~HolidayHome() { MEMBER_TRACER; }

HolidayHome::HolidayHome(const HolidayHome& h) : House(h), Rentable(h) { MEMBER_TRACER; }

HolidayHome::HolidayHome(HolidayHome&& h) : House(std::move(h)), Rentable(std::move(h)) { MEMBER_TRACER; }

HolidayHome& HolidayHome::operator=(const HolidayHome& other)
{
        MEMBER_TRACER;
        if (this != &other) {
                House::operator=(other);
                Rentable::operator=(other);
        }
        return *this;
}

HolidayHome& HolidayHome::operator=(HolidayHome&& other)
{
        MEMBER_TRACER;
        if (this != &other) {
                House::operator=(std::move(other));
                Rentable::operator=(std::move(other));
        }
        return *this;
}

std::string HolidayHome::getName() const
{
        MEMBER_TRACER;
        return "HolidayHome";
}

void HolidayHome::addNeighbour(HolidayHome* neighbour)
{
        MEMBER_TRACER;
        if (neighbour != this) {
                m_neighbours.emplace_back(neighbour);
        }
}

void HolidayHome::welcome(Visitor& v) {
        MEMBER_TRACER;
        v.visit(this);
}

} // namespace tracing_exam_2022_1
