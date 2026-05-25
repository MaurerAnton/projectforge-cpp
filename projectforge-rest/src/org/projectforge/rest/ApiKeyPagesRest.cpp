// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/ApiKeyPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: ApiKeyPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct ApiKeyPagesRestAutoRegister {
    ApiKeyPagesRestAutoRegister() {
        spdlog::debug("REST: Registering ApiKeyPagesRest routes");
        ApiKeyPagesRest::registerRoutes();
        spdlog::debug("REST: ApiKeyPagesRest routes registered");
    }
} _ApiKeyPagesRestAutoRegister;

} // namespace
