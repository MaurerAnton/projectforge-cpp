// ProjectForge C++ port — GPL v3
#include "org/projectforge/wicket/AbstractForm.hpp"
#include <spdlog/spdlog.h>

// Wicket Page Implementation: AbstractForm
namespace org::projectforge::wicket {

// Static initialization
static struct AbstractFormInit {
    AbstractFormInit() { spdlog::debug("Wicket page loaded: AbstractForm"); }
} _AbstractFormInit;

} // namespace
