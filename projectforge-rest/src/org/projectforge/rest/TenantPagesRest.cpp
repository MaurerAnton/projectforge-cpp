// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/TenantPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: TenantPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct TenantPagesRestAutoRegister {
    TenantPagesRestAutoRegister() {
        spdlog::debug("REST: Registering TenantPagesRest routes");
        TenantPagesRest::registerRoutes();
        spdlog::debug("REST: TenantPagesRest routes registered");
    }
} _TenantPagesRestAutoRegister;

} // namespace
