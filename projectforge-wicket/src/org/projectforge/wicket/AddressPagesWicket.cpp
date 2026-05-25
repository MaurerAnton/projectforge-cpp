// ProjectForge C++ port — GPL v3
#include "org/projectforge/wicket/AddressPagesWicket.hpp"
#include <spdlog/spdlog.h>

// Wicket Page Implementation: AddressPagesWicket
namespace org::projectforge::wicket {

// Static initialization
static struct AddressPagesWicketInit {
    AddressPagesWicketInit() { spdlog::debug("Wicket page loaded: AddressPagesWicket"); }
} _AddressPagesWicketInit;

} // namespace
