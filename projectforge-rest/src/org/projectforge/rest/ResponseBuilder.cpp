// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/ResponseBuilder.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: ResponseBuilder
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct ResponseBuilderAutoRegister {
    ResponseBuilderAutoRegister() {
        spdlog::debug("REST: Registering ResponseBuilder routes");
        ResponseBuilder::registerRoutes();
        spdlog::debug("REST: ResponseBuilder routes registered");
    }
} _ResponseBuilderAutoRegister;

} // namespace
