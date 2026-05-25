// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <map>
#include <vector>
#include <optional>

namespace org::projectforge::common {

enum class MessageParamType { VALUE, I18N_KEY };

struct MessageParam {
    std::string value;
    MessageParamType type;
    MessageParam(const std::string& v, MessageParamType t = MessageParamType::VALUE)
        : value(v), type(t) {}
};

class I18nHelper {
public:
    static I18nHelper& instance();

    void loadResourceBundle(const std::string& locale, const std::string& path);
    void loadProperties(const std::string& locale, const std::map<std::string, std::string>& props);
    void setDefaultLocale(const std::string& locale);

    std::string getLocalizedString(const std::string& key, const std::string& locale = "") const;
    std::string getLocalizedString(const std::string& key, const std::vector<MessageParam>& params,
                                   const std::string& locale = "") const;

    std::string format(const std::string& pattern, const std::vector<std::string>& args) const;

    bool hasKey(const std::string& key, const std::string& locale = "") const;

    std::vector<std::string> getAvailableLocales() const;
    std::string getCurrentLocale() const;

    std::string translate(const std::string& key, const std::string& defaultText = "") const;
    std::string translatePlural(const std::string& key, int count, const std::string& defaultText = "") const;

private:
    I18nHelper() = default;
    std::map<std::string, std::map<std::string, std::string>> bundles_;
    std::string defaultLocale_ = "en";
    std::string currentLocale_ = "en";
};

inline std::string i18n(const std::string& key) {
    return I18nHelper::instance().translate(key, key);
}

}