// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/common/ApplicationContext.hpp"
namespace org::projectforge::common {
ApplicationContext& ApplicationContext::instance() { static ApplicationContext ctx; return ctx; }
bool ApplicationContext::has(const std::string& k) const { return context_.count(k) > 0; }
void ApplicationContext::remove(const std::string& k) { context_.erase(k); }
void ApplicationContext::clear() { context_.clear(); }
}