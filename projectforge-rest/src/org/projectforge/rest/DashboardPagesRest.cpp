// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/DashboardPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: DashboardPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct DashboardPagesRestAutoRegister {
    DashboardPagesRestAutoRegister() {
        spdlog::debug("REST: Registering DashboardPagesRest routes");
        DashboardPagesRest::registerRoutes();
        spdlog::debug("REST: DashboardPagesRest routes registered");
    }
} _DashboardPagesRestAutoRegister;

} // namespace
