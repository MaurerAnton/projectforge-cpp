// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/FibuPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: FibuPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct FibuPagesRestAutoRegister {
    FibuPagesRestAutoRegister() {
        spdlog::debug("REST: Registering FibuPagesRest routes");
        FibuPagesRest::registerRoutes();
        spdlog::debug("REST: FibuPagesRest routes registered");
    }
} _FibuPagesRestAutoRegister;

} // namespace
