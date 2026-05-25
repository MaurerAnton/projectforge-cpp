// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <map>
#include <any>

namespace org::projectforge::common {

class ApplicationContext {
public:
    static ApplicationContext& instance();

    template<typename T>
    void set(const std::string& key, const T& value) { context_[key] = value; }

    template<typename T>
    T get(const std::string& key, const T& defaultVal = T{}) const {
        auto it = context_.find(key);
        return (it != context_.end()) ? std::any_cast<T>(it->second) : defaultVal;
    }

    bool has(const std::string& key) const;
    void remove(const std::string& key);
    void clear();

private:
    std::map<std::string, std::any> context_;
};
}