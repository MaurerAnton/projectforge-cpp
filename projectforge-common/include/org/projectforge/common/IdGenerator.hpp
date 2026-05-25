// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <atomic>

namespace org::projectforge::common {

class IdGenerator {
public:
    static IdGenerator& instance();
    int64_t nextId();
    void setStartValue(int64_t start);
    std::string nextUUID();
private:
    std::atomic<int64_t> counter_{1};
};
}