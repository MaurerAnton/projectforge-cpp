// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/RestPaths.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct RestPathsModuleInit {
    RestPathsModuleInit() { spdlog::debug("model: RestPaths module initialized"); }
} _RestPathsInit;
} // namespace
