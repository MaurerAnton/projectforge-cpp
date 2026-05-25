// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/NotificationPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: NotificationPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct NotificationPagesRestAutoRegister {
    NotificationPagesRestAutoRegister() {
        spdlog::debug("REST: Registering NotificationPagesRest routes");
        NotificationPagesRest::registerRoutes();
        spdlog::debug("REST: NotificationPagesRest routes registered");
    }
} _NotificationPagesRestAutoRegister;

} // namespace
