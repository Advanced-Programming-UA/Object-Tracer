/**
 * @file
 * Implementation for the class Rentable.
 * @author Thomas Avé
 */

#include "Rentable.h"
#include "utils/tracer.h"

#include <memory>
#include <stdexcept>

namespace tracing_exam_2022_2 {

Rentable::Rentable() : m_renter() { MEMBER_TRACER; }

Rentable::~Rentable() { MEMBER_TRACER; }

Rentable::Rentable(const Rentable& other) : m_renter(other.m_renter) { MEMBER_TRACER; }

Rentable::Rentable(Rentable&& other) : m_renter(std::move(other.m_renter)) { MEMBER_TRACER; }

Rentable& Rentable::operator=(const Rentable& other)
{
        MEMBER_TRACER;
        if (this != &other) {
                m_renter = other.m_renter;
        }
        return *this;
}

Rentable& Rentable::operator=(Rentable&& other)
{
        MEMBER_TRACER;
        if (this != &other) {
                m_renter = std::move(other.m_renter);
        }
        return *this;
}

void Rentable::rent(const Person& renter)
{
        MEMBER_TRACER;
        if (m_renter) {
                throw std::runtime_error("This Rentable is already being rented!");
        } else {
                m_renter = std::make_shared<Person>(renter);
                notify(Event::BuildingRented);
        }
}

} // namespace tracing_exam_2022_2
