// ProjectForge C++ port — GPL v3
#include "org/projectforge/jcr/JcrRepository.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::jcr {
static struct JcrRepositoryModuleInit {
    JcrRepositoryModuleInit() { spdlog::debug("jcr: JcrRepository module initialized"); }
} _JcrRepositoryInit;
} // namespace
