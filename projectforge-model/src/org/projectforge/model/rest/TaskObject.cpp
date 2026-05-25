// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/TaskObject.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct TaskObjectModuleInit {
    TaskObjectModuleInit() { spdlog::debug("model: TaskObject module initialized"); }
} _TaskObjectInit;
} // namespace
