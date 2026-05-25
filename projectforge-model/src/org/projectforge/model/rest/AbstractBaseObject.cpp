// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/AbstractBaseObject.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct AbstractBaseObjectModuleInit {
    AbstractBaseObjectModuleInit() { spdlog::debug("model: AbstractBaseObject module initialized"); }
} _AbstractBaseObjectInit;
} // namespace
