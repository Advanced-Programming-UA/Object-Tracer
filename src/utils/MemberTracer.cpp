#include "utils/MemberTracer.h"
#include <sstream>

using namespace std;
using namespace Utils;

MemberTracer::MemberTracer(const string& member_name, const void* object_this)
    : m_member_name(member_name), m_object_this(object_this) {
    std::ostringstream ss;
    ss << "---> member for object: " << m_object_this << " : " << m_member_name;
    TracerOutput::getInstance().log(ss.str());
    TracerOutput::getInstance().increase_indent();
}

MemberTracer::~MemberTracer() {
    TracerOutput::getInstance().decrease_indent();
    std::ostringstream ss;
    ss << "<--- member for object: " << m_object_this << " : " << m_member_name;
    TracerOutput::getInstance().log(ss.str());
}
