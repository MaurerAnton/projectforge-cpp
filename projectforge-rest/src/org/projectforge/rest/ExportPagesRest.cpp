// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/ExportPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: ExportPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct ExportPagesRestAutoRegister {
    ExportPagesRestAutoRegister() {
        spdlog::debug("REST: Registering ExportPagesRest routes");
        ExportPagesRest::registerRoutes();
        spdlog::debug("REST: ExportPagesRest routes registered");
    }
} _ExportPagesRestAutoRegister;

} // namespace
