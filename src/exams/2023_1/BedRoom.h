#pragma once
#ifndef BED_ROOM_H
#define BED_ROOM_H

#include <memory>
#include <vector>

#include "Room.h"

/**
 * @file
 * Header for the BedRoom class.
 * @author Thomas Avé
 */

namespace tracing_exam_2023_1 {

class BedRoom : public Room
{
public:
        /// Constructor
        BedRoom();

        /// Copy Constructor
        BedRoom(const BedRoom& p);

        /// Move Constructor
        BedRoom(BedRoom&& p);

        /// Destructor.
        virtual ~BedRoom();

        /// Copy-assignment of a BedRoom:
        BedRoom& operator=(const BedRoom&);

        /// Move-assignment of a BedRoom:
        BedRoom& operator=(BedRoom&&);

        /// Return room information.
        virtual void info() const override;
};

} // namespace tracing_exam_2023_1

#endif // BED_ROOM_H
