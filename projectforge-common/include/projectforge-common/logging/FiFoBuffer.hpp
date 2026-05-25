/////////////////////////////////////////////////////////////////////////////
// (C) 2001-2026 Micromata GmbH - GPL v3
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <vector>
#include <mutex>
#include <optional>
namespace org::projectforge::common::logging {
template<typename T>
class FiFoBuffer {
public:
    explicit FiFoBuffer(int maxSize) : maxSize_(maxSize) {}
    void clear() { std::lock_guard<std::mutex> lock(mutex_); list_.clear(); }
    void add(const T& element) {
        std::lock_guard<std::mutex> lock(mutex_);
        if (static_cast<int>(list_.size()) >= maxSize_ && !list_.empty()) list_.erase(list_.begin());
        list_.push_back(element);
    }
    std::optional<T> get(int index) const {
        std::lock_guard<std::mutex> lock(mutex_);
        if (index < 0 || index >= static_cast<int>(list_.size())) return std::nullopt;
        return list_[index];
    }
    std::optional<T> newestEntry() const {
        std::lock_guard<std::mutex> lock(mutex_);
        if (list_.empty()) return std::nullopt;
        return list_.back();
    }
    int size() const { std::lock_guard<std::mutex> lock(mutex_); return static_cast<int>(list_.size()); }
private:
    int maxSize_;
    std::vector<T> list_;
    mutable std::mutex mutex_;
};
}
