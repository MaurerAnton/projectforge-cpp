// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/RestAuth.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: RestAuth
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct RestAuthAutoRegister {
    RestAuthAutoRegister() {
        spdlog::debug("REST: Registering RestAuth routes");
        RestAuth::registerRoutes();
        spdlog::debug("REST: RestAuth routes registered");
    }
} _RestAuthAutoRegister;

} // namespace
