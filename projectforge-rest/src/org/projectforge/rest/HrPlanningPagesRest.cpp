// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/HrPlanningPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: HrPlanningPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct HrPlanningPagesRestAutoRegister {
    HrPlanningPagesRestAutoRegister() {
        spdlog::debug("REST: Registering HrPlanningPagesRest routes");
        HrPlanningPagesRest::registerRoutes();
        spdlog::debug("REST: HrPlanningPagesRest routes registered");
    }
} _HrPlanningPagesRestAutoRegister;

} // namespace
