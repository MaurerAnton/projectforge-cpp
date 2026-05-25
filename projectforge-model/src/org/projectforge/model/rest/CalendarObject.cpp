// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/CalendarObject.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct CalendarObjectModuleInit {
    CalendarObjectModuleInit() { spdlog::debug("model: CalendarObject module initialized"); }
} _CalendarObjectInit;
} // namespace
