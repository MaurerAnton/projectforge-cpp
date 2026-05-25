// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/abstract_base_object.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct abstract_base_objectModuleInit {
    abstract_base_objectModuleInit() { spdlog::debug("model: abstract_base_object module initialized"); }
} _abstract_base_objectInit;
} // namespace
