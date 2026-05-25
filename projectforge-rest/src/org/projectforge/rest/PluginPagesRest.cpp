// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/PluginPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: PluginPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct PluginPagesRestAutoRegister {
    PluginPagesRestAutoRegister() {
        spdlog::debug("REST: Registering PluginPagesRest routes");
        PluginPagesRest::registerRoutes();
        spdlog::debug("REST: PluginPagesRest routes registered");
    }
} _PluginPagesRestAutoRegister;

} // namespace
