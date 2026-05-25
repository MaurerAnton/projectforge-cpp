// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/calendar_object.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct calendar_objectModuleInit {
    calendar_objectModuleInit() { spdlog::debug("model: calendar_object module initialized"); }
} _calendar_objectInit;
} // namespace
