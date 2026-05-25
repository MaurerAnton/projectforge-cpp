// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/rest_paths.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct rest_pathsModuleInit {
    rest_pathsModuleInit() { spdlog::debug("model: rest_paths module initialized"); }
} _rest_pathsInit;
} // namespace
