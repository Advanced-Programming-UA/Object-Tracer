#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H

/**
 * @file
 * Header for the Subject class.
 * @author Thomas Avé
 */

#include "utils/tracer.h"
#include "Observer.h"
#include <map>
#include <vector>
#include <memory>

namespace tracing_exam_2022_2 {

    template <typename T>
    class Subject
    {
        public:
            Subject(): m_observers() {
                MEMBER_TRACER;
            }
            virtual ~Subject() {
                MEMBER_TRACER;
            }
            void attach (std::shared_ptr<Observer<T>> observer, Event e)
            {
                MEMBER_TRACER;
                m_observers[e].push_back(observer);
            }
            void notify (Event e)
            {
                MEMBER_TRACER;
                for (auto o: m_observers[e])
                    o->update(static_cast<T *>(this), e);
            }
        private:
            std::map<Event, std::vector<std::shared_ptr<Observer<T>>>> m_observers;
    };

} // namespace tracing_exam_2022_2

#endif // SUBJECT_H
