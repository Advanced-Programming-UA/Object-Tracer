#pragma once

#include <sstream>

/// Macro for manual log outputs
#define LOG_TRACER Utils::TracerOutput::getInstance().log
#define TRACER_OUTPUT_OFF Utils::TracerOutput::getInstance().set_output_off()
#define TRACER_OUTPUT_ON Utils::TracerOutput::getInstance().set_output_on()

namespace Utils {

class TracerOutput
{
public:
        /// Indicate whether current making output.
        bool is_output_on();

        /// Start making output (ok even output already started).
        void set_output_on();

        /// Stop making output (ok even if output already stopped).
        void set_output_off();

        /// Increase the indentation level.
        void increase_indent();

        /// Decrease the indentation level.
        void decrease_indent();

        /// Insert the message in the google log at given severity level.
        void log(const std::string& msg);

        /// Get the TracerOutput instance
        static TracerOutput& getInstance();

        /// Get the output of this TracerOutput instance
        friend std::ostream& operator<<(std::ostream&, const TracerOutput&);

        TracerOutput(TracerOutput const&) = delete;
        void operator=(TracerOutput const&) = delete;

private:
        TracerOutput() = default;

        bool m_make_output{true};
        unsigned int m_indent{0};
        std::ostringstream m_output;
};

} // Utils
