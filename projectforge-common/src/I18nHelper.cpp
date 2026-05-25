// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/common/I18nHelper.hpp"
#include "org/projectforge/common/StringHelper.hpp"
#include <fstream>
#include <spdlog/spdlog.h>

namespace org::projectforge::common {

I18nHelper& I18nHelper::instance() {
    static I18nHelper inst;
    return inst;
}

void I18nHelper::loadResourceBundle(const std::string& locale, const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) return;
    std::string line;
    auto& bundle = bundles_[locale];
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;
        auto pos = line.find('=');
        if (pos != std::string::npos) {
            bundle[line.substr(0, pos)] = line.substr(pos + 1);
        }
    }
}

void I18nHelper::loadProperties(const std::string& locale, const std::map<std::string, std::string>& props) {
    bundles_[locale].insert(props.begin(), props.end());
}

void I18nHelper::setDefaultLocale(const std::string& locale) {
    defaultLocale_ = locale;
    currentLocale_ = locale;
}

std::string I18nHelper::getLocalizedString(const std::string& key, const std::string& locale) const {
    std::string loc = locale.empty() ? currentLocale_ : locale;
    auto it = bundles_.find(loc);
    if (it != bundles_.end()) {
        auto kit = it->second.find(key);
        if (kit != it->second.end()) return kit->second;
    }
    if (loc != "en") {
        auto en = bundles_.find("en");
        if (en != bundles_.end()) {
            auto kit = en->second.find(key);
            if (kit != en->second.end()) return kit->second;
        }
    }
    return key;
}

std::string I18nHelper::getLocalizedString(const std::string& key,
    const std::vector<MessageParam>& params, const std::string& locale) const {
    std::string base = getLocalizedString(key, locale);
    std::string result = base;
    for (size_t i = 0; i < params.size(); ++i) {
        std::string placeholder = "{" + std::to_string(i) + "}";
        result = StringHelper::replace(result, placeholder, params[i].value);
    }
    return result;
}

std::string I18nHelper::format(const std::string& pattern, const std::vector<std::string>& args) const {
    return StringHelper::format(pattern, args);
}

bool I18nHelper::hasKey(const std::string& key, const std::string& locale) const {
    std::string loc = locale.empty() ? currentLocale_ : locale;
    auto it = bundles_.find(loc);
    if (it != bundles_.end()) return it->second.count(key) > 0;
    return false;
}

std::vector<std::string> I18nHelper::getAvailableLocales() const {
    std::vector<std::string> result;
    for (const auto& [k, v] : bundles_) result.push_back(k);
    return result;
}

std::string I18nHelper::getCurrentLocale() const { return currentLocale_; }

std::string I18nHelper::translate(const std::string& key, const std::string& defaultText) const {
    auto result = getLocalizedString(key);
    return (result == key && !defaultText.empty()) ? defaultText : result;
}

std::string I18nHelper::translatePlural(const std::string& key, int count, const std::string& defaultText) const {
    std::string pluralKey = (count == 1) ? key + ".one" : key + ".other";
    if (hasKey(pluralKey)) return translate(pluralKey, defaultText);
    return translate(key, defaultText);
}
}