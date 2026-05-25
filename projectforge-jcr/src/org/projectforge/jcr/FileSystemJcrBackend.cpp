// ProjectForge C++ port — GPL v3
#include "org/projectforge/jcr/FileSystemJcrBackend.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::jcr {
static struct FileSystemJcrBackendModuleInit {
    FileSystemJcrBackendModuleInit() { spdlog::debug("jcr: FileSystemJcrBackend module initialized"); }
} _FileSystemJcrBackendInit;
} // namespace
