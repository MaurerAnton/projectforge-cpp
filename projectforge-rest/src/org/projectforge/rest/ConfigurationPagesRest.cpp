// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/ConfigurationPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: ConfigurationPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct ConfigurationPagesRestAutoRegister {
    ConfigurationPagesRestAutoRegister() {
        spdlog::debug("REST: Registering ConfigurationPagesRest routes");
        ConfigurationPagesRest::registerRoutes();
        spdlog::debug("REST: ConfigurationPagesRest routes registered");
    }
} _ConfigurationPagesRestAutoRegister;

} // namespace
