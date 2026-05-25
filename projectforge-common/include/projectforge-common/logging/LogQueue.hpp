/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <deque>
#include <mutex>
#include <cstdint>
#include <memory>
#include <vector>
namespace org::projectforge::common::logging {
class LoggingEventData;
class LogQueue {
public:
    static constexpr int MAX_SIZE = 10000;
    void add(std::shared_ptr<LoggingEventData> event);
    std::vector<std::shared_ptr<LoggingEventData>> getEvents(int64_t since, int maxRows);
    std::vector<std::shared_ptr<LoggingEventData>> getAll();
    void clear();
    int size();
private:
    std::deque<std::shared_ptr<LoggingEventData>> queue_;
    std::mutex mutex_;
    int64_t counter_ = 0;
};
}
