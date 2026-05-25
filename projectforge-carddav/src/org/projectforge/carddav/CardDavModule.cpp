// ProjectForge C++ port — GPL v3
#include "org/projectforge/carddav/CardDavModule.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::carddav {
static struct CardDavModuleModuleInit {
    CardDavModuleModuleInit() { spdlog::debug("carddav: CardDavModule module initialized"); }
} _CardDavModuleInit;
} // namespace
