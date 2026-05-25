// ProjectForge C++ port — GPL v3
#include "org/projectforge/jcr/JcrNode.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::jcr {
static struct JcrNodeModuleInit {
    JcrNodeModuleInit() { spdlog::debug("jcr: JcrNode module initialized"); }
} _JcrNodeInit;
} // namespace
