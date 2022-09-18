#include "utils/FunctionTracer.h"
#include "utils/TracerOutput.h"

using namespace Utils;

FunctionTracer::FunctionTracer(const std::string& function_name) : m_function_name(function_name) {
    TracerOutput::getInstance().log("---> function body: " + m_function_name);
    TracerOutput::getInstance().increase_indent();
}

FunctionTracer::~FunctionTracer() {
    TracerOutput::getInstance().decrease_indent();
    TracerOutput::getInstance().log("<--- function body: " + m_function_name);
}
