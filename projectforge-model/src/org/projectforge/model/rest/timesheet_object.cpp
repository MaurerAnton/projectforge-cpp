// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/timesheet_object.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct timesheet_objectModuleInit {
    timesheet_objectModuleInit() { spdlog::debug("model: timesheet_object module initialized"); }
} _timesheet_objectInit;
} // namespace
