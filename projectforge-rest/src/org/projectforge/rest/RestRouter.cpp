// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/RestRouter.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: RestRouter
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct RestRouterAutoRegister {
    RestRouterAutoRegister() {
        spdlog::debug("REST: Registering RestRouter routes");
        RestRouter::registerRoutes();
        spdlog::debug("REST: RestRouter routes registered");
    }
} _RestRouterAutoRegister;

} // namespace
