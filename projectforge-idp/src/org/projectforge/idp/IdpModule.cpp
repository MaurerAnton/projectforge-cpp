// ProjectForge C++ port — GPL v3
#include "org/projectforge/idp/IdpModule.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::idp {
static struct IdpModuleModuleInit {
    IdpModuleModuleInit() { spdlog::debug("idp: IdpModule module initialized"); }
} _IdpModuleInit;
} // namespace
