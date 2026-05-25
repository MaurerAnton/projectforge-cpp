// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/TimesheetPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: TimesheetPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct TimesheetPagesRestAutoRegister {
    TimesheetPagesRestAutoRegister() {
        spdlog::debug("REST: Registering TimesheetPagesRest routes");
        TimesheetPagesRest::registerRoutes();
        spdlog::debug("REST: TimesheetPagesRest routes registered");
    }
} _TimesheetPagesRestAutoRegister;

} // namespace
