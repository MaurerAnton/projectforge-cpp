#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>
#include <cstdint>

namespace org::projectforge::business::fibu {

struct Kost2 {
    int64_t id = 0;
    std::string nummer;
    std::string name;
    std::string beschreibung;
    int64_t parent_kost2_id = 0;
    std::string kost2_art; // PROJEKT, KOSTENSTELLE, etc.
    bool aktiv = true;
    bool fakturierbar = true;
    int64_t created_at = 0;
    int64_t updated_at = 0;
    std::string nummernkreis;
};

inline auto make_kost2_table() {
    using namespace sqlite_orm;
    return make_table("t_kost2",
        make_column("id", &Kost2::id, primary_key().autoincrement()),
        make_column("nummer", &Kost2::nummer),
        make_column("name", &Kost2::name),
        make_column("beschreibung", &Kost2::beschreibung),
        make_column("parent_kost2_id", &Kost2::parent_kost2_id),
        make_column("kost2_art", &Kost2::kost2_art),
        make_column("aktiv", &Kost2::aktiv),
        make_column("fakturierbar", &Kost2::fakturierbar),
        make_column("created_at", &Kost2::created_at),
        make_column("updated_at", &Kost2::updated_at),
        make_column("nummernkreis", &Kost2::nummernkreis));
}

class KostDao : public BaseDao<Kost2> {
public:
    explicit KostDao(std::shared_ptr<sqlite_orm::database> db);

    std::optional<Kost2> findByNummer(const std::string& nummer) const;
    std::vector<Kost2> findByParent(int64_t parentId) const;
    std::vector<Kost2> findByKostArt(const std::string& art) const;
    std::vector<Kost2> findActive() const;
    std::vector<Kost2> findFakturierbar() const;
    std::vector<Kost2> search(const std::string& query) const;
    std::vector<Kost2> getRoots() const;

    std::string buildKostPath(int64_t kost2Id) const;
    std::vector<Kost2> getChildren(int64_t parentId) const;
    std::vector<int64_t> getDescendantIds(int64_t parentId) const;

    json toJson(const Kost2& kost) const override;
    Kost2 fromJson(const json& j) const override;
};

} // namespace org::projectforge::business::fibu
