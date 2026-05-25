// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/address_object.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct address_objectModuleInit {
    address_objectModuleInit() { spdlog::debug("model: address_object module initialized"); }
} _address_objectInit;
} // namespace
