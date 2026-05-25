// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <ctime>

namespace org::projectforge::plugins::memo {

struct MemoEntity {
    int64_t id=-1; std::string title, content;
    int64_t created=0, lastUpdate=0;
    int64_t ownerId=-1; std::vector<int64_t> sharedWith;
};

class MemoPlugin {
public:
    static void init() {}
    static std::string getName() { return "Memo Plugin"; }
};
}