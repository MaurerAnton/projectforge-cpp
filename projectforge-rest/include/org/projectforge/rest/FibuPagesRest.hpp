// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include <org/projectforge/rest/RestController.hpp>
#include <org/projectforge/rest/JsonSerializer.hpp>
#include <org/projectforge/business/KontoDao.hpp>
#include <org/projectforge/business/RechnungDao.hpp>
#include <org/projectforge/business/AuftragDao.hpp>
#include <drogon/HttpController.h>
#include <memory>
#include <cstdint>

namespace org::projectforge::rest {

class FibuPagesRest : public RestController {
public:
    FibuPagesRest(std::shared_ptr<org::projectforge::business::fibu::KontoDao> kontoDao);

    // === Konto (accounts) endpoints ===
    void listKontos(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void getKonto(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void createKonto(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void updateKonto(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void removeKonto(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void searchKontos(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void bankAccounts(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void updateBalance(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);

    // === Buchungssatz (booking entries) endpoints ===
    void listBuchungen(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void getBuchung(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void createBuchung(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void reverseBuchung(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void buchungenByDateRange(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

    // === Reports ===
    void kontenstand(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void bilanz(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void guv(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void datevExport(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void exportFibu(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

private:
    std::shared_ptr<org::projectforge::business::fibu::KontoDao> kontoDao_;
    json kontoToApiJson(const org::projectforge::business::fibu::Konto& k) const;
    json buchungToApiJson(const org::projectforge::business::fibu::Buchungssatz& b) const;
};

class RechnungPagesRest : public RestController {
public:
    RechnungPagesRest(std::shared_ptr<org::projectforge::business::fibu::RechnungDao> rechnungDao);

    // GET /api/v1/rechnung
    void list(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/rechnung/:id
    void get(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/rechnung
    void create(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // PUT /api/v1/rechnung/:id
    void update(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // DELETE /api/v1/rechnung/:id
    void remove(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // PUT /api/v1/rechnung/:id/send
    void markSent(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // PUT /api/v1/rechnung/:id/pay
    void markPaid(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // PUT /api/v1/rechnung/:id/cancel
    void markCancelled(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // GET /api/v1/rechnung/:id/positions
    void getPositions(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/rechnung/:id/positions
    void addPosition(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // PUT /api/v1/rechnung/:id/positions/:posId
    void updatePosition(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id, int64_t posId);
    // DELETE /api/v1/rechnung/:id/positions/:posId
    void removePosition(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id, int64_t posId);
    // POST /api/v1/rechnung/:id/reorder-positions
    void reorderPositions(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // POST /api/v1/rechnung/:id/recalculate
    void recalculate(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    // GET /api/v1/rechnung/overdue
    void overdue(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/rechnung/stats
    void stats(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/rechnung/next-number
    void nextNumber(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    // GET /api/v1/rechnung/export
    void exportRechnungen(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

private:
    std::shared_ptr<org::projectforge::business::fibu::RechnungDao> rechnungDao_;
    json rechnungToApiJson(const org::projectforge::business::fibu::Rechnung& r) const;
    json positionToApiJson(const org::projectforge::business::fibu::RechnungPosition& p) const;
};

class KontoPagesRest : public RestController {
public:
    KontoPagesRest(std::shared_ptr<org::projectforge::business::fibu::KontoDao> kontoDao);

    void list(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void get(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void create(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void update(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void remove(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void byType(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void byCategory(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void bankAccounts(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void getBuchungen(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void getBilanz(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void getGuV(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void exportKontos(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

private:
    std::shared_ptr<org::projectforge::business::fibu::KontoDao> kontoDao_;
};

class AuftragPagesRest : public RestController {
public:
    AuftragPagesRest(std::shared_ptr<org::projectforge::business::fibu::AuftragDao> auftragDao);

    void list(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void get(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void create(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void update(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void remove(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void byStatus(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void byKunde(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void confirm(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void complete(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void cancel(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void getPositionen(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void addPosition(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void updatePosition(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id, int64_t posId);
    void removePosition(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id, int64_t posId);
    void recalculate(const drogon::HttpRequestPtr& req, HttpCallback&& callback, int64_t id);
    void nextNumber(const drogon::HttpRequestPtr& req, HttpCallback&& callback);
    void exportAuftraege(const drogon::HttpRequestPtr& req, HttpCallback&& callback);

private:
    std::shared_ptr<org::projectforge::business::fibu::AuftragDao> auftragDao_;
};

} // namespace org::projectforge::rest
