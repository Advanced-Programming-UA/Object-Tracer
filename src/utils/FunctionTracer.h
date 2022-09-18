#pragma once

#include "utils/TracerOutput.h"
#include <string>

/// Macro to take advantage of PRETTY_FUNCTION over plain FUNCTION with gcc.
#if defined(__GNUC__)
#define FUNCTION_NAME __PRETTY_FUNCTION__
#else
#define FUNCTION_NAME __FUNCTION__
#endif

/// Macro for tracking function scope.
#define FUNCTION_TRACER Utils::FunctionTracer macro_defined_function_tracer##__LINE__(FUNCTION_NAME)

namespace Utils {
/**
 * Class whose constructor/destructor pair are used to mark entering
 * and leaving a function body block.
 * You do this by defining an automatic variable of CodeTracker type
 * at the beginning of the body. The constructor triggers an appropriate
 * message.The destructor for the variable gets called when leaving the
 * function body and triggers the appropriate message.
 * The messages are logged through the TrackerOutput.
 */
class FunctionTracer
{
public:
        /// Constructor inserts message in TrackerOutput about entering a function body.
        explicit FunctionTracer(const std::string& function_name);

        /// No copy constructor.
        FunctionTracer(const FunctionTracer&) = delete;

        /// No assignment.
        FunctionTracer& operator=(const FunctionTracer&) = delete;

        /// Destructor inserts message in TracketOutput about leaving funvtion body.
        ~FunctionTracer();

private:
        std::string const m_function_name;
};

} // Utils
