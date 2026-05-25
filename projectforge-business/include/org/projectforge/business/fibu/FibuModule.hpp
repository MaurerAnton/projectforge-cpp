// ProjectForge C++ port — GPL v3 — www.projectforge.org — namespace org::projectforge::business::fibu
#pragma once

#include "org/projectforge/business/BaseDao.hpp"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <chrono>

namespace org::projectforge::business::fibu {

// ============================================================================
// ENUMS AND CONSTANTS
// ============================================================================

namespace constants {
    constexpr double DEFAULT_VAT_RATE = 19.0;
    constexpr double REDUCED_VAT_RATE = 7.0;
    constexpr const char* STATUS_NEW = "NEW";
    constexpr const char* STATUS_OPEN = "OPEN";
    constexpr const char* STATUS_PAID = "PAID";
    constexpr const char* STATUS_CANCELLED = "CANCELLED";
    constexpr const char* STATUS_IN_PROGRESS = "IN_PROGRESS";
    constexpr const char* STATUS_DELIVERED = "DELIVERED";
    constexpr const char* STATUS_INVOICED = "INVOICED";
    constexpr const char* TYPE_INCOMING = "INCOMING";
    constexpr const char* TYPE_OUTGOING = "OUTGOING";
    constexpr const char* PAYMENT_BANK_TRANSFER = "BANK_TRANSFER";
    constexpr const char* PAYMENT_DIRECT_DEBIT = "DIRECT_DEBIT";
    constexpr const char* PAYMENT_CASH = "CASH";
    constexpr const char* PAYMENT_CREDIT_CARD = "CREDIT_CARD";
    constexpr const char* PAYMENT_PAYPAL = "PAYPAL";
    constexpr const char* VAT_FULL = "FULL";
    constexpr const char* VAT_REDUCED = "REDUCED";
    constexpr const char* VAT_NONE = "NONE";

    std::vector<std::string> paymentMethods() {
        return {"BANK_TRANSFER","DIRECT_DEBIT","CASH","CREDIT_CARD","PAYPAL"};
    }
    std::vector<std::string> vatTypes() { return {"FULL","REDUCED","NONE"}; }
    std::vector<std::string> invoiceStatuses() { return {"NEW","OPEN","PAID","CANCELLED"}; }
}

// ============================================================================
// KONTO (ACCOUNT) ENTITY
// ============================================================================
struct KontoEntity {
    DECLARE_ENTITY_FIELDS();
    int number = 0;
    std::string name;
    std::string description;
    std::string type; // AKTIVA, PASSIVA, AUFWAND, ERTRAG
    std::string category;
    int64_t parentKontoId = -1;
    bool active = true;
    double balance = 0.0;
    double budget = 0.0;

    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        j["number"] = number; j["name"] = name;
        if (!description.empty()) j["description"] = description;
        j["type"] = type;
        if (!category.empty()) j["category"] = category;
        if (parentKontoId >= 0) j["parentKontoId"] = parentKontoId;
        j["active"] = active; j["balance"] = balance;
        if (budget > 0) j["budget"] = budget;
        return j;
    }
    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        if (j.contains("number")) number = j["number"];
        if (j.contains("name")) name = j["name"];
        if (j.contains("description")) description = j["description"];
        if (j.contains("type")) type = j["type"];
        if (j.contains("category")) category = j["category"];
        if (j.contains("parentKontoId")) parentKontoId = j["parentKontoId"];
        if (j.contains("active")) active = j["active"];
        if (j.contains("balance")) balance = j["balance"];
        if (j.contains("budget")) budget = j["budget"];
    }
};

class KontoDao : public BaseDao<KontoEntity> {
public:
    explicit KontoDao(Storage& storage) : BaseDao<KontoEntity>(storage) {}

    std::vector<KontoEntity> getByType(const std::string& type) {
        auto all = getAll();
        std::vector<KontoEntity> r;
        std::copy_if(all.begin(), all.end(), std::back_inserter(r), [&](const auto& k) {
            return k.type == type && !k.deleted;
        });
        return r;
    }

    std::vector<KontoEntity> getActiveKontos() {
        auto all = getAll();
        std::vector<KontoEntity> r;
        std::copy_if(all.begin(), all.end(), std::back_inserter(r), [](const auto& k) {
            return k.active && !k.deleted;
        });
        return r;
    }

    std::optional<KontoEntity> findByNumber(int number) {
        auto all = getAll();
        for (auto& k : all) {
            if (k.number == number && !k.deleted) return k;
        }
        return std::nullopt;
    }

    std::vector<KontoEntity> getChildren(int64_t parentId) {
        auto all = getAll();
        std::vector<KontoEntity> r;
        for (auto& k : all) {
            if (k.parentKontoId == parentId && !k.deleted) r.push_back(k);
        }
        return r;
    }

    void updateBalance(int64_t kontoId, double amount) {
        auto k = getById(kontoId);
        if (k.has_value()) { k->balance += amount; save(*k); }
    }

    std::vector<KontoEntity> searchKontos(const std::string& query) {
        auto all = getActiveKontos();
        std::vector<KontoEntity> r;
        std::string q = query;
        std::transform(q.begin(), q.end(), q.begin(), ::tolower);
        for (auto& k : all) {
            std::string n = k.name;
            std::transform(n.begin(), n.end(), n.begin(), ::tolower);
            if (n.find(q) != std::string::npos || std::to_string(k.number).find(query) != std::string::npos) {
                r.push_back(k);
            }
        }
        return r;
    }

    double getTotalBalance(const std::string& type = "") {
        auto kontos = type.empty() ? getActiveKontos() : getByType(type);
        double total = 0;
        for (auto& k : kontos) total += k.balance;
        return total;
    }
};

// ============================================================================
// KOST (COST CENTER) ENTITY
// ============================================================================
struct KostEntity {
    DECLARE_ENTITY_FIELDS();
    int number = 0;
    std::string name;
    std::string description;
    int64_t kost1Id = -1;
    std::string type;

    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        j["number"] = number; j["name"] = name;
        if (!description.empty()) j["description"] = description;
        if (kost1Id >= 0) j["kost1Id"] = kost1Id;
        if (!type.empty()) j["type"] = type;
        return j;
    }
    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        if (j.contains("number")) number = j["number"];
        if (j.contains("name")) name = j["name"];
        if (j.contains("kost1Id")) kost1Id = j["kost1Id"];
    }
};

class KostDao : public BaseDao<KostEntity> {
public:
    explicit KostDao(Storage& storage) : BaseDao<KostEntity>(storage) {}
    std::vector<KostEntity> getActiveKosts() {
        auto all = getAll();
        std::vector<KostEntity> r;
        std::copy_if(all.begin(), all.end(), std::back_inserter(r), [](const auto& k) { return !k.deleted; });
        return r;
    }
    std::optional<KostEntity> findByNumber(int n) {
        auto all = getAll();
        for (auto& k : all) if (k.number == n && !k.deleted) return k;
        return std::nullopt;
    }
    std::vector<KostEntity> getChildren(int64_t parentId) {
        auto all = getAll();
        std::vector<KostEntity> r;
        for (auto& k : all) if (k.kost1Id == parentId && !k.deleted) r.push_back(k);
        return r;
    }
};

// ============================================================================
// RECHNUNG (INVOICE) ENTITY
// ============================================================================
struct RechnungPosition {
    int number = 0;
    std::string text;
    double netAmount = 0.0;
    std::string vatType = "FULL";
    double quantity = 1.0;
    double unitPrice = 0.0;
    int64_t kost2Id = -1;

    double getVatRate() const {
        if (vatType == "FULL") return constants::DEFAULT_VAT_RATE;
        if (vatType == "REDUCED") return constants::REDUCED_VAT_RATE;
        return 0.0;
    }
    double getVatAmount() const { return netAmount * getVatRate() / 100.0; }
    double getGrossAmount() const { return netAmount + getVatAmount(); }

    nlohmann::json toJson() const {
        return {{"number",number},{"text",text},{"netAmount",netAmount},
                {"vatType",vatType},{"quantity",quantity},{"unitPrice",unitPrice},
                {"vatRate",getVatRate()},{"grossAmount",getGrossAmount()}};
    }
};

struct RechnungEntity {
    DECLARE_ENTITY_FIELDS();
    int number = 0;
    std::string subject;
    std::string status = "NEW";
    std::string type = "OUTGOING";
    int64_t customerId = -1;
    int64_t contactPersonId = -1;
    int64_t projectId = -1;
    int64_t date = 0;
    int64_t dueDate = 0;
    int64_t paymentDate = 0;
    int64_t deliveryDate = 0;
    std::string paymentType = "BANK_TRANSFER";
    std::string currency = "EUR";
    double discountPercent = 0.0;
    int discountDays = 0;
    double netSum = 0.0;
    double vatSum = 0.0;
    double grossSum = 0.0;
    std::string comment;
    std::string customerRef1;
    std::string customerRef2;
    std::vector<RechnungPosition> positions;
    std::string paymentInfo;
    int64_t kontoId = -1;

    void recalculate() {
        netSum = 0; vatSum = 0;
        for (auto& p : positions) {
            p.netAmount = p.quantity * p.unitPrice;
            netSum += p.netAmount;
            vatSum += p.getVatAmount();
        }
        grossSum = netSum + vatSum;
    }

    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        j["number"] = number;
        if (!subject.empty()) j["subject"] = subject;
        j["status"] = status; j["type"] = type;
        if (customerId >= 0) j["customerId"] = customerId;
        if (contactPersonId >= 0) j["contactPersonId"] = contactPersonId;
        if (projectId >= 0) j["projectId"] = projectId;
        if (date > 0) j["date"] = date;
        if (dueDate > 0) j["dueDate"] = dueDate;
        if (paymentDate > 0) j["paymentDate"] = paymentDate;
        if (deliveryDate > 0) j["deliveryDate"] = deliveryDate;
        j["paymentType"] = paymentType; j["currency"] = currency;
        j["discountPercent"] = discountPercent; j["discountDays"] = discountDays;
        j["netSum"] = netSum; j["vatSum"] = vatSum; j["grossSum"] = grossSum;
        if (!comment.empty()) j["comment"] = comment;
        if (!positions.empty()) {
            nlohmann::json arr = nlohmann::json::array();
            for (auto& p : positions) arr.push_back(p.toJson());
            j["positions"] = arr;
        }
        return j;
    }
    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        if (j.contains("number")) number = j["number"];
        if (j.contains("subject")) subject = j["subject"];
        if (j.contains("status")) status = j["status"];
        if (j.contains("type")) type = j["type"];
        if (j.contains("customerId")) customerId = j["customerId"];
        if (j.contains("date")) date = j["date"];
        if (j.contains("dueDate")) dueDate = j["dueDate"];
        if (j.contains("paymentDate")) paymentDate = j["paymentDate"];
        if (j.contains("paymentType")) paymentType = j["paymentType"];
        if (j.contains("netSum")) netSum = j["netSum"];
        if (j.contains("vatSum")) vatSum = j["vatSum"];
        if (j.contains("grossSum")) grossSum = j["grossSum"];
        if (j.contains("comment")) comment = j["comment"];
        if (j.contains("positions")) {
            for (auto& pj : j["positions"]) {
                RechnungPosition p;
                if (pj.contains("number")) p.number = pj["number"];
                if (pj.contains("text")) p.text = pj["text"];
                if (pj.contains("netAmount")) p.netAmount = pj["netAmount"];
                if (pj.contains("vatType")) p.vatType = pj["vatType"];
                if (pj.contains("quantity")) p.quantity = pj["quantity"];
                if (pj.contains("unitPrice")) p.unitPrice = pj["unitPrice"];
                positions.push_back(p);
            }
        }
    }
};

class RechnungDao : public BaseDao<RechnungEntity> {
public:
    explicit RechnungDao(Storage& storage) : BaseDao<RechnungEntity>(storage) {}

    std::vector<RechnungEntity> getByStatus(const std::string& status) {
        auto all = getAll();
        std::vector<RechnungEntity> r;
        for (auto& re : all) {
            if (!re.deleted && re.status == status) r.push_back(re);
        }
        return r;
    }

    std::vector<RechnungEntity> getByCustomer(int64_t customerId) {
        auto all = getAll();
        std::vector<RechnungEntity> r;
        for (auto& re : all) {
            if (!re.deleted && re.customerId == customerId) r.push_back(re);
        }
        return r;
    }

    std::vector<RechnungEntity> getByType(const std::string& type) {
        auto all = getAll();
        std::vector<RechnungEntity> r;
        for (auto& re : all) {
            if (!re.deleted && re.type == type) r.push_back(re);
        }
        return r;
    }

    std::vector<RechnungEntity> getOpenInvoices() {
        auto all = getAll();
        std::vector<RechnungEntity> r;
        for (auto& re : all) {
            if (!re.deleted && re.status != "PAID" && re.status != "CANCELLED") r.push_back(re);
        }
        return r;
    }

    std::vector<RechnungEntity> getOverdueInvoices() {
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        auto open = getOpenInvoices();
        std::vector<RechnungEntity> r;
        for (auto& re : open) {
            if (re.dueDate > 0 && re.dueDate < now) r.push_back(re);
        }
        return r;
    }

    bool markAsPaid(int64_t id, int64_t paymentDate = 0) {
        auto re = getById(id);
        if (!re.has_value()) return false;
        re->status = "PAID";
        re->paymentDate = paymentDate > 0 ? paymentDate :
            std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count();
        save(*re);
        return true;
    }

    bool cancel(int64_t id) {
        auto re = getById(id);
        if (!re.has_value() || re->status == "PAID") return false;
        re->status = "CANCELLED";
        save(*re);
        return true;
    }

    int getNextNumber() {
        auto all = getAll();
        int maxN = 0;
        for (auto& re : all) { if (re.number > maxN) maxN = re.number; }
        return maxN + 1;
    }

    std::vector<RechnungEntity> getByDateRange(int64_t from, int64_t to) {
        auto all = getAll();
        std::vector<RechnungEntity> r;
        for (auto& re : all) {
            if (!re.deleted && re.date >= from && re.date <= to) r.push_back(re);
        }
        return r;
    }

    double getTotalRevenue(int64_t fromDate = 0, int64_t toDate = 0) {
        auto invoices = fromDate > 0 ? getByDateRange(fromDate, toDate) : getAll();
        double total = 0;
        for (auto& inv : invoices) {
            if (!inv.deleted && inv.type == "OUTGOING" && inv.status == "PAID") total += inv.grossSum;
        }
        return total;
    }

    double getTotalExpenses(int64_t fromDate = 0, int64_t toDate = 0) {
        auto invoices = fromDate > 0 ? getByDateRange(fromDate, toDate) : getAll();
        double total = 0;
        for (auto& inv : invoices) {
            if (!inv.deleted && inv.type == "INCOMING" && inv.status == "PAID") total += inv.grossSum;
        }
        return total;
    }

    std::vector<RechnungEntity> getByProject(int64_t projectId) {
        auto all = getAll();
        std::vector<RechnungEntity> r;
        for (auto& re : all) {
            if (!re.deleted && re.projectId == projectId) r.push_back(re);
        }
        return r;
    }

    std::vector<RechnungEntity> searchInvoices(const std::string& query, int limit = 100) {
        auto all = getAll();
        std::vector<RechnungEntity> r;
        std::string q = query;
        std::transform(q.begin(), q.end(), q.begin(), ::tolower);
        for (auto& re : all) {
            if (re.deleted) continue;
            std::string s = re.subject;
            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
            if (s.find(q) != std::string::npos || std::to_string(re.number).find(query) != std::string::npos) {
                r.push_back(re);
                if (static_cast<int>(r.size()) >= limit) break;
            }
        }
        return r;
    }

    // Dunning / Mahnung support
    std::vector<RechnungEntity> getDunningCandidates(int daysOverdue) {
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        int64_t threshold = now - (static_cast<int64_t>(daysOverdue) * 86400000LL);
        auto overdue = getOverdueInvoices();
        std::vector<RechnungEntity> r;
        for (auto& re : overdue) {
            if (re.dueDate < threshold) r.push_back(re);
        }
        return r;
    }
};

// ============================================================================
// AUFTRAG (ORDER) ENTITY
// ============================================================================
struct AuftragPosition {
    int number = 0;
    std::string text;
    double netAmount = 0.0;
    double quantity = 1.0;
    double unitPrice = 0.0;
    std::string vatType = "FULL";

    double getVatRate() const {
        if (vatType == "FULL") return constants::DEFAULT_VAT_RATE;
        if (vatType == "REDUCED") return constants::REDUCED_VAT_RATE;
        return 0.0;
    }
    double getGrossAmount() const {
        double net = quantity * unitPrice;
        return net * (1.0 + getVatRate() / 100.0);
    }
};

struct AuftragEntity {
    DECLARE_ENTITY_FIELDS();
    int number = 0;
    std::string subject;
    std::string status = "NEW";
    std::string type = "ORDER";
    int64_t customerId = -1;
    int64_t projectId = -1;
    int64_t orderDate = 0;
    int64_t deliveryDate = 0;
    std::string reference;
    std::vector<AuftragPosition> positions;
    double netSum = 0.0;
    double grossSum = 0.0;
    std::string comment;

    void recalculate() {
        netSum = 0;
        for (auto& p : positions) {
            netSum += p.quantity * p.unitPrice;
        }
        grossSum = netSum;
        for (auto& p : positions) {
            grossSum += p.quantity * p.unitPrice * p.getVatRate() / 100.0;
        }
    }

    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        j["number"] = number;
        if (!subject.empty()) j["subject"] = subject;
        j["status"] = status; j["type"] = type;
        if (customerId >= 0) j["customerId"] = customerId;
        if (projectId >= 0) j["projectId"] = projectId;
        if (orderDate > 0) j["orderDate"] = orderDate;
        if (deliveryDate > 0) j["deliveryDate"] = deliveryDate;
        if (!reference.empty()) j["reference"] = reference;
        j["netSum"] = netSum; j["grossSum"] = grossSum;
        if (!comment.empty()) j["comment"] = comment;
        return j;
    }
    void fromJson(const nlohmann::json& j) {
        FROMJSON_ENTITY_BASE(j);
        if (j.contains("number")) number = j["number"];
        if (j.contains("subject")) subject = j["subject"];
        if (j.contains("status")) status = j["status"];
        if (j.contains("customerId")) customerId = j["customerId"];
        if (j.contains("orderDate")) orderDate = j["orderDate"];
        if (j.contains("deliveryDate")) deliveryDate = j["deliveryDate"];
        if (j.contains("netSum")) netSum = j["netSum"];
        if (j.contains("grossSum")) grossSum = j["grossSum"];
        if (j.contains("comment")) comment = j["comment"];
    }
};

class AuftragDao : public BaseDao<AuftragEntity> {
public:
    explicit AuftragDao(Storage& storage) : BaseDao<AuftragEntity>(storage) {}

    std::vector<AuftragEntity> getByStatus(const std::string& status) {
        auto all = getAll();
        std::vector<AuftragEntity> r;
        for (auto& a : all) { if (!a.deleted && a.status == status) r.push_back(a); }
        return r;
    }

    std::vector<AuftragEntity> getByCustomer(int64_t customerId) {
        auto all = getAll();
        std::vector<AuftragEntity> r;
        for (auto& a : all) { if (!a.deleted && a.customerId == customerId) r.push_back(a); }
        return r;
    }

    std::vector<AuftragEntity> getByProject(int64_t projectId) {
        auto all = getAll();
        std::vector<AuftragEntity> r;
        for (auto& a : all) { if (!a.deleted && a.projectId == projectId) r.push_back(a); }
        return r;
    }

    std::vector<AuftragEntity> getOpenOrders() {
        return getByStatus("OPEN");
    }

    bool updateStatus(int64_t id, const std::string& status) {
        auto a = getById(id);
        if (!a.has_value()) return false;
        a->status = status;
        save(*a);
        return true;
    }

    std::vector<AuftragEntity> getPendingDelivery() {
        auto all = getAll();
        std::vector<AuftragEntity> r;
        for (auto& a : all) {
            if (!a.deleted && a.status == "OPEN" && a.deliveryDate > 0) r.push_back(a);
        }
        return r;
    }

    int getNextNumber() {
        auto all = getAll();
        int maxN = 0;
        for (auto& a : all) { if (a.number > maxN) maxN = a.number; }
        return maxN + 1;
    }
};

// ============================================================================
// DATEV EXPORT SERVICE
// ============================================================================
class DatevExportService {
public:
    struct DatevBookingEntry {
        int kontoNumber = 0;
        int gegenKontoNumber = 0;
        double amount = 0.0;
        std::string belegfeld;
        int64_t datum = 0;
        std::string buchungstext;
        std::string kost1;
        std::string kost2;
        std::string umsatzsteuer;
    };

    static std::string exportToCsv(const std::vector<DatevBookingEntry>& entries) {
        std::ostringstream ss;
        // DATEV CSV header
        ss << "\\\"Umsatz (ohne Soll/Haben-Kz)\\\";\\\"Soll/Haben-Kennzeichen\\\";"
           << "\\\"WKZ Umsatz\\\";\\\"Kurs\\\";\\\"Basis-Umsatz\\\";"
           << "\\\"WKZ Basis-Umsatz\\\";\\\"Konto\\\";\\\"Gegenkonto (ohne BU-Schlussel)\\\";"
           << "\\\"BU-Schlussel\\\";\\\"Belegdatum\\\";\\\"Belegfeld 1\\\";"
           << "\\\"Belegfeld 2\\\";\\\"Skonto\\\";\\\"Buchungstext\\\";"
           << "\\\"Postensperre\\\";\\\"Diverse Adressnummer\\\";\\\"Geschaftspartnerbank\\\";"
           << "\\\"Sachverhalt\\\";\\\"Zinssperre\\\";\\\"Beleglink\\\";"
           << "\\\"Beleginfo - Art 1\\\";\\\"Beleginfo - Inhalt 1\\\";"
           << "\\\"Beleginfo - Art 2\\\";\\\"Beleginfo - Inhalt 2\\\";"
           << "\\\"Beleginfo - Art 3\\\";\\\"Beleginfo - Inhalt 3\\\";"
           << "\\\"Beleginfo - Art 4\\\";\\\"Beleginfo - Inhalt 4\\\";"
           << "\\\"Beleginfo - Art 5\\\";\\\"Beleginfo - Inhalt 5\\\";"
           << "\\\"Beleginfo - Art 6\\\";\\\"Beleginfo - Inhalt 6\\\";"
           << "\\\"Beleginfo - Art 7\\\";\\\"Beleginfo - Inhalt 7\\\";"
           << "\\\"Beleginfo - Art 8\\\";\\\"Beleginfo - Inhalt 8\\\";"
           << "\\\"KOST1 - Konto\\\";\\\"KOST2 - Konto\\\";\\\"Kost-Menge\\\";"
           << "\\\"EU-Land u. UstID\\\";\\\"EU-Steuer - Art\\\";"
           << "\\\"Sachverhalt L+L\\\";\\\"Funktionserg. - Art L+L\\\";"
           << "\\\"BU 49 Hauptfunktionstyp\\\";\\\"BU 49 Hauptfunktionsnummer\\\";"
           << "\\\"BU 49 Funktionserg. Typ\\\";\\\"Zusatzinformation - Art 1\\\";"
           << "\\\"Zusatzinformation- Inhalt 1\\\";\\\"Zusatzinformation - Art 2\\\";"
           << "\\\"Zusatzinformation- Inhalt 2\\\";\\\"Zusatzinformation - Art 3\\\";"
           << "\\\"Zusatzinformation- Inhalt 3\\\";\\\"Zusatzinformation - Art 4\\\";"
           << "\\\"Zusatzinformation- Inhalt 4\\\";\\\"Zusatzinformation - Art 5\\\";"
           << "\\\"Zusatzinformation- Inhalt 5\\\";\\\"Zusatzinformation - Art 6\\\";"
           << "\\\"Zusatzinformation- Inhalt 6\\\";\\\"Zusatzinformation - Art 7\\\";"
           << "\\\"Zusatzinformation- Inhalt 7\\\";\\\"Zusatzinformation - Art 8\\\";"
           << "\\\"Zusatzinformation- Inhalt 8\\\";\\\"Zusatzinformation - Art 9\\\";"
           << "\\\"Zusatzinformation- Inhalt 9\\\";\\\"Zusatzinformation - Art 10\\\";"
           << "\\\"Zusatzinformation- Inhalt 10\\\";\\\"Zusatzinformation - Art 11\\\";"
           << "\\\"Zusatzinformation- Inhalt 11\\\";\\\"Zusatzinformation - Art 12\\\";"
           << "\\\"Zusatzinformation- Inhalt 12\\\";\\\"Zusatzinformation - Art 13\\\";"
           << "\\\"Zusatzinformation- Inhalt 13\\\";\\\"Zusatzinformation - Art 14\\\";"
           << "\\\"Zusatzinformation- Inhalt 14\\\";\\\"Zusatzinformation - Art 15\\\";"
           << "\\\"Zusatzinformation- Inhalt 15\\\";\\\"Zusatzinformation - Art 16\\\";"
           << "\\\"Zusatzinformation- Inhalt 16\\\";\\\"Zusatzinformation - Art 17\\\";"
           << "\\\"Zusatzinformation- Inhalt 17\\\";\\\"Zusatzinformation - Art 18\\\";"
           << "\\\"Zusatzinformation- Inhalt 18\\\";\\\"Zusatzinformation - Art 19\\\";"
           << "\\\"Zusatzinformation- Inhalt 19\\\";\\\"Zusatzinformation - Art 20\\\";"
           << "\\\"Zusatzinformation- Inhalt 20\\\";\\\"Stuck\\\";\\\"Gewicht\\\";"
           << "\\\"Zahlweise\\\";\\\"Forderungsart\\\";\\\"Veranlagungsjahr\\\";"
           << "\\\"Zugeordnete Falligkeit\\\";\\\"Skontotyp\\\";\\\"Auftragsnummer\\\";"
           << "\\\"Buchungstyp\\\";\\\"Ust-Schlussel\\\";\\\"EU-Land\\\";"
           << "\\\"Sachverhalt L+L (Stapelverarbeitung)\\\";\\\"EU-Steuer - Art\\\";"
           << "\\\"Erstellungsdatum\\\";\\\"Lieferdatum\\\";\\\"Datum Festschreibung\\\"\\n";

        for (auto& e : entries) {
            ss << std::fixed << std::setprecision(2) << std::abs(e.amount) << ";"
               << (e.amount >= 0 ? "S" : "H") << ";" // Soll/Haben
               << "EUR;1.00000;"
               << std::abs(e.amount) << ";EUR;"
               << e.kontoNumber << ";"
               << e.gegenKontoNumber << ";"
               << ";;" // BU-Schlussel
               << formatDate(e.datum) << ";"
               << e.belegfeld << ";;"
               << ";;" << e.buchungstext << ";"
               << "0;;;" // Postensperre, Adressnummer, Bank
               << ";;0;;" // Sachverhalt, Zinssperre, Beleglink
               << ";;;;;;;;;;;" // Beleginfos 1-5
               << ";;;;;;;;;;;" // Beleginfos 6-8, KOST1/2, Menge
               << ";" << e.kost1 << ";" << e.kost2 << ";"
               << "1.00000;" // Kost-Menge
               << ";;" << e.umsatzsteuer << ";" // EU-Land, Steuerart
               << ";;;;;;"
               << std::endl;
        }
        return ss.str();
    }

    static std::vector<DatevBookingEntry> generateFromInvoices(
        const std::vector<RechnungEntity>& invoices, KontoDao& kontoDao) {
        std::vector<DatevBookingEntry> entries;
        for (auto& inv : invoices) {
            DatevBookingEntry entry;
            entry.amount = inv.grossSum;
            entry.kontoNumber = 1400; // Forderungen default
            entry.gegenKontoNumber = 8400; // Erlose default
            if (inv.kontoId >= 0) {
                auto k = kontoDao.getById(inv.kontoId);
                if (k.has_value()) entry.gegenKontoNumber = k->number;
            }
            entry.belegfeld = "RE" + std::to_string(inv.number);
            entry.datum = inv.date;
            entry.buchungstext = inv.subject;
            entry.umsatzsteuer = std::to_string(static_cast<int>(constants::DEFAULT_VAT_RATE));
            entries.push_back(entry);
        }
        return entries;
    }

private:
    static std::string formatDate(int64_t millis) {
        if (millis <= 0) return "";
        auto tp = std::chrono::system_clock::from_time_t(millis / 1000);
        auto tt = std::chrono::system_clock::to_time_t(tp);
        std::ostringstream ss;
        ss << std::put_time(std::localtime(&tt), "%d%m%Y");
        return ss.str();
    }
};

// ============================================================================
// SEPA XML BUILDER
// ============================================================================
class SepaXmlBuilder {
public:
    struct SepaTransfer {
        std::string messageId;
        int64_t creationDateTime = 0;
        int numTransactions = 0;
        double controlSum = 0.0;
        std::string initiatorName;
        std::string initiatorIban;
        std::string initiatorBic;

        struct Transaction {
            std::string endToEndId;
            double amount = 0.0;
            std::string currency = "EUR";
            std::string recipientName;
            std::string recipientIban;
            std::string recipientBic;
            std::string purpose;
            int64_t requestedExecutionDate = 0;
        };
        std::vector<Transaction> transactions;
    };

    static std::string buildSepaXml(const SepaTransfer& transfer) {
        std::ostringstream ss;
        ss << "<?xml version=\\\"1.0\\\" encoding=\\\"UTF-8\\\"?>\\n"
           << "<Document xmlns=\\\"urn:iso:std:iso:20022:tech:xsd:pain.001.003.03\\\"\\n"
           << "  xmlns:xsi=\\\"http://www.w3.org/2001/XMLSchema-instance\\\"\\n"
           << "  xsi:schemaLocation=\\\"urn:iso:std:iso:20022:tech:xsd:pain.001.003.03 pain.001.003.03.xsd\\\">\\n"
           << "  <CstmrCdtTrfInitn>\\n"
           << "    <GrpHdr>\\n"
           << "      <MsgId>" << transfer.messageId << "</MsgId>\\n"
           << "      <CreDtTm>" << formatIsoDateTime(transfer.creationDateTime) << "</CreDtTm>\\n"
           << "      <NbOfTxs>" << transfer.transactions.size() << "</NbOfTxs>\\n"
           << "      <CtrlSum>" << std::fixed << std::setprecision(2) << transfer.controlSum << "</CtrlSum>\\n"
           << "      <InitgPty><Nm>" << transfer.initiatorName << "</Nm></InitgPty>\\n"
           << "    </GrpHdr>\\n"
           << "    <PmtInf>\\n"
           << "      <PmtInfId>" << transfer.messageId << "-1</PmtInfId>\\n"
           << "      <PmtMtd>TRF</PmtMtd>\\n"
           << "      <NbOfTxs>" << transfer.transactions.size() << "</NbOfTxs>\\n"
           << "      <CtrlSum>" << std::fixed << std::setprecision(2) << transfer.controlSum << "</CtrlSum>\\n"
           << "      <Dbtr><Nm>" << transfer.initiatorName << "</Nm></Dbtr>\\n"
           << "      <DbtrAcct><Id><IBAN>" << transfer.initiatorIban << "</IBAN></Id></DbtrAcct>\\n"
           << "      <DbtrAgt><FinInstnId><BIC>" << transfer.initiatorBic << "</BIC></FinInstnId></DbtrAgt>\\n";

        for (size_t i = 0; i < transfer.transactions.size(); ++i) {
            auto& t = transfer.transactions[i];
            ss << "      <CdtTrfTxInf>\\n"
               << "        <PmtId><EndToEndId>" << t.endToEndId << "</EndToEndId></PmtId>\\n"
               << "        <Amt><InstdAmt Ccy=\\\"" << t.currency << "\\\">"
               << std::fixed << std::setprecision(2) << t.amount
               << "</InstdAmt></Amt>\\n"
               << "        <CdtrAgt><FinInstnId><BIC>" << t.recipientBic << "</BIC></FinInstnId></CdtrAgt>\\n"
               << "        <Cdtr><Nm>" << t.recipientName << "</Nm></Cdtr>\\n"
               << "        <CdtrAcct><Id><IBAN>" << t.recipientIban << "</IBAN></Id></CdtrAcct>\\n"
               << "        <RmtInf><Ustrd>" << t.purpose << "</Ustrd></RmtInf>\\n"
               << "      </CdtTrfTxInf>\\n";
        }

        ss << "    </PmtInf>\\n"
           << "  </CstmrCdtTrfInitn>\\n"
           << "</Document>\\n";
        return ss.str();
    }

private:
    static std::string formatIsoDateTime(int64_t millis) {
        if (millis <= 0) return "";
        auto tp = std::chrono::system_clock::from_time_t(millis / 1000);
        auto tt = std::chrono::system_clock::to_time_t(tp);
        std::ostringstream ss;
        ss << std::put_time(std::localtime(&tt), "%Y-%m-%dT%H:%M:%S");
        return ss.str();
    }
};

// ============================================================================
// FIBU SERVICE (orchestrates all fibu operations)
// ============================================================================
class FibuService {
public:
    FibuService(KontoDao& kontoDao, RechnungDao& rechnungDao, AuftragDao& auftragDao, KostDao& kostDao)
        : kontoDao_(kontoDao), rechnungDao_(rechnungDao), auftragDao_(auftragDao), kostDao_(kostDao) {}

    // Get financial overview
    nlohmann::json getFinancialOverview(int64_t fromDate = 0, int64_t toDate = 0) {
        nlohmann::json overview;
        overview["totalRevenue"] = rechnungDao_.getTotalRevenue(fromDate, toDate);
        overview["totalExpenses"] = rechnungDao_.getTotalExpenses(fromDate, toDate);
        overview["profit"] = overview["totalRevenue"].get<double>() - overview["totalExpenses"].get<double>();
        overview["openInvoices"] = rechnungDao_.getOpenInvoices().size();
        overview["overdueInvoices"] = rechnungDao_.getOverdueInvoices().size();
        overview["openOrders"] = auftragDao_.getOpenOrders().size();

        // Sum open invoice amounts
        double openAmount = 0, overdueAmount = 0;
        for (auto& inv : rechnungDao_.getOpenInvoices()) openAmount += inv.grossSum;
        for (auto& inv : rechnungDao_.getOverdueInvoices()) overdueAmount += inv.grossSum;
        overview["openAmount"] = openAmount;
        overview["overdueAmount"] = overdueAmount;

        return overview;
    }

    // Generate DATEV export
    std::string generateDatevExport(int64_t fromDate, int64_t toDate) {
        auto invoices = rechnungDao_.getByDateRange(fromDate, toDate);
        auto entries = DatevExportService::generateFromInvoices(invoices, kontoDao_);
        return DatevExportService::exportToCsv(entries);
    }

    // Generate SEPA XML for payment
    std::string generateSepaXml(const std::vector<int64_t>& invoiceIds) {
        SepaXmlBuilder::SepaTransfer transfer;
        transfer.messageId = "PF-" + std::to_string(
            std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count());
        transfer.creationDateTime = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        transfer.initiatorName = "ProjectForge";

        for (auto id : invoiceIds) {
            auto inv = rechnungDao_.getById(id);
            if (!inv.has_value()) continue;
            SepaXmlBuilder::SepaTransfer::Transaction t;
            t.endToEndId = "RE" + std::to_string(inv->number);
            t.amount = inv->grossSum;
            t.purpose = inv->subject;
            transfer.transactions.push_back(t);
        }
        transfer.controlSum = 0;
        for (auto& t : transfer.transactions) transfer.controlSum += t.amount;
        transfer.numTransactions = transfer.transactions.size();

        return SepaXmlBuilder::buildSepaXml(transfer);
    }

    // Cash flow forecast
    nlohmann::json getCashFlowForecast(int months = 6) {
        nlohmann::json forecast = nlohmann::json::array();
        int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        int64_t monthMs = 30LL * 24 * 3600 * 1000;

        for (int i = 0; i < months; ++i) {
            int64_t start = now + i * monthMs;
            int64_t end = start + monthMs;
            nlohmann::json month;
            month["month"] = i + 1;
            month["expectedRevenue"] = rechnungDao_.getTotalRevenue(start, end);
            month["expectedExpenses"] = rechnungDao_.getTotalExpenses(start, end);
            forecast.push_back(month);
        }
        return forecast;
    }

private:
    KontoDao& kontoDao_;
    RechnungDao& rechnungDao_;
    AuftragDao& auftragDao_;
    KostDao& kostDao_;
};

} // namespace org::projectforge::business::fibu
