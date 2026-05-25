// ProjectForge C++ port — GPL v3
#include "org/projectforge/jcr/SqliteJcrBackend.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::jcr {
static struct SqliteJcrBackendModuleInit {
    SqliteJcrBackendModuleInit() { spdlog::debug("jcr: SqliteJcrBackend module initialized"); }
} _SqliteJcrBackendInit;
} // namespace
