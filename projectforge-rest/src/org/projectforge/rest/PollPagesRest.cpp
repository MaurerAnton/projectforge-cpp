// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/PollPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: PollPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct PollPagesRestAutoRegister {
    PollPagesRestAutoRegister() {
        spdlog::debug("REST: Registering PollPagesRest routes");
        PollPagesRest::registerRoutes();
        spdlog::debug("REST: PollPagesRest routes registered");
    }
} _PollPagesRestAutoRegister;

} // namespace
