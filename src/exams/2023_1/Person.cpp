/**
 * @file
 * Implementation for the class Person.
 * @author Thomas Avé
 */

#include "Person.h"
#include "utils/tracer.h"

namespace tracing_exam_2023_1 {

Person::Person(std::string name) : m_name(name) { MEMBER_TRACER; }

Person::Person(const Person& p) : m_name(p.m_name) { MEMBER_TRACER; }

Person::Person(Person&& p) : m_name(std::move(p.m_name)) { MEMBER_TRACER; }

Person::~Person() { MEMBER_TRACER; }

std::string Person::getName() const
{
        MEMBER_TRACER;
        return m_name;
}

Person& Person::operator=(const Person& other)
{
        MEMBER_TRACER;
        if (this != &other) {
                m_name = other.m_name;
        }
        return *this;
}

Person& Person::operator=(Person&& other)
{
        MEMBER_TRACER;
        if (this != &other) {
                m_name = std::move(other.m_name);
        }
        return *this;
}

} // namespace tracing_exam_2023_1
