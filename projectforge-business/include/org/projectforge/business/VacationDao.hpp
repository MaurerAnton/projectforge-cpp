#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>
#include <cstdint>

namespace org::projectforge::business::vacation {

struct Vacation {
    int64_t id = 0;
    int64_t user_id = 0;
    int64_t start_date = 0;
    int64_t end_date = 0;
    double days = 0.0;
    double half_day_begin = false;
    double half_day_end = false;
    std::string type; // URLAUB, KRANK, SONDERURLAUB, UEBERSTUNDENABBAU, GLEITZEIT
    std::string status; // REQUESTED, APPROVED, REJECTED, CANCELLED
    std::string comment;
    int64_t requested_at = 0;
    int64_t approved_at = 0;
    int64_t approved_by = 0;
    int64_t created_at = 0;
    int64_t updated_at = 0;
    int64_t substitute_user_id = 0;
    bool substitution_accepted = false;
};

inline auto make_vacation_table() {
    using namespace sqlite_orm;
    return make_table("t_vacation",
        make_column("id", &Vacation::id, primary_key().autoincrement()),
        make_column("user_id", &Vacation::user_id),
        make_column("start_date", &Vacation::start_date),
        make_column("end_date", &Vacation::end_date),
        make_column("days", &Vacation::days),
        make_column("half_day_begin", &Vacation::half_day_begin),
        make_column("half_day_end", &Vacation::half_day_end),
        make_column("type", &Vacation::type),
        make_column("status", &Vacation::status),
        make_column("comment", &Vacation::comment),
        make_column("requested_at", &Vacation::requested_at),
        make_column("approved_at", &Vacation::approved_at),
        make_column("approved_by", &Vacation::approved_by),
        make_column("created_at", &Vacation::created_at),
        make_column("updated_at", &Vacation::updated_at),
        make_column("substitute_user_id", &Vacation::substitute_user_id),
        make_column("substitution_accepted", &Vacation::substitution_accepted));
}

struct VacationAccount {
    int64_t id = 0;
    int64_t user_id = 0;
    int32_t year = 0;
    double total_days = 30.0;
    double used_days = 0.0;
    double planned_days = 0.0;
    double remaining_days_previous_year = 0.0;
    double special_days = 0.0;
    int64_t created_at = 0;
    int64_t updated_at = 0;
};

inline auto make_vacation_account_table() {
    using namespace sqlite_orm;
    return make_table("t_vacation_account",
        make_column("id", &VacationAccount::id, primary_key().autoincrement()),
        make_column("user_id", &VacationAccount::user_id),
        make_column("year", &VacationAccount::year),
        make_column("total_days", &VacationAccount::total_days),
        make_column("used_days", &VacationAccount::used_days),
        make_column("planned_days", &VacationAccount::planned_days),
        make_column("remaining_days_previous_year", &VacationAccount::remaining_days_previous_year),
        make_column("special_days", &VacationAccount::special_days),
        make_column("created_at", &VacationAccount::created_at),
        make_column("updated_at", &VacationAccount::updated_at));
}

class VacationDao : public BaseDao<Vacation> {
public:
    explicit VacationDao(std::shared_ptr<sqlite_orm::database> db);

    std::vector<Vacation> findByUser(int64_t userId) const;
    std::vector<Vacation> findByDateRange(int64_t from, int64_t to) const;
    std::vector<Vacation> findByUserAndYear(int64_t userId, int32_t year) const;
    std::vector<Vacation> findByStatus(const std::string& status) const;
    std::vector<Vacation> findPendingApprovals(int64_t approverId) const;
    std::vector<Vacation> findOverlapping(int64_t userId, int64_t start, int64_t end, int64_t excludeId = 0) const;
    std::vector<Vacation> findTeamVacations(const std::vector<int64_t>& userIds, int64_t from, int64_t to) const;

    bool requestVacation(const Vacation& vac);
    bool approveVacation(int64_t vacId, int64_t approvedBy);
    bool rejectVacation(int64_t vacId, int64_t approvedBy, const std::string& reason);
    bool cancelVacation(int64_t vacId);

    // Account
    std::optional<VacationAccount> getAccount(int64_t userId, int32_t year) const;
    VacationAccount saveAccount(const VacationAccount& account);
    double getRemainingDays(int64_t userId, int32_t year) const;
    double getTotalEntitlement(int64_t userId, int32_t year) const;
    void recalculateAccount(int64_t userId, int32_t year);

    // Statistics
    struct VacationStats {
        double total_days = 0.0;
        double used_days = 0.0;
        double planned_days = 0.0;
        double remaining_days = 0.0;
        int32_t year = 0;
    };
    VacationStats getStats(int64_t userId, int32_t year) const;

    json toJson(const Vacation& vac) const override;
    Vacation fromJson(const json& j) const override;

    bool isOverlapping(int64_t userId, int64_t start, int64_t end, int64_t excludeId = 0) const;
};

} // namespace org::projectforge::business::vacation
