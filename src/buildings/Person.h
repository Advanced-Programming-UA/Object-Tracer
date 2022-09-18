#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>

/**
 * @file
 * Header for the Person class.
 * @author Thomas Avé
 */

namespace tracing_example_exam {

class Person
{
public:
        /// Constructor
        Person(std::string name);

        /// Copy Constructor
        Person(const Person& p);

        /// Move Constructor
        Person(Person&& p);

        /// Copy-assignment of a Person:
        Person& operator=(const Person&);

        /// Move-assignment of a Person:
        Person& operator=(Person&&);

        /// Destructor.
        ~Person();

        /// Returns the name of the Person
        std::string getName() const;

private:
        std::string m_name;
};

} // namespace tracing_example_exam

#endif // PERSON_H
