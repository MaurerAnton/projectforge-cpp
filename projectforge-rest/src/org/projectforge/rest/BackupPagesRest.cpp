// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/BackupPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: BackupPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct BackupPagesRestAutoRegister {
    BackupPagesRestAutoRegister() {
        spdlog::debug("REST: Registering BackupPagesRest routes");
        BackupPagesRest::registerRoutes();
        spdlog::debug("REST: BackupPagesRest routes registered");
    }
} _BackupPagesRestAutoRegister;

} // namespace
