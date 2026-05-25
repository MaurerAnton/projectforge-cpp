// ProjectForge C++ port — GPL v3
#include "org/projectforge/jcr/file_object.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::jcr {
static struct file_objectModuleInit {
    file_objectModuleInit() { spdlog::debug("jcr: file_object module initialized"); }
} _file_objectInit;
} // namespace
