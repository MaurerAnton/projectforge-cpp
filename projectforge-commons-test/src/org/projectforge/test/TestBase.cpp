// ProjectForge C++ port — GPL v3
#include "org/projectforge/test/TestBase.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::commons-test {
static struct TestBaseModuleInit {
    TestBaseModuleInit() { spdlog::debug("commons-test: TestBase module initialized"); }
} _TestBaseInit;
} // namespace
