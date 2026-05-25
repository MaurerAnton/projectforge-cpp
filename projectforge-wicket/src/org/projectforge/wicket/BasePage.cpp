// ProjectForge C++ port — GPL v3
#include "org/projectforge/wicket/BasePage.hpp"
#include <spdlog/spdlog.h>

// Wicket Page Implementation: BasePage
namespace org::projectforge::wicket {

// Static initialization
static struct BasePageInit {
    BasePageInit() { spdlog::debug("Wicket page loaded: BasePage"); }
} _BasePageInit;

} // namespace
