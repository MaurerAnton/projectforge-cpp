// ProjectForge C++ port — GPL v3
#include "org/projectforge/wicket/BaseListPage.hpp"
#include <spdlog/spdlog.h>

// Wicket Page Implementation: BaseListPage
namespace org::projectforge::wicket {

// Static initialization
static struct BaseListPageInit {
    BaseListPageInit() { spdlog::debug("Wicket page loaded: BaseListPage"); }
} _BaseListPageInit;

} // namespace
