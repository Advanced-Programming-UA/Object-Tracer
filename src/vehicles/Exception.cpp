#include "Exception.h"
#include "utils/tracer.h"

namespace Vehicles {

using namespace std;

Exception::Exception(std::string m) : m_message(std::move(m)) { MEMBER_TRACER; }

Exception::Exception(const Exception& e) : m_message(e.m_message) { MEMBER_TRACER; }

Exception::Exception(Exception&& e) noexcept : m_message(std::move(e.m_message)) { MEMBER_TRACER; }

const char* Exception::what() const noexcept
{
        MEMBER_TRACER;
        return m_message.c_str();
}

void Exception::info() const { MEMBER_TRACER; }

MotionException::MotionException(std::string m) : Exception(std::move(m)) { MEMBER_TRACER; }

void MotionException::info() const { MEMBER_TRACER; }

LoadingException::LoadingException(std::string m) : Exception(std::move(m)) { MEMBER_TRACER; }

void LoadingException::info() const { MEMBER_TRACER; }

SailingException::SailingException(std::string m) : MotionException(std::move(m)) { MEMBER_TRACER; }

void SailingException::info() const { MEMBER_TRACER; }

} // namespace Vehicles
