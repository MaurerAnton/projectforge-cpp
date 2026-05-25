// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/UserObject.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct UserObjectModuleInit {
    UserObjectModuleInit() { spdlog::debug("model: UserObject module initialized"); }
} _UserObjectInit;
} // namespace
