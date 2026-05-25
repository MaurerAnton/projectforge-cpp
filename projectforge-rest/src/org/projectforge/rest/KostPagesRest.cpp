// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/KostPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: KostPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct KostPagesRestAutoRegister {
    KostPagesRestAutoRegister() {
        spdlog::debug("REST: Registering KostPagesRest routes");
        KostPagesRest::registerRoutes();
        spdlog::debug("REST: KostPagesRest routes registered");
    }
} _KostPagesRestAutoRegister;

} // namespace
