#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>
#include <cstdint>

namespace org::projectforge::business::fibu {

struct Rechnung {
    int64_t id = 0;
    std::string number; // invoice number
    int64_t customer_id = 0;
    int64_t contact_id = 0;
    std::string subject;
    int64_t date = 0;
    int64_t due_date = 0;
    int64_t delivery_date = 0;
    int64_t payment_date = 0;
    std::string status; // DRAFT, SENT, PAID, CANCELLED, OVERDUE
    std::string type; // INCOMING, OUTGOING
    double net_amount = 0.0;
    double gross_amount = 0.0;
    double vat_amount = 0.0;
    double vat_rate = 19.0;
    std::string currency = "EUR";
    std::string payment_method;
    std::string payment_terms;
    std::string comment;
    std::string header_text;
    std::string footer_text;
    int64_t created_at = 0;
    int64_t updated_at = 0;
    int64_t created_by = 0;
    int64_t kost2_id = 0;
    int64_t project_id = 0;
    int64_t auftrag_id = 0;
    std::string fibu_account;
    bool exported = false;
    int64_t exported_date = 0;
};

inline auto make_rechnung_table() {
    using namespace sqlite_orm;
    return make_table("t_rechnung",
        make_column("id", &Rechnung::id, primary_key().autoincrement()),
        make_column("number", &Rechnung::number),
        make_column("customer_id", &Rechnung::customer_id),
        make_column("contact_id", &Rechnung::contact_id),
        make_column("subject", &Rechnung::subject),
        make_column("date", &Rechnung::date),
        make_column("due_date", &Rechnung::due_date),
        make_column("delivery_date", &Rechnung::delivery_date),
        make_column("payment_date", &Rechnung::payment_date),
        make_column("status", &Rechnung::status),
        make_column("type", &Rechnung::type),
        make_column("net_amount", &Rechnung::net_amount),
        make_column("gross_amount", &Rechnung::gross_amount),
        make_column("vat_amount", &Rechnung::vat_amount),
        make_column("vat_rate", &Rechnung::vat_rate),
        make_column("currency", &Rechnung::currency),
        make_column("payment_method", &Rechnung::payment_method),
        make_column("payment_terms", &Rechnung::payment_terms),
        make_column("comment", &Rechnung::comment),
        make_column("header_text", &Rechnung::header_text),
        make_column("footer_text", &Rechnung::footer_text),
        make_column("created_at", &Rechnung::created_at),
        make_column("updated_at", &Rechnung::updated_at),
        make_column("created_by", &Rechnung::created_by),
        make_column("kost2_id", &Rechnung::kost2_id),
        make_column("project_id", &Rechnung::project_id),
        make_column("auftrag_id", &Rechnung::auftrag_id),
        make_column("fibu_account", &Rechnung::fibu_account),
        make_column("exported", &Rechnung::exported),
        make_column("exported_date", &Rechnung::exported_date));
}

struct RechnungPosition {
    int64_t id = 0;
    int64_t rechnung_id = 0;
    int32_t position_number = 0;
    std::string title;
    std::string description;
    double quantity = 1.0;
    std::string unit;
    double unit_price = 0.0;
    double net_amount = 0.0;
    double gross_amount = 0.0;
    double vat_amount = 0.0;
    double vat_rate = 19.0;
    int64_t task_id = 0;
    int64_t timesheet_id = 0;
    int32_t order_position = 0;
};

inline auto make_rechnung_position_table() {
    using namespace sqlite_orm;
    return make_table("t_rechnung_position",
        make_column("id", &RechnungPosition::id, primary_key().autoincrement()),
        make_column("rechnung_id", &RechnungPosition::rechnung_id),
        make_column("position_number", &RechnungPosition::position_number),
        make_column("title", &RechnungPosition::title),
        make_column("description", &RechnungPosition::description),
        make_column("quantity", &RechnungPosition::quantity),
        make_column("unit", &RechnungPosition::unit),
        make_column("unit_price", &RechnungPosition::unit_price),
        make_column("net_amount", &RechnungPosition::net_amount),
        make_column("gross_amount", &RechnungPosition::gross_amount),
        make_column("vat_amount", &RechnungPosition::vat_amount),
        make_column("vat_rate", &RechnungPosition::vat_rate),
        make_column("task_id", &RechnungPosition::task_id),
        make_column("timesheet_id", &RechnungPosition::timesheet_id),
        make_column("order_position", &RechnungPosition::order_position));
}

class RechnungDao : public BaseDao<Rechnung> {
public:
    explicit RechnungDao(std::shared_ptr<sqlite_orm::database> db);

    std::vector<Rechnung> findByCustomer(int64_t customerId) const;
    std::vector<Rechnung> findByStatus(const std::string& status) const;
    std::vector<Rechnung> findByType(const std::string& type) const;
    std::vector<Rechnung> findByDateRange(int64_t from, int64_t to) const;
    std::vector<Rechnung> findByProject(int64_t projectId) const;
    std::vector<Rechnung> findOverdue(int64_t now) const;
    std::vector<Rechnung> findUnpaid() const;
    std::vector<Rechnung> search(const std::string& query) const;
    std::optional<Rechnung> findByNumber(const std::string& number) const;

    std::string generateNextNumber(const std::string& type, int32_t year);

    bool markSent(int64_t rechnungId, int64_t timestamp);
    bool markPaid(int64_t rechnungId, int64_t timestamp);
    bool markCancelled(int64_t rechnungId);
    bool markExported(int64_t rechnungId, int64_t timestamp);

    // Positions
    std::vector<RechnungPosition> getPositions(int64_t rechnungId) const;
    RechnungPosition addPosition(const RechnungPosition& pos);
    RechnungPosition updatePosition(const RechnungPosition& pos);
    bool removePosition(int64_t positionId);
    bool reorderPositions(int64_t rechnungId, const std::vector<int64_t>& positionIds);

    // Calculations
    void recalculateTotals(int64_t rechnungId);
    double calculateVat(double netAmount, double vatRate) const;

    // Stats
    struct RevenueStats {
        double total_net = 0.0;
        double total_gross = 0.0;
        double total_vat = 0.0;
        size_t invoice_count = 0;
    };
    RevenueStats getRevenueStats(int64_t from, int64_t to) const;
    RevenueStats getRevenueByCustomer(int64_t customerId, int64_t from, int64_t to) const;

    json toJson(const Rechnung& rechnung) const override;
    Rechnung fromJson(const json& j) const override;
};

} // namespace org::projectforge::business::fibu
