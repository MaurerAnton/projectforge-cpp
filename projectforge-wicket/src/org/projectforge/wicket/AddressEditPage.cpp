// ProjectForge C++ port — GPL v3
#include "org/projectforge/wicket/AddressEditPage.hpp"
#include <spdlog/spdlog.h>

// Wicket Page Implementation: AddressEditPage
namespace org::projectforge::wicket {

// Static initialization
static struct AddressEditPageInit {
    AddressEditPageInit() { spdlog::debug("Wicket page loaded: AddressEditPage"); }
} _AddressEditPageInit;

} // namespace
