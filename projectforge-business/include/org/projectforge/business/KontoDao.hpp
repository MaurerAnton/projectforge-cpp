#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>
#include <cstdint>

namespace org::projectforge::business::fibu {

struct Konto {
    int64_t id = 0;
    std::string kontonummer;
    std::string name;
    std::string description;
    std::string type; // AKTIV, PASSIV, AUFWAND, ERTRAG
    std::string category; // e.g. Bank, Kasse, Debitoren, Kreditoren
    std::string steuer_schluessel;
    double balance = 0.0;
    double opening_balance = 0.0;
    int64_t opening_balance_date = 0;
    std::string currency = "EUR";
    std::string iban;
    std::string bic;
    std::string bank_name;
    int64_t created_at = 0;
    int64_t updated_at = 0;
    bool active = true;
    bool is_bank_account = false;
    std::string datev_kontonummer;
    std::string fibu_export_category;
};

inline auto make_konto_table() {
    using namespace sqlite_orm;
    return make_table("t_konto",
        make_column("id", &Konto::id, primary_key().autoincrement()),
        make_column("kontonummer", &Konto::kontonummer),
        make_column("name", &Konto::name),
        make_column("description", &Konto::description),
        make_column("type", &Konto::type),
        make_column("category", &Konto::category),
        make_column("steuer_schluessel", &Konto::steuer_schluessel),
        make_column("balance", &Konto::balance),
        make_column("opening_balance", &Konto::opening_balance),
        make_column("opening_balance_date", &Konto::opening_balance_date),
        make_column("currency", &Konto::currency),
        make_column("iban", &Konto::iban),
        make_column("bic", &Konto::bic),
        make_column("bank_name", &Konto::bank_name),
        make_column("created_at", &Konto::created_at),
        make_column("updated_at", &Konto::updated_at),
        make_column("active", &Konto::active),
        make_column("is_bank_account", &Konto::is_bank_account),
        make_column("datev_kontonummer", &Konto::datev_kontonummer),
        make_column("fibu_export_category", &Konto::fibu_export_category));
}

struct Buchungssatz {
    int64_t id = 0;
    std::string buchungsnummer;
    int64_t buchungsdatum = 0;
    int64_t soll_konto_id = 0;
    int64_t haben_konto_id = 0;
    double betrag = 0.0;
    std::string text;
    std::string belegnummer;
    int64_t rechnung_id = 0;
    int64_t kost2_id = 0;
    int64_t created_at = 0;
    int64_t created_by = 0;
    std::string fibu_source;
};

inline auto make_buchungssatz_table() {
    using namespace sqlite_orm;
    return make_table("t_buchungssatz",
        make_column("id", &Buchungssatz::id, primary_key().autoincrement()),
        make_column("buchungsnummer", &Buchungssatz::buchungsnummer),
        make_column("buchungsdatum", &Buchungssatz::buchungsdatum),
        make_column("soll_konto_id", &Buchungssatz::soll_konto_id),
        make_column("haben_konto_id", &Buchungssatz::haben_konto_id),
        make_column("betrag", &Buchungssatz::betrag),
        make_column("text", &Buchungssatz::text),
        make_column("belegnummer", &Buchungssatz::belegnummer),
        make_column("rechnung_id", &Buchungssatz::rechnung_id),
        make_column("kost2_id", &Buchungssatz::kost2_id),
        make_column("created_at", &Buchungssatz::created_at),
        make_column("created_by", &Buchungssatz::created_by),
        make_column("fibu_source", &Buchungssatz::fibu_source));
}

class KontoDao : public BaseDao<Konto> {
public:
    explicit KontoDao(std::shared_ptr<sqlite_orm::database> db);

    std::optional<Konto> findByKontonummer(const std::string& nummer) const;
    std::vector<Konto> findByType(const std::string& type) const;
    std::vector<Konto> findByCategory(const std::string& category) const;
    std::vector<Konto> findActive() const;
    std::vector<Konto> findBankAccounts() const;
    std::vector<Konto> search(const std::string& query) const;

    bool updateBalance(int64_t kontoId, double newBalance);
    bool setOpeningBalance(int64_t kontoId, double balance, int64_t date);
    double getBalance(int64_t kontoId) const;

    // Buchungssatz operations
    std::vector<Buchungssatz> getBuchungen(int64_t kontoId) const;
    std::vector<Buchungssatz> getBuchungenByDateRange(int64_t from, int64_t to) const;
    std::vector<Buchungssatz> getBuchungenByRechnung(int64_t rechnungId) const;
    Buchungssatz createBuchung(const Buchungssatz& buchung);
    bool reverseBuchung(int64_t buchungId);
    std::string generateBuchungsnummer();

    // Financial reports
    struct Kontenstand {
        double soll = 0.0;
        double haben = 0.0;
        double saldo = 0.0;
    };
    Kontenstand getKontenstand(int64_t kontoId, int64_t from, int64_t to) const;
    std::vector<Kontenstand> getBilanz(int64_t date) const;
    std::vector<Kontenstand> getGuV(int64_t from, int64_t to) const;

    // DATEV
    std::vector<Konto> getDatevExportableAccounts() const;

    json toJson(const Konto& konto) const override;
    Konto fromJson(const json& j) const override;
};

} // namespace org::projectforge::business::fibu
