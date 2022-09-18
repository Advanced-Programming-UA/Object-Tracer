#pragma once
#ifndef KITCHEN_H
#define KITCHEN_H

#include <memory>
#include <vector>

#include "Room.h"

/**
 * @file
 * Header for the Kitchen class.
 * @author Thomas Avé
 */

namespace tracing_exam_2022_2 {

class Kitchen : public Room
{
public:
        /// Constructor
        Kitchen();

        /// Copy Constructor
        Kitchen(const Kitchen& p);

        /// Move Constructor
        Kitchen(Kitchen&& p);

        /// Destructor.
        virtual ~Kitchen();

        /// Copy-assignment of a Kitchen:
        Kitchen& operator=(const Kitchen&);

        /// Move-assignment of a Kitchen:
        Kitchen& operator=(Kitchen&&);

        /// Return room information.
        virtual void info() const override;
};

} // namespace tracing_exam_2022_2

#endif // KITCHEN_H
