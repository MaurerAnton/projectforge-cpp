#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>
#include <cstdint>
#include <map>

namespace org::projectforge::business::fibu {

struct DatevExportRecord {
    int64_t id = 0;
    int64_t export_run_id = 0;
    std::string record_type; // HEADER, BUCHUNG, ABSCHLUSS
    std::string content; // formatted DATEV line
    int32_t line_number = 0;
};

inline auto make_datev_export_record_table() {
    using namespace sqlite_orm;
    return make_table("t_datev_export_record",
        make_column("id", &DatevExportRecord::id, primary_key().autoincrement()),
        make_column("export_run_id", &DatevExportRecord::export_run_id),
        make_column("record_type", &DatevExportRecord::record_type),
        make_column("content", &DatevExportRecord::content),
        make_column("line_number", &DatevExportRecord::line_number));
}

struct DatevExportRun {
    int64_t id = 0;
    int64_t start_date;
    int64_t end_date;
    int64_t exported_at = 0;
    int64_t exported_by = 0;
    int32_t total_records = 0;
    std::string status; // RUNNING, COMPLETED, FAILED
};

inline auto make_datev_export_run_table() {
    using namespace sqlite_orm;
    return make_table("t_datev_export_run",
        make_column("id", &DatevExportRun::id, primary_key().autoincrement()),
        make_column("start_date", &DatevExportRun::start_date),
        make_column("end_date", &DatevExportRun::end_date),
        make_column("exported_at", &DatevExportRun::exported_at),
        make_column("exported_by", &DatevExportRun::exported_by),
        make_column("total_records", &DatevExportRun::total_records),
        make_column("status", &DatevExportRun::status));
}

class DatevDao {
public:
    explicit DatevDao(std::shared_ptr<sqlite_orm::database> db);

    // Export configuration
    struct DatevConfig {
        std::string berater_nummer;
        std::string mandanten_nummer;
        std::string buchungsstapel_name;
        std::string sachkontenlaenge = "4";
        int32_t geschaeftsjahr = 2024;
        int32_t buchungsperiode = 1;
        std::string fibu_buchungskreis;
        std::string datev_format = "EXTF"; // EXTF or CSV
    };

    DatevExportRun createExportRun(int64_t startDate, int64_t endDate, int64_t userId);
    bool generateExportRecords(int64_t exportRunId, const DatevConfig& config);
    std::string generateExportFile(int64_t exportRunId, const DatevConfig& config) const;
    std::string generateDatevHeader(const DatevConfig& config) const;
    std::string formatBuchungssatzLine(const struct Buchungssatz& bs, int32_t gegenKonto, const DatevConfig& config) const;
    std::string formatAbschlussLine(const DatevConfig& config, int32_t sollTotal, int32_t habenTotal, double summe) const;

    std::vector<DatevExportRun> getExportRuns() const;
    std::optional<DatevExportRun> getExportRun(int64_t runId) const;
    std::vector<DatevExportRecord> getExportRecords(int64_t exportRunId) const;

    bool validateDatevFormat(const std::string& line, const DatevConfig& config) const;
    std::map<std::string, std::string> parseDatevLine(const std::string& line, const DatevConfig& config) const;

private:
    std::shared_ptr<sqlite_orm::database> db_;
    std::string padField(const std::string& value, size_t length, char padChar = ' ') const;
    std::string formatNumber(double value, size_t length, int decimals = 2) const;
    static constexpr size_t DATEV_LINE_LENGTH = 500;
};

// Forward declare from KontoDao
namespace org::projectforge::business::fibu {
    struct Buchungssatz;
}

} // namespace org::projectforge::business::fibu
