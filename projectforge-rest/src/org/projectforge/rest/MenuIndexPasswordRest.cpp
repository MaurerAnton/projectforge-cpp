// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/MenuIndexPasswordRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: MenuIndexPasswordRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct MenuIndexPasswordRestAutoRegister {
    MenuIndexPasswordRestAutoRegister() {
        spdlog::debug("REST: Registering MenuIndexPasswordRest routes");
        MenuIndexPasswordRest::registerRoutes();
        spdlog::debug("REST: MenuIndexPasswordRest routes registered");
    }
} _MenuIndexPasswordRestAutoRegister;

} // namespace
