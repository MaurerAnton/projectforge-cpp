// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/task_object.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct task_objectModuleInit {
    task_objectModuleInit() { spdlog::debug("model: task_object module initialized"); }
} _task_objectInit;
} // namespace
