// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/user_object.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct user_objectModuleInit {
    user_objectModuleInit() { spdlog::debug("model: user_object module initialized"); }
} _user_objectInit;
} // namespace
