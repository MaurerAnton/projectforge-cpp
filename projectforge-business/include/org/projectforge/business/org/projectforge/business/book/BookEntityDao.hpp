// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "org/projectforge/business/BaseDao.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <sstream>
#include <nlohmann/json.hpp>

namespace org::projectforge::business::book {

struct BookEntity {
    DECLARE_ENTITY_FIELDS();
    std::string title;
    std::string author;
    std::string isbn;
    std::string description;
    int year = 2026;
    int pages = 0;
    std::string publisher;
    std::string category;
    int rating = 0;
    bool available = true;

    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        toJsonImpl(j);
        return j;
    }
    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        fromJsonImpl(j);
    }
private:
    void toJsonImpl(nlohmann::json& j) const;
    void fromJsonImpl(const nlohmann::json& j);
};

class BookDao : public BaseDao<BookEntity> {
public:
    explicit BookDao() {}
    std::vector<BookEntity> getRecent(int limit=20) {
        auto all = getAll();
        std::sort(all.begin(), all.end(), [](auto& a, auto& b){ return a.lastUpdate > b.lastUpdate; });
        if ((int)all.size()>limit) all.resize(limit);
        return all;
    }
    std::vector<BookEntity> search(const std::string& q, int limit=100) {
        auto all = getAll(); std::vector<BookEntity> r;
        std::string lower=q; std::transform(lower.begin(),lower.end(),lower.begin(),::tolower);
        for(auto& e : all) {
            if(e.deleted) continue;
            if(searchMatch(e,lower)) { r.push_back(e); if((int)r.size()>=limit) break; }
        }
        return r;
    }
    std::vector<BookEntity> getByAuthor(const std::string& author) {
        auto all = getAll(); std::vector<BookEntity> r;
        for(auto& b : all) if(!b.deleted && b.author==author) r.push_back(b);
        return r;
    }
    std::vector<BookEntity> getByCategory(const std::string& cat) {
        auto all = getAll(); std::vector<BookEntity> r;
        for(auto& b : all) if(!b.deleted && b.category==cat) r.push_back(b);
        return r;
    }
    std::vector<BookEntity> getAvailableBooks() {
        auto all = getAll(); std::vector<BookEntity> r;
        for(auto& b : all) if(!b.deleted && b.available) r.push_back(b);
        return r;
    }
protected:
    bool searchMatch(const BookEntity& e, const std::string& q);
};

} // namespace
