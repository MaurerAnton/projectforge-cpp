// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/AddressObject.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct AddressObjectModuleInit {
    AddressObjectModuleInit() { spdlog::debug("model: AddressObject module initialized"); }
} _AddressObjectInit;
} // namespace
