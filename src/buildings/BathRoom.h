#pragma once
#ifndef BATH_ROOM_H
#define BATH_ROOM_H

#include <memory>
#include <vector>

#include "Room.h"

/**
 * @file
 * Header for the BathRoom class.
 * @author Thomas Avé
 */

namespace tracing_example_exam {

class BathRoom : public Room
{
public:
        /// Constructor
        BathRoom();

        /// Copy Constructor
        BathRoom(const BathRoom& b);

        /// Move Constructor
        BathRoom(BathRoom&& b);

        /// Destructor.
        virtual ~BathRoom();

        /// Copy-assignment of a BathRoom:
        BathRoom& operator=(const BathRoom&);

        /// Move-assignment of a BathRoom:
        BathRoom& operator=(BathRoom&&);

        /// Return room information.
        virtual void info() const override;
};

} // namespace tracing_example_exam

#endif // BATH_ROOM_H
