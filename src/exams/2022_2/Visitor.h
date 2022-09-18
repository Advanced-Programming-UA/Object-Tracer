#pragma once
#ifndef VISITOR_H
#define VISITOR_H

#include "utils/tracer.h"

#include <memory>
#include <string>
#include <map>

/**
 * @file
 * Header for the Visitor class.
 * @author Thomas Avé
 */

namespace tracing_exam_2022_2 {

class HolidayHome;
class Visitor
{
public:
        /// Constructor
        Visitor();

        /// Destructor
        ~Visitor();

        /// Visit the provided object
        /// Make sure you provide the actual type T for each template instantiation
        /// For example:   ---> function body: void tracing_exam_2022_2::Visitor::visit(T*) [with T = tracing_exam_2022_2::Building]
        template<typename T>
        void visit(T* t) {
            MEMBER_TRACER;
            LOG_TRACER("Visiting a " + t->getName());
        }

};

template<>
void Visitor::visit(HolidayHome* h);

} // namespace tracing_exam_2022_2

#endif // VISITOR_H
