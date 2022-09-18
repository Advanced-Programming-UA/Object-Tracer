#include "utils/TracerOutput.h"
#include <iostream>

using namespace std;

namespace Utils {

bool TracerOutput::is_output_on() { return m_make_output; }

void TracerOutput::set_output_on() { m_make_output = true; }

void TracerOutput::set_output_off() { m_make_output = false; }

void TracerOutput::increase_indent() { m_indent++; }

void TracerOutput::decrease_indent() { m_indent--; }

void TracerOutput::log(const string& msg)
{
        if (is_output_on()) {
                for (unsigned int i = 0; i < m_indent; ++i) {
                        m_output << "     ";
                }
                m_output << msg << std::endl;
        }
}

TracerOutput& TracerOutput::getInstance() {
    static TracerOutput instance;
    return instance;
}

ostream& operator<<(ostream& os, const TracerOutput& t)
{
    os << t.m_output.str();
    return os;
}

}
