// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/StatisticsPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: StatisticsPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct StatisticsPagesRestAutoRegister {
    StatisticsPagesRestAutoRegister() {
        spdlog::debug("REST: Registering StatisticsPagesRest routes");
        StatisticsPagesRest::registerRoutes();
        spdlog::debug("REST: StatisticsPagesRest routes registered");
    }
} _StatisticsPagesRestAutoRegister;

} // namespace
