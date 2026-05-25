// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/CompleteRestApi.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: CompleteRestApi
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct CompleteRestApiAutoRegister {
    CompleteRestApiAutoRegister() {
        spdlog::debug("REST: Registering CompleteRestApi routes");
        CompleteRestApi::registerRoutes();
        spdlog::debug("REST: CompleteRestApi routes registered");
    }
} _CompleteRestApiAutoRegister;

} // namespace
