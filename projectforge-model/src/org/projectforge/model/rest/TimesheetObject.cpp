// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/TimesheetObject.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct TimesheetObjectModuleInit {
    TimesheetObjectModuleInit() { spdlog::debug("model: TimesheetObject module initialized"); }
} _TimesheetObjectInit;
} // namespace
