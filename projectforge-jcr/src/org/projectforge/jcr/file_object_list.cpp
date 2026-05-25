// ProjectForge C++ port — GPL v3
#include "org/projectforge/jcr/file_object_list.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::jcr {
static struct file_object_listModuleInit {
    file_object_listModuleInit() { spdlog::debug("jcr: file_object_list module initialized"); }
} _file_object_listInit;
} // namespace
