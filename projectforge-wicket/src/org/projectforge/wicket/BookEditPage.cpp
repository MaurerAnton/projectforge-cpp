// ProjectForge C++ port — GPL v3
#include "org/projectforge/wicket/BookEditPage.hpp"
#include <spdlog/spdlog.h>

// Wicket Page Implementation: BookEditPage
namespace org::projectforge::wicket {

// Static initialization
static struct BookEditPageInit {
    BookEditPageInit() { spdlog::debug("Wicket page loaded: BookEditPage"); }
} _BookEditPageInit;

} // namespace
