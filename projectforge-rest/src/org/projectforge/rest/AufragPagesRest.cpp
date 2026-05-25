// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/AufragPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: AufragPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct AufragPagesRestAutoRegister {
    AufragPagesRestAutoRegister() {
        spdlog::debug("REST: Registering AufragPagesRest routes");
        AufragPagesRest::registerRoutes();
        spdlog::debug("REST: AufragPagesRest routes registered");
    }
} _AufragPagesRestAutoRegister;

} // namespace
