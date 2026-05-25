// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/UserPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: UserPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct UserPagesRestAutoRegister {
    UserPagesRestAutoRegister() {
        spdlog::debug("REST: Registering UserPagesRest routes");
        UserPagesRest::registerRoutes();
        spdlog::debug("REST: UserPagesRest routes registered");
    }
} _UserPagesRestAutoRegister;

} // namespace
