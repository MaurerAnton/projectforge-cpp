// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/cost2_object.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct cost2_objectModuleInit {
    cost2_objectModuleInit() { spdlog::debug("model: cost2_object module initialized"); }
} _cost2_objectInit;
} // namespace
