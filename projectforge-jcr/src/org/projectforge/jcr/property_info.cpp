// ProjectForge C++ port — GPL v3
#include "org/projectforge/jcr/property_info.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::jcr {
static struct property_infoModuleInit {
    property_infoModuleInit() { spdlog::debug("jcr: property_info module initialized"); }
} _property_infoInit;
} // namespace
