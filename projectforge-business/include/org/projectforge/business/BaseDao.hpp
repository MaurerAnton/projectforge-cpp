// ProjectForge C++ port - Base Data Access Object
#pragma once
#include <string>
#include <vector>
#include <optional>
#include <functional>
#include <memory>
#include <stdexcept>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>

namespace org::projectforge::business {

// Simplified BaseDao - template methods are inline, no sqlite_orm dependency at template level
template<typename T>
class BaseDao {
public:
    BaseDao() = default;
    virtual ~BaseDao() = default;

    virtual std::optional<T> getById(int64_t /*id*/) {
        return std::nullopt;
    }

    virtual std::vector<T> getAll() {
        return {};
    }

    virtual std::vector<T> getList(int /*page*/, int /*pageSize*/, const std::string& /*orderBy*/ = "id") {
        return {};
    }

    virtual T save(T& entity) {
        return entity;
    }

    virtual bool deleteById(int64_t /*id*/) {
        return true;
    }

    virtual int64_t count() {
        return 0;
    }

    virtual bool exists(int64_t /*id*/) {
        return false;
    }

    virtual std::vector<T> search(const std::string& /*query*/, int /*limit*/ = 100) {
        return {};
    }
};

// Common entity macros for JSON serialization
#define DECLARE_ENTITY_FIELDS() \
    int64_t id = -1; \
    int64_t created = 0; \
    int64_t lastUpdate = 0; \
    bool deleted = false

#define JSON_ENTITY_BASE(j) \
    if (id >= 0) j["id"] = id; \
    if (created > 0) j["created"] = created; \
    if (lastUpdate > 0) j["lastUpdate"] = lastUpdate; \
    if (deleted) j["deleted"] = true

#define FROMJSON_ENTITY_BASE(j) \
    if (j.contains("id")) id = j["id"].get<int64_t>(); \
    if (j.contains("created")) created = j["created"].get<int64_t>(); \
    if (j.contains("lastUpdate")) lastUpdate = j["lastUpdate"].get<int64_t>(); \
    if (j.contains("deleted")) deleted = j["deleted"].get<bool>()

} // namespace
