// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/FilePagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: FilePagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct FilePagesRestAutoRegister {
    FilePagesRestAutoRegister() {
        spdlog::debug("REST: Registering FilePagesRest routes");
        FilePagesRest::registerRoutes();
        spdlog::debug("REST: FilePagesRest routes registered");
    }
} _FilePagesRestAutoRegister;

} // namespace
