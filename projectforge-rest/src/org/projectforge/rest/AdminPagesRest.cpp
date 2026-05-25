// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/AdminPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: AdminPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct AdminPagesRestAutoRegister {
    AdminPagesRestAutoRegister() {
        spdlog::debug("REST: Registering AdminPagesRest routes");
        AdminPagesRest::registerRoutes();
        spdlog::debug("REST: AdminPagesRest routes registered");
    }
} _AdminPagesRestAutoRegister;

} // namespace
