// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/TaskPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: TaskPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct TaskPagesRestAutoRegister {
    TaskPagesRestAutoRegister() {
        spdlog::debug("REST: Registering TaskPagesRest routes");
        TaskPagesRest::registerRoutes();
        spdlog::debug("REST: TaskPagesRest routes registered");
    }
} _TaskPagesRestAutoRegister;

} // namespace
