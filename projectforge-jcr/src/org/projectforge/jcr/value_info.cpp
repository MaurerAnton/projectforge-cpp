// ProjectForge C++ port — GPL v3
#include "org/projectforge/jcr/value_info.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::jcr {
static struct value_infoModuleInit {
    value_infoModuleInit() { spdlog::debug("jcr: value_info module initialized"); }
} _value_infoInit;
} // namespace
