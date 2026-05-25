// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/Cost2Object.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct Cost2ObjectModuleInit {
    Cost2ObjectModuleInit() { spdlog::debug("model: Cost2Object module initialized"); }
} _Cost2ObjectInit;
} // namespace
