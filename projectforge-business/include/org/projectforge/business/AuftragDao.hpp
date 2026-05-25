#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>
#include <cstdint>

namespace org::projectforge::business::fibu {

struct Auftrag {
    int64_t id = 0;
    std::string nummer;
    std::string titel;
    std::string beschreibung;
    int64_t kunde_id = 0;
    int64_t kontakt_id = 0;
    int64_t projekt_id = 0;
    std::string status; // ANGELEGT, BESTAETIGT, IN_BEARBEITUNG, ABGESCHLOSSEN, STORNIERT
    int64_t erstellungsdatum = 0;
    int64_t angebotsdatum = 0;
    int64_t bestaetigungsdatum = 0;
    int64_t lieferdatum = 0;
    int64_t faelligkeitsdatum = 0;
    double nettosumme = 0.0;
    double bruttosumme = 0.0;
    double mwst_summe = 0.0;
    double mwst_satz = 19.0;
    std::string waehrung = "EUR";
    std::string zahlungsbedingungen;
    std::string referenz;
    int64_t created_at = 0;
    int64_t updated_at = 0;
    int64_t created_by = 0;
    int64_t verantwortlicher_id = 0;
};

inline auto make_auftrag_table() {
    using namespace sqlite_orm;
    return make_table("t_auftrag",
        make_column("id", &Auftrag::id, primary_key().autoincrement()),
        make_column("nummer", &Auftrag::nummer),
        make_column("titel", &Auftrag::titel),
        make_column("beschreibung", &Auftrag::beschreibung),
        make_column("kunde_id", &Auftrag::kunde_id),
        make_column("kontakt_id", &Auftrag::kontakt_id),
        make_column("projekt_id", &Auftrag::projekt_id),
        make_column("status", &Auftrag::status),
        make_column("erstellungsdatum", &Auftrag::erstellungsdatum),
        make_column("angebotsdatum", &Auftrag::angebotsdatum),
        make_column("bestaetigungsdatum", &Auftrag::bestaetigungsdatum),
        make_column("lieferdatum", &Auftrag::lieferdatum),
        make_column("faelligkeitsdatum", &Auftrag::faelligkeitsdatum),
        make_column("nettosumme", &Auftrag::nettosumme),
        make_column("bruttosumme", &Auftrag::bruttosumme),
        make_column("mwst_summe", &Auftrag::mwst_summe),
        make_column("mwst_satz", &Auftrag::mwst_satz),
        make_column("waehrung", &Auftrag::waehrung),
        make_column("zahlungsbedingungen", &Auftrag::zahlungsbedingungen),
        make_column("referenz", &Auftrag::referenz),
        make_column("created_at", &Auftrag::created_at),
        make_column("updated_at", &Auftrag::updated_at),
        make_column("created_by", &Auftrag::created_by),
        make_column("verantwortlicher_id", &Auftrag::verantwortlicher_id));
}

struct AuftragPosition {
    int64_t id = 0;
    int64_t auftrag_id = 0;
    int32_t positions_nummer = 0;
    std::string titel;
    std::string beschreibung;
    double menge = 1.0;
    std::string einheit;
    double einzelpreis = 0.0;
    double nettosumme = 0.0;
    int32_t order_position = 0;
};

inline auto make_auftrag_position_table() {
    using namespace sqlite_orm;
    return make_table("t_auftrag_position",
        make_column("id", &AuftragPosition::id, primary_key().autoincrement()),
        make_column("auftrag_id", &AuftragPosition::auftrag_id),
        make_column("positions_nummer", &AuftragPosition::positions_nummer),
        make_column("titel", &AuftragPosition::titel),
        make_column("beschreibung", &AuftragPosition::beschreibung),
        make_column("menge", &AuftragPosition::menge),
        make_column("einheit", &AuftragPosition::einheit),
        make_column("einzelpreis", &AuftragPosition::einzelpreis),
        make_column("nettosumme", &AuftragPosition::nettosumme),
        make_column("order_position", &AuftragPosition::order_position));
}

class AuftragDao : public BaseDao<Auftrag> {
public:
    explicit AuftragDao(std::shared_ptr<sqlite_orm::database> db);

    std::vector<Auftrag> findByKunde(int64_t kundeId) const;
    std::vector<Auftrag> findByStatus(const std::string& status) const;
    std::vector<Auftrag> findByProjekt(int64_t projektId) const;
    std::vector<Auftrag> findByVerantwortlicher(int64_t userId) const;
    std::vector<Auftrag> findActive() const;
    std::vector<Auftrag> search(const std::string& query) const;
    std::optional<Auftrag> findByNummer(const std::string& nummer) const;

    std::string generateNextNummer();

    bool setStatus(int64_t auftragId, const std::string& newStatus);
    bool confirmAuftrag(int64_t auftragId, int64_t timestamp);
    bool completeAuftrag(int64_t auftragId, int64_t timestamp);
    bool cancelAuftrag(int64_t auftragId);

    // Positions
    std::vector<AuftragPosition> getPositionen(int64_t auftragId) const;
    AuftragPosition addPosition(const AuftragPosition& pos);
    AuftragPosition updatePosition(const AuftragPosition& pos);
    bool removePosition(int64_t positionId);
    bool reorderPositionen(int64_t auftragId, const std::vector<int64_t>& positionIds);
    void recalculateTotals(int64_t auftragId);

    json toJson(const Auftrag& auftrag) const override;
    Auftrag fromJson(const json& j) const override;
};

} // namespace org::projectforge::business::fibu
