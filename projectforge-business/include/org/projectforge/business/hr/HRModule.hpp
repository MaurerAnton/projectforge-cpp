// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "org/projectforge/business/BaseDao.hpp"
#include <string>
#include <vector>
#include <algorithm>

namespace org::projectforge::business::hr {

struct HRPlanningEntity {
    DECLARE_ENTITY_FIELDS();
    int64_t userId = -1;
    int64_t plannedHours = 0;
    int64_t actualHours = 0;
    int64_t startDate = 0;
    int64_t endDate = 0;
    std::string description;
    int64_t projectId = -1;
    int64_t taskId = -1;
    std::string status = "PLANNED";
    nlohmann::json toJson() const {
        nlohmann::json j; JSON_ENTITY_BASE(j);
        if(userId>=0)j["userId"]=userId;
        j["plannedHours"]=plannedHours; j["actualHours"]=actualHours;
        if(startDate>0)j["startDate"]=startDate;
        if(endDate>0)j["endDate"]=endDate;
        if(!description.empty())j["description"]=description;
        if(projectId>=0)j["projectId"]=projectId;
        if(taskId>=0)j["taskId"]=taskId;
        j["status"]=status;
        return j;
    }
};

class HRPlanningDao : public BaseDao<HRPlanningEntity> {
public:
    explicit HRPlanningDao(Storage& storage) : BaseDao<HRPlanningEntity>(storage) {}
    std::vector<HRPlanningEntity> getByUser(int64_t uid) {
        auto all = getAll(); std::vector<HRPlanningEntity> r;
        for(auto& p : all) if(!p.deleted && p.userId==uid) r.push_back(p);
        return r;
    }
    std::vector<HRPlanningEntity> getByProject(int64_t pid) {
        auto all = getAll(); std::vector<HRPlanningEntity> r;
        for(auto& p : all) if(!p.deleted && p.projectId==pid) r.push_back(p);
        return r;
    }
    std::vector<HRPlanningEntity> getByDateRange(int64_t s, int64_t e) {
        auto all = getAll(); std::vector<HRPlanningEntity> r;
        for(auto& p : all) if(!p.deleted && p.startDate<=e && p.endDate>=s) r.push_back(p);
        return r;
    }
    int64_t getTotalPlannedHours(int64_t uid, int64_t start=0, int64_t end=0) {
        auto plans = getByUser(uid); int64_t total=0;
        for(auto& p : plans) {
            if(start>0 && p.startDate<start) continue;
            if(end>0 && p.endDate>end) continue;
            total+=p.plannedHours;
        }
        return total;
    }
    int64_t getTotalActualHours(int64_t uid, int64_t start=0, int64_t end=0) {
        auto plans = getByUser(uid); int64_t total=0;
        for(auto& p : plans) {
            if(start>0 && p.startDate<start) continue;
            if(end>0 && p.endDate>end) continue;
            total+=p.actualHours;
        }
        return total;
    }
    double getUtilization(int64_t uid) {
        int64_t planned=getTotalPlannedHours(uid), actual=getTotalActualHours(uid);
        return planned>0 ? (100.0*actual)/planned : 0.0;
    }
};

// Leave / vacation management
struct LeaveAccountEntity {
    DECLARE_ENTITY_FIELDS();
    int64_t userId = -1;
    int year = 2026;
    int totalDays = 30;
    int usedDays = 0;
    int remainingDays = 0;
    int plannedDays = 0;
    std::string leaveType = "VACATION";
};

class LeaveAccountDao : public BaseDao<LeaveAccountEntity> {
public:
    explicit LeaveAccountDao(Storage& storage) : BaseDao<LeaveAccountEntity>(storage) {}
    std::optional<LeaveAccountEntity> getByUserAndYear(int64_t uid, int y) {
        auto all = getAll();
        for(auto& l : all) if(!l.deleted && l.userId==uid && l.year==y) return l;
        return std::nullopt;
    }
    void requestLeave(int64_t uid, int days) {
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        std::tm tm = *std::localtime(reinterpret_cast<const time_t*>(&now));
        int year = tm.tm_year+1900;
        auto acc = getByUserAndYear(uid, year);
        if(acc.has_value()) { acc->plannedDays+=days; acc->remainingDays=acc->totalDays-acc->usedDays-acc->plannedDays; save(*acc); }
    }
    void approveLeave(int64_t uid, int days) {
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        std::tm tm = *std::localtime(reinterpret_cast<const time_t*>(&now));
        auto acc = getByUserAndYear(uid, tm.tm_year+1900);
        if(acc.has_value()) { acc->usedDays+=days; acc->plannedDays-=days; acc->remainingDays=acc->totalDays-acc->usedDays-acc->plannedDays; save(*acc); }
    }
};

struct VacationEntryEntity {
    DECLARE_ENTITY_FIELDS();
    int64_t userId = -1;
    int64_t startDate = 0;
    int64_t endDate = 0;
    std::string status = "REQUESTED";
    std::string comment;
    int days = 0;
    int64_t approvedBy = -1;
    int64_t substituteId = -1;
    std::string leaveType = "VACATION";
};

class VacationDao : public BaseDao<VacationEntryEntity> {
public:
    explicit VacationDao(Storage& storage) : BaseDao<VacationEntryEntity>(storage) {}
    std::vector<VacationEntryEntity> getByUser(int64_t uid) {
        auto all = getAll(); std::vector<VacationEntryEntity> r;
        for(auto& v : all) if(!v.deleted && v.userId==uid) r.push_back(v);
        return r;
    }
    std::vector<VacationEntryEntity> getByStatus(const std::string& s) {
        auto all = getAll(); std::vector<VacationEntryEntity> r;
        for(auto& v : all) if(!v.deleted && v.status==s) r.push_back(v);
        return r;
    }
    std::vector<VacationEntryEntity> getPendingApprovals(int64_t approverId) {
        auto all = getAll(); std::vector<VacationEntryEntity> r;
        for(auto& v : all) if(!v.deleted && v.status=="REQUESTED" && v.approvedBy==approverId) r.push_back(v);
        return r;
    }
    bool approve(int64_t id, int64_t approverId) {
        auto v = getById(id);
        if(!v.has_value() || v->approvedBy!=approverId) return false;
        v->status="APPROVED"; save(*v); return true;
    }
    bool reject(int64_t id, int64_t approverId) {
        auto v = getById(id);
        if(!v.has_value() || v->approvedBy!=approverId) return false;
        v->status="REJECTED"; save(*v); return true;
    }
    std::vector<VacationEntryEntity> getActiveVacations(int64_t uid = -1) {
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        auto all = getAll(); std::vector<VacationEntryEntity> r;
        for(auto& v : all) {
            if(v.deleted || v.status!="APPROVED") continue;
            if(uid>=0 && v.userId!=uid) continue;
            if(v.startDate<=now && v.endDate>=now) r.push_back(v);
        }
        return r;
    }
    int getRemainingDays(int64_t uid, int year) {
        int used=0; auto all=getByUser(uid);
        for(auto& v : all) {
            if(v.status=="APPROVED"||v.status=="REQUESTED") {
                std::tm tm = *std::localtime(reinterpret_cast<const time_t*>(&v.startDate));
                if(tm.tm_year+1900==year) used+=v.days;
            }
        }
        return 30-used;
    }
};

} // namespace
