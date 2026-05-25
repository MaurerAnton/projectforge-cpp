// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/VacationHRPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: VacationHRPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct VacationHRPagesRestAutoRegister {
    VacationHRPagesRestAutoRegister() {
        spdlog::debug("REST: Registering VacationHRPagesRest routes");
        VacationHRPagesRest::registerRoutes();
        spdlog::debug("REST: VacationHRPagesRest routes registered");
    }
} _VacationHRPagesRestAutoRegister;

} // namespace
