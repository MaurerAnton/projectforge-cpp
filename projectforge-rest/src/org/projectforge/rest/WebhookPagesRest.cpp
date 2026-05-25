// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/WebhookPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: WebhookPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct WebhookPagesRestAutoRegister {
    WebhookPagesRestAutoRegister() {
        spdlog::debug("REST: Registering WebhookPagesRest routes");
        WebhookPagesRest::registerRoutes();
        spdlog::debug("REST: WebhookPagesRest routes registered");
    }
} _WebhookPagesRestAutoRegister;

} // namespace
