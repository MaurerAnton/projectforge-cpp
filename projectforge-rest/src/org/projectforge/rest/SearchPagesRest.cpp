// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/SearchPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: SearchPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct SearchPagesRestAutoRegister {
    SearchPagesRestAutoRegister() {
        spdlog::debug("REST: Registering SearchPagesRest routes");
        SearchPagesRest::registerRoutes();
        spdlog::debug("REST: SearchPagesRest routes registered");
    }
} _SearchPagesRestAutoRegister;

} // namespace
