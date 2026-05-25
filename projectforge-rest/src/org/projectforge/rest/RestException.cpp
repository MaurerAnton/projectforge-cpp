// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/RestException.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: RestException
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct RestExceptionAutoRegister {
    RestExceptionAutoRegister() {
        spdlog::debug("REST: Registering RestException routes");
        RestException::registerRoutes();
        spdlog::debug("REST: RestException routes registered");
    }
} _RestExceptionAutoRegister;

} // namespace
