#include "utils/BlockTracer.h"

using namespace Utils;

BlockTracer::BlockTracer(const std::string& msg) : m_msg(msg) {
    TracerOutput::getInstance().log("---> code block: " + m_msg);
    TracerOutput::getInstance().increase_indent();
}

BlockTracer::~BlockTracer() {
    TracerOutput::getInstance().decrease_indent();
    TracerOutput::getInstance().log("<---  code block: " + m_msg);
}
