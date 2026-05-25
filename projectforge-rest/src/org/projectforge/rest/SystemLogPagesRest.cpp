// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/SystemLogPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: SystemLogPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct SystemLogPagesRestAutoRegister {
    SystemLogPagesRestAutoRegister() {
        spdlog::debug("REST: Registering SystemLogPagesRest routes");
        SystemLogPagesRest::registerRoutes();
        spdlog::debug("REST: SystemLogPagesRest routes registered");
    }
} _SystemLogPagesRestAutoRegister;

} // namespace
