// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/KontoPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: KontoPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct KontoPagesRestAutoRegister {
    KontoPagesRestAutoRegister() {
        spdlog::debug("REST: Registering KontoPagesRest routes");
        KontoPagesRest::registerRoutes();
        spdlog::debug("REST: KontoPagesRest routes registered");
    }
} _KontoPagesRestAutoRegister;

} // namespace
