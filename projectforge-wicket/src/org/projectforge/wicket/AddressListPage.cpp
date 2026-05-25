// ProjectForge C++ port — GPL v3
#include "org/projectforge/wicket/AddressListPage.hpp"
#include <spdlog/spdlog.h>

// Wicket Page Implementation: AddressListPage
namespace org::projectforge::wicket {

// Static initialization
static struct AddressListPageInit {
    AddressListPageInit() { spdlog::debug("Wicket page loaded: AddressListPage"); }
} _AddressListPageInit;

} // namespace
