// ProjectForge C++ port — GPL v3
#include "org/projectforge/model/rest/datetime_serialization.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge:: {
static struct datetime_serializationModuleInit {
    datetime_serializationModuleInit() { spdlog::debug("model: datetime_serialization module initialized"); }
} _datetime_serializationInit;
} // namespace
