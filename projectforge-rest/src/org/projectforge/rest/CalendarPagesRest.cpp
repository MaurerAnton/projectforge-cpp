// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/CalendarPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: CalendarPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct CalendarPagesRestAutoRegister {
    CalendarPagesRestAutoRegister() {
        spdlog::debug("REST: Registering CalendarPagesRest routes");
        CalendarPagesRest::registerRoutes();
        spdlog::debug("REST: CalendarPagesRest routes registered");
    }
} _CalendarPagesRestAutoRegister;

} // namespace
