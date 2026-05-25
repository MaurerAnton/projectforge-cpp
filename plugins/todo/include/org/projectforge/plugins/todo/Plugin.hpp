// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <ctime>

namespace org::projectforge::plugins::todo {

struct TodoEntity {
    int64_t id=-1; std::string title, description, priority="MEDIUM";
    int64_t dueDate=0; bool completed=false; int64_t completedAt=0;
    int64_t ownerId=-1; int64_t assignedTo=-1;
    std::string category; int order=0;
};

class TodoPlugin {
public:
    static void init() {}
    static std::string getName() { return "ToDo Plugin"; }
};
}