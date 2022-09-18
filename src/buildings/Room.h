#pragma once
#ifndef ROOM_H
#define ROOM_H

#include <memory>
#include <vector>

/**
 * @file
 * Header for the Room class.
 * @author Thomas Avé
 */

namespace tracing_example_exam {

class Room
{
public:
        /// Constructor
        Room();

        /// Copy Constructor
        Room(const Room& p);

        /// Move Constructor
        Room(Room&& p);

        /// Destructor.
        virtual ~Room();

        /// Copy-assignment of a Room:
        Room& operator=(const Room&);

        /// Move-assignment of a Room:
        Room& operator=(Room&&);

        /// Return room information.
        virtual void info() const;
};

} // namespace tracing_example_exam

#endif // ROOM_H
