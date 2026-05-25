/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
#include <set>
#include <mutex>
#include <functional>
namespace org::projectforge::common {
class CoroutineTracker {
public:
    static CoroutineTracker& instance();
    void add(const std::string& name);
    void remove(const std::string& name);
    std::set<std::string> getActiveJobs() const;
    int getCount() const;
private:
    CoroutineTracker() = default;
    std::set<std::string> activeJobs_;
    mutable std::mutex mutex_;
};
}
