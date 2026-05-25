// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/RestController.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: RestController
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct RestControllerAutoRegister {
    RestControllerAutoRegister() {
        spdlog::debug("REST: Registering RestController routes");
        RestController::registerRoutes();
        spdlog::debug("REST: RestController routes registered");
    }
} _RestControllerAutoRegister;

} // namespace
