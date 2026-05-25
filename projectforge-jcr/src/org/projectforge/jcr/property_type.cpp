// ProjectForge C++ port — GPL v3
#include "org/projectforge/jcr/property_type.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::jcr {
static struct property_typeModuleInit {
    property_typeModuleInit() { spdlog::debug("jcr: property_type module initialized"); }
} _property_typeInit;
} // namespace
