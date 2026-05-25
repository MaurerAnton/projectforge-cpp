// ProjectForge C++ port — GPL v3
#include "org/projectforge/jcr/file_info.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::jcr {
static struct file_infoModuleInit {
    file_infoModuleInit() { spdlog::debug("jcr: file_info module initialized"); }
} _file_infoInit;
} // namespace
