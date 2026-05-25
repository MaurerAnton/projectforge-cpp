// ProjectForge C++ port — GPL v3
#include "org/projectforge/rest/BookPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>

// REST Implementation: BookPagesRest
namespace org::projectforge::rest {

// Auto-register routes on module load
static struct BookPagesRestAutoRegister {
    BookPagesRestAutoRegister() {
        spdlog::debug("REST: Registering BookPagesRest routes");
        BookPagesRest::registerRoutes();
        spdlog::debug("REST: BookPagesRest routes registered");
    }
} _BookPagesRestAutoRegister;

} // namespace
