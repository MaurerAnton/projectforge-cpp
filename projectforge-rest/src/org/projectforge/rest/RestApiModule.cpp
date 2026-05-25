// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/RestApiModule.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: RestApiModule
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct RestApiModuleAutoRegister {
    RestApiModuleAutoRegister() {
        spdlog::debug("REST: Registering RestApiModule routes");
        RestApiModule::registerRoutes();
        spdlog::debug("REST: RestApiModule routes registered");
    }
} _RestApiModuleAutoRegister;

} // namespace
