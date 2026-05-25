// ProjectForge C++ port — GPL v3
#include "org/projectforge/jcr/ContentRepositoryManager.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::jcr {
static struct ContentRepositoryManagerModuleInit {
    ContentRepositoryManagerModuleInit() { spdlog::debug("jcr: ContentRepositoryManager module initialized"); }
} _ContentRepositoryManagerInit;
} // namespace
