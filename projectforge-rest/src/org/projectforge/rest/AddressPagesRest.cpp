// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/AddressPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: AddressPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct AddressPagesRestAutoRegister {
    AddressPagesRestAutoRegister() {
        spdlog::debug("REST: Registering AddressPagesRest routes");
        AddressPagesRest::registerRoutes();
        spdlog::debug("REST: AddressPagesRest routes registered");
    }
} _AddressPagesRestAutoRegister;

} // namespace
