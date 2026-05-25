// ProjectForge C++ port — GPL v3
#include "org/projectforge/jcr/session_wrapper.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::jcr {
static struct session_wrapperModuleInit {
    session_wrapperModuleInit() { spdlog::debug("jcr: session_wrapper module initialized"); }
} _session_wrapperInit;
} // namespace
