// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/common/IdGenerator.hpp"
#include "org/projectforge/common/CryptoHelper.hpp"

namespace org::projectforge::common {
IdGenerator& IdGenerator::instance() { static IdGenerator gen; return gen; }
int64_t IdGenerator::nextId() { return counter_.fetch_add(1); }
void IdGenerator::setStartValue(int64_t s) { counter_.store(s); }
std::string IdGenerator::nextUUID() { return CryptoHelper::generateUUID(); }
}