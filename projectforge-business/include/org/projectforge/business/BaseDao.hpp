// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <optional>
#include <functional>
#include <memory>
#include <stdexcept>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <sqlite_orm/sqlite_orm.h>

namespace org::projectforge::business {

template<typename T>
class BaseDao {
public:
    using Storage = sqlite_orm::storage_t<sqlite_orm::internal::storage_impl<>>;
    using QueryResult = std::vector<T>;

    BaseDao(Storage& storage) : storage_(storage) {}

    virtual std::optional<T> getById(int64_t id) {
        try {
            auto result = storage_.template get_all<T>(sqlite_orm::where(sqlite_orm::c(&T::id) == id));
            return result.empty() ? std::nullopt : std::optional<T>(result[0]);
        } catch (const std::exception& e) {
            spdlog::error("BaseDao::getById failed: {}", e.what());
            return std::nullopt;
        }
    }

    virtual std::vector<T> getAll() {
        return storage_.template get_all<T>();
    }

    virtual std::vector<T> getList(int page, int pageSize, const std::string& orderBy = "id") {
        int offset = (page - 1) * pageSize;
        return storage_.template get_all<T>(
            sqlite_orm::order_by(sqlite_orm::get_order_by(orderBy)),
            sqlite_orm::limit(pageSize),
            sqlite_orm::offset(offset)
        );
    }

    virtual T save(T& entity) {
        if (entity.id >= 0 && exists(entity.id)) {
            storage_.update(entity);
        } else {
            entity.id = storage_.insert(entity);
        }
        return entity;
    }

    virtual bool deleteById(int64_t id) {
        try {
            storage_.template remove_all<T>(sqlite_orm::where(sqlite_orm::c(&T::id) == id));
            return true;
        } catch (...) {
            return false;
        }
    }

    virtual int64_t count() {
        return storage_.template count<T>();
    }

    virtual bool exists(int64_t id) {
        return storage_.template count<T>(sqlite_orm::where(sqlite_orm::c(&T::id) == id)) > 0;
    }

    virtual int64_t countByFilter(const std::string& search) {
        return storage_.template count<T>();
    }

    virtual std::vector<T> search(const std::string& query, int limit = 100) {
        return storage_.template get_all<T>(sqlite_orm::limit(limit));
    }

protected:
    Storage& storage_;
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
