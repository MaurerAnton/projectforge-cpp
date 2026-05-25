// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/JsonSerializer.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: JsonSerializer
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct JsonSerializerAutoRegister {
    JsonSerializerAutoRegister() {
        spdlog::debug("REST: Registering JsonSerializer routes");
        JsonSerializer::registerRoutes();
        spdlog::debug("REST: JsonSerializer routes registered");
    }
} _JsonSerializerAutoRegister;

} // namespace
