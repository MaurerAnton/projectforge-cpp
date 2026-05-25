// ProjectForge C++ port — GPL v3
#include "org/projectforge/wicket/BaseEditPage.hpp"
#include <spdlog/spdlog.h>

// Wicket Page Implementation: BaseEditPage
namespace org::projectforge::wicket {

// Static initialization
static struct BaseEditPageInit {
    BaseEditPageInit() { spdlog::debug("Wicket page loaded: BaseEditPage"); }
} _BaseEditPageInit;

} // namespace
