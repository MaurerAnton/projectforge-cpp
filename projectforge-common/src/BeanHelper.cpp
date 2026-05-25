// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/common/BeanHelper.hpp"
namespace org::projectforge::common {
BeanHelper& BeanHelper::instance() { static BeanHelper inst; return inst; }
bool BeanHelper::hasBean(const std::string& name) const {
    return beans_.count(name) > 0 || factories_.count(name) > 0;
}
void BeanHelper::removeBean(const std::string& name) { beans_.erase(name); factories_.erase(name); }
void BeanHelper::clear() { beans_.clear(); factories_.clear(); }
}