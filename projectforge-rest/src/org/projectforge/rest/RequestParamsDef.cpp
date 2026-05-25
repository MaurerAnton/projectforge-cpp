// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/RequestParamsDef.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: RequestParamsDef
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct RequestParamsDefAutoRegister {
    RequestParamsDefAutoRegister() {
        spdlog::debug("REST: Registering RequestParamsDef routes");
        RequestParamsDef::registerRoutes();
        spdlog::debug("REST: RequestParamsDef routes registered");
    }
} _RequestParamsDefAutoRegister;

} // namespace
