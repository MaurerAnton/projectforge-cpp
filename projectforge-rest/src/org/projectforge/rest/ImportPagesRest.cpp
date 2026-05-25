// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/ImportPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: ImportPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct ImportPagesRestAutoRegister {
    ImportPagesRestAutoRegister() {
        spdlog::debug("REST: Registering ImportPagesRest routes");
        ImportPagesRest::registerRoutes();
        spdlog::debug("REST: ImportPagesRest routes registered");
    }
} _ImportPagesRestAutoRegister;

} // namespace
