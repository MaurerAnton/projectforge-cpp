// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <map>
#include <any>
#include <optional>
#include <functional>
#include <algorithm>
#include <chrono>
#include <memory>
#include <mutex>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>

namespace org::projectforge::framework::persistence {

// ============================================================================
// SORT PROPERTY
// ============================================================================
struct SortProperty {
    std::string property;
    bool ascending = true;
    SortProperty() = default;
    SortProperty(const std::string& p, bool asc=true) : property(p), ascending(asc) {}
    std::string toOrderBy() const { return property + (ascending ? " ASC" : " DESC"); }
};

// ============================================================================
// QUERY FILTER
// ============================================================================
class QueryFilter {
public:
    QueryFilter() = default;
    QueryFilter(const std::string& searchString) : searchString_(searchString) {}

    QueryFilter& setSearchString(const std::string& s) { searchString_ = s; return *this; }
    QueryFilter& setFullTextSearchString(const std::string& s) { fulltextSearchString_ = s; return *this; }
    QueryFilter& setDeleted(std::optional<bool> d) { deleted_ = d; return *this; }
    QueryFilter& setAutoWildcardSearch(bool aws) { autoWildcardSearch_ = aws; return *this; }
    QueryFilter& addSortProperty(const SortProperty& sp) { sortProperties_.push_back(sp); return *this; }
    QueryFilter& setModifiedFrom(int64_t from) { modifiedFrom_ = from; return *this; }
    QueryFilter& setModifiedTo(int64_t to) { modifiedTo_ = to; return *this; }
    QueryFilter& setModifiedByUserId(int64_t uid) { modifiedByUserId_ = uid; return *this; }
    QueryFilter& setSearchHistory(const std::string& sh) { searchHistory_ = sh; return *this; }
    QueryFilter& setMaxRows(int max) { maxRows_ = max; return *this; }
    QueryFilter& setFirstResult(int first) { firstResult_ = first; return *this; }
    QueryFilter& addPredicate(const std::string& field, const std::string& op, const std::any& value) {
        predicates_.push_back({field, op, value}); return *this;
    }
    QueryFilter& setExtended(const std::string& key, const std::any& value) {
        extended_[key] = value; return *this;
    }

    const std::string& getSearchString() const { return searchString_; }
    const std::vector<SortProperty>& getSortProperties() const { return sortProperties_; }
    std::optional<bool> getDeleted() const { return deleted_; }
    bool getAutoWildcardSearch() const { return autoWildcardSearch_; }
    std::optional<int64_t> getModifiedFrom() const { return modifiedFrom_; }
    std::optional<int64_t> getModifiedTo() const { return modifiedTo_; }
    std::optional<int64_t> getModifiedByUserId() const { return modifiedByUserId_; }
    int getMaxRows() const { return maxRows_; }
    int getFirstResult() const { return firstResult_; }

    template<typename T>
    bool matches(const T& entity) const {
        if (deleted_.has_value() && entity.deleted != *deleted_) return false;
        if (!searchString_.empty()) {
            std::string lower = searchString_;
            std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            // Check common searchable fields
            if constexpr (requires { entity.title; }) {
                std::string t = entity.title;
                std::transform(t.begin(), t.end(), t.begin(), ::tolower);
                if (t.find(lower) != std::string::npos) return true;
            }
            if constexpr (requires { entity.description; }) {
                std::string d = entity.description;
                std::transform(d.begin(), d.end(), d.begin(), ::tolower);
                if (d.find(lower) != std::string::npos) return true;
            }
            if constexpr (requires { entity.name; }) {
                std::string n = entity.name;
                std::transform(n.begin(), n.end(), n.begin(), ::tolower);
                if (n.find(lower) != std::string::npos) return true;
            }
            return false;
        }
        return true;
    }

private:
    struct Predicate {
        std::string field, op;
        std::any value;
    };
    std::string searchString_, searchHistory_;
    std::string fulltextSearchString_;
    std::optional<bool> deleted_;
    bool autoWildcardSearch_ = false;
    std::vector<SortProperty> sortProperties_;
    std::vector<Predicate> predicates_;
    std::map<std::string, std::any> extended_;
    std::optional<int64_t> modifiedFrom_, modifiedTo_, modifiedByUserId_;
    int maxRows_ = 100, firstResult_ = 0;
};

// ============================================================================
// EXTENDED BASE DO - Base Data Object for all entities
// ============================================================================
class ExtendedBaseDO {
public:
    int64_t id = -1;
    int64_t created = 0;
    int64_t lastUpdate = 0;
    bool deleted = false;
    int64_t tenant = 0;

    virtual ~ExtendedBaseDO() = default;

    void setCreated() {
        if (created == 0) created = nowMillis();
    }
    void setLastUpdate() { lastUpdate = nowMillis(); }
    void touch() { setCreated(); setLastUpdate(); }
    void markDeleted() { deleted = true; setLastUpdate(); }

    virtual nlohmann::json toJson() const {
        nlohmann::json j;
        if (id >= 0) j["id"] = id;
        if (created > 0) j["created"] = created;
        if (lastUpdate > 0) j["lastUpdate"] = lastUpdate;
        if (deleted) j["deleted"] = true;
        return j;
    }
    virtual void fromJson(const nlohmann::json& j) {
        if (j.contains("id")) id = j["id"];
        if (j.contains("created")) created = j["created"];
        if (j.contains("lastUpdate")) lastUpdate = j["lastUpdate"];
        if (j.contains("deleted")) deleted = j["deleted"];
    }

protected:
    static int64_t nowMillis() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    }
};

// ============================================================================
// HISTORY ENTRY
// ============================================================================
struct HistoryEntry {
    int64_t id = -1;
    int64_t entityId = -1;
    std::string entityType;
    std::string propertyName;
    std::string oldValue, newValue;
    int64_t modifiedAt = 0;
    int64_t modifiedBy = -1;
    std::string comment;
    nlohmann::json toJson() const {
        nlohmann::json j;
        j["id"]=id; j["entityId"]=entityId; j["entityType"]=entityType;
        j["propertyName"]=propertyName; j["oldValue"]=oldValue; j["newValue"]=newValue;
        j["modifiedAt"]=modifiedAt; j["modifiedBy"]=modifiedBy;
        if (!comment.empty()) j["comment"]=comment;
        return j;
    }
};

// ============================================================================
// HISTORY SERVICE
// ============================================================================
class HistoryService {
public:
    template<typename T>
    static void recordChange(int64_t entityId, const std::string& entityType,
                              const std::string& property, const std::string& oldVal,
                              const std::string& newVal, int64_t userId=-1, const std::string& comment="") {
        HistoryEntry entry;
        entry.entityId = entityId;
        entry.entityType = entityType;
        entry.propertyName = property;
        entry.oldValue = oldVal;
        entry.newValue = newVal;
        entry.modifiedAt = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        entry.modifiedBy = userId;
        entry.comment = comment;
        history_.push_back(entry);
        spdlog::debug("History: {}#{} {} changed from '{}' to '{}'", entityType, entityId, property, oldVal, newVal);
    }

    static std::vector<HistoryEntry> getHistory(int64_t entityId, const std::string& entityType) {
        std::vector<HistoryEntry> result;
        for (auto& h : history_) {
            if (h.entityId == entityId && h.entityType == entityType) result.push_back(h);
        }
        return result;
    }

    static std::vector<HistoryEntry> searchHistory(const std::string& query, int limit=100) {
        std::vector<HistoryEntry> result;
        std::string q = query;
        std::transform(q.begin(), q.end(), q.begin(), ::tolower);
        for (auto& h : history_) {
            std::string searchable = h.propertyName + " " + h.oldValue + " " + h.newValue + " " + h.comment;
            std::transform(searchable.begin(), searchable.end(), searchable.begin(), ::tolower);
            if (searchable.find(q) != std::string::npos) {
                result.push_back(h);
                if (static_cast<int>(result.size()) >= limit) break;
            }
        }
        return result;
    }

    static void clearOldEntries(int daysToKeep=365) {
        auto cutoff = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count()
            - static_cast<int64_t>(daysToKeep) * 86400000LL;
        history_.erase(std::remove_if(history_.begin(), history_.end(),
            [cutoff](const HistoryEntry& h) { return h.modifiedAt < cutoff; }),
            history_.end());
    }

private:
    static inline std::vector<HistoryEntry> history_;
};

// ============================================================================
// ADVANCED BASE DAO with History, Filtering, Pagination
// ============================================================================
template<typename T>
class AdvancedBaseDao {
public:
    AdvancedBaseDao() = default;
    virtual ~AdvancedBaseDao() = default;

    virtual void setStorage(void* storage) { storage_ = storage; }

    virtual std::optional<T> getById(int64_t id) = 0;
    virtual std::vector<T> getAll() = 0;
    virtual T save(T& entity) = 0;
    virtual bool deleteById(int64_t id) = 0;
    virtual int64_t count() = 0;

    // Paginated list with filtering
    std::vector<T> getList(const QueryFilter& filter) {
        auto all = getAll();
        std::vector<T> result;

        // Filter
        for (auto& entity : all) {
            if (filter.matches(entity)) {
                result.push_back(entity);
            }
        }

        // Sort
        const auto& sortProps = filter.getSortProperties();
        if (!sortProps.empty()) {
            std::sort(result.begin(), result.end(), [&](const T& a, const T& b) {
                for (const auto& sp : sortProps) {
                    int cmp = compareProperty(a, b, sp.property);
                    if (cmp != 0) return sp.ascending ? (cmp < 0) : (cmp > 0);
                }
                return false;
            });
        }

        // Paginate
        int first = filter.getFirstResult();
        int max = filter.getMaxRows();
        if (first > 0 && first < static_cast<int>(result.size()))
            result.erase(result.begin(), result.begin() + first);
        if (max > 0 && static_cast<int>(result.size()) > max)
            result.resize(max);

        return result;
    }

    int64_t getCount(const QueryFilter& filter) {
        auto all = getAll();
        return std::count_if(all.begin(), all.end(), [&](const T& e) { return filter.matches(e); });
    }

    // Save with history tracking
    T saveWithHistory(T& entity, const std::string& entityType, int64_t userId=-1, const std::string& comment="") {
        auto old = getById(entity.id);
        bool isNew = !old.has_value();
        if (!isNew) {
            detectChanges(*old, entity, entityType, userId, comment);
        }
        entity.lastUpdate = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        if (isNew) entity.created = entity.lastUpdate;
        return save(entity);
    }

protected:
    void* storage_ = nullptr;

    // Property comparison for sorting
    template<typename U = T>
    static int compareProperty(const U& a, const U& b, const std::string& prop) {
        if (prop == "id") return a.id < b.id ? -1 : (a.id > b.id ? 1 : 0);
        if constexpr (requires { a.title; })
            if (prop == "title") return a.title.compare(b.title);
        if constexpr (requires { a.name; })
            if (prop == "name") return a.name.compare(b.name);
        if constexpr (requires { a.created; })
            if (prop == "created") return a.created < b.created ? -1 : (a.created > b.created ? 1 : 0);
        if constexpr (requires { a.lastUpdate; })
            if (prop == "lastUpdate") return a.lastUpdate < b.lastUpdate ? -1 : (a.lastUpdate > b.lastUpdate ? 1 : 0);
        return 0;
    }

    // Detect changes for history
    template<typename U = T>
    static void detectChanges(const U& oldEntity, const U& newEntity,
                               const std::string& entityType, int64_t userId, const std::string& comment) {
        std::map<std::string, std::pair<std::string, std::string>> changes;
        compareFields("id", std::to_string(oldEntity.id), std::to_string(newEntity.id), changes);
        if constexpr (requires { oldEntity.title; newEntity.title; })
            compareFields("title", oldEntity.title, newEntity.title, changes);
        if constexpr (requires { oldEntity.description; newEntity.description; })
            compareFields("description", oldEntity.description, newEntity.description, changes);
        if constexpr (requires { oldEntity.status; newEntity.status; })
            compareFields("status", oldEntity.status, newEntity.status, changes);
        if constexpr (requires { oldEntity.deleted; newEntity.deleted; })
            compareFields("deleted", oldEntity.deleted ? "true" : "false", newEntity.deleted ? "true" : "false", changes);

        for (auto& [prop, vals] : changes) {
            HistoryService::recordChange(oldEntity.id, entityType, prop, vals.first, vals.second, userId, comment);
        }
    }

    static void compareFields(const std::string& name, const std::string& oldVal,
                               const std::string& newVal,
                               std::map<std::string, std::pair<std::string, std::string>>& changes) {
        if (oldVal != newVal) changes[name] = {oldVal, newVal};
    }
};

} // namespace org::projectforge::framework::persistence
