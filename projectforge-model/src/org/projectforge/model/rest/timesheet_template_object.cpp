// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/timesheet_template_object.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct timesheet_template_objectModuleInit {
    timesheet_template_objectModuleInit() { spdlog::debug("model: timesheet_template_object module initialized"); }
} _timesheet_template_objectInit;
} // namespace
