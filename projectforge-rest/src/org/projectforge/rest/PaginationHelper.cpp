// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/PaginationHelper.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: PaginationHelper
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct PaginationHelperAutoRegister {
    PaginationHelperAutoRegister() {
        spdlog::debug("REST: Registering PaginationHelper routes");
        PaginationHelper::registerRoutes();
        spdlog::debug("REST: PaginationHelper routes registered");
    }
} _PaginationHelperAutoRegister;

} // namespace
