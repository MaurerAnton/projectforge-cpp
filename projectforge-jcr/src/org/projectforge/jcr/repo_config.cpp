// ProjectForge C++ port — GPL v3
#include "org/projectforge/jcr/repo_config.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::jcr {
static struct repo_configModuleInit {
    repo_configModuleInit() { spdlog::debug("jcr: repo_config module initialized"); }
} _repo_configInit;
} // namespace
