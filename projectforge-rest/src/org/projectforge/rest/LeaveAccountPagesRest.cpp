// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/LeaveAccountPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: LeaveAccountPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct LeaveAccountPagesRestAutoRegister {
    LeaveAccountPagesRestAutoRegister() {
        spdlog::debug("REST: Registering LeaveAccountPagesRest routes");
        LeaveAccountPagesRest::registerRoutes();
        spdlog::debug("REST: LeaveAccountPagesRest routes registered");
    }
} _LeaveAccountPagesRestAutoRegister;

} // namespace
