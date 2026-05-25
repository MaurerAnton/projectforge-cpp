#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>
#include <cstdint>
#include <nlohmann/json.hpp>

namespace org::projectforge::business::configuration {

using json = nlohmann::json;

struct ConfigurationEntry {
    int64_t id = 0;
    std::string config_key;
    std::string config_value;
    std::string description;
    std::string category; // SYSTEM, USER, FIBU, CALENDAR, MAIL, etc.
    int64_t user_id = 0; // 0 = global/system
    int64_t updated_at = 0;
    int64_t updated_by = 0;
    bool encrypted = false;
};

inline auto make_configuration_table() {
    using namespace sqlite_orm;
    return make_table("t_configuration",
        make_column("id", &ConfigurationEntry::id, primary_key().autoincrement()),
        make_column("config_key", &ConfigurationEntry::config_key),
        make_column("config_value", &ConfigurationEntry::config_value),
        make_column("description", &ConfigurationEntry::description),
        make_column("category", &ConfigurationEntry::category),
        make_column("user_id", &ConfigurationEntry::user_id),
        make_column("updated_at", &ConfigurationEntry::updated_at),
        make_column("updated_by", &ConfigurationEntry::updated_by),
        make_column("encrypted", &ConfigurationEntry::encrypted));
}

class ConfigurationDao : public BaseDao<ConfigurationEntry> {
public:
    explicit ConfigurationDao(std::shared_ptr<sqlite_orm::database> db);

    std::optional<std::string> getValue(const std::string& key, int64_t userId = 0) const;
    std::string getValueOrDefault(const std::string& key, const std::string& defaultValue, int64_t userId = 0) const;
    bool setValue(const std::string& key, const std::string& value, int64_t userId = 0, int64_t updatedBy = 0);

    int32_t getIntValue(const std::string& key, int32_t defaultValue = 0, int64_t userId = 0) const;
    double getDoubleValue(const std::string& key, double defaultValue = 0.0, int64_t userId = 0) const;
    bool getBoolValue(const std::string& key, bool defaultValue = false, int64_t userId = 0) const;
    json getJsonValue(const std::string& key, int64_t userId = 0) const;

    bool setIntValue(const std::string& key, int32_t value, int64_t userId = 0);
    bool setDoubleValue(const std::string& key, double value, int64_t userId = 0);
    bool setBoolValue(const std::string& key, bool value, int64_t userId = 0);
    bool setJsonValue(const std::string& key, const json& value, int64_t userId = 0);

    std::vector<ConfigurationEntry> findByCategory(const std::string& category) const;
    std::vector<ConfigurationEntry> findByUser(int64_t userId) const;
    std::vector<ConfigurationEntry> findGlobal() const;
    bool deleteByKey(const std::string& key, int64_t userId = 0);

    // Bulk operations
    std::map<std::string, std::string> getAllForCategory(const std::string& category) const;
    bool importFromJson(const json& data, int64_t userId = 0, int64_t importedBy = 0);
    json exportToJson(int64_t userId = 0) const;

    json toJson(const ConfigurationEntry& entry) const override;
    ConfigurationEntry fromJson(const json& j) const override;

private:
    std::optional<ConfigurationEntry> findByKey(const std::string& key, int64_t userId = 0) const;
};

} // namespace org::projectforge::business::configuration
