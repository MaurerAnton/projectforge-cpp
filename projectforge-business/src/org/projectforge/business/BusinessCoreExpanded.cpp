// ProjectForge C++ port — GPL v3
#include "org/projectforge/business/user/UserEntity.hpp"
#include "org/projectforge/business/task/TaskDao.hpp"
#include "org/projectforge/business/timesheet/TimesheetDaoFull.hpp"
#include "org/projectforge/business/fibu/FibuModule.hpp"
#include "org/projectforge/business/address/AddressModule.hpp"
#include "org/projectforge/business/calendar/CalendarModule.hpp"
#include "org/projectforge/business/hr/HRModule.hpp"
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <random>

// ============================================================================
// ProjectForge Business — Core Algorithms and Business Rules
// ============================================================================

namespace org::projectforge::business {

// ======== WORKING TIME CALCULATOR ========
class WorkingTimeCalculator {
    int64_t workDayStartMs = 8 * 3600000LL;  // 08:00
    int64_t workDayEndMs = 17 * 3600000LL;   // 17:00
    int64_t breakDurationMs = 3600000LL;     // 1 hour lunch
    
public:
    int64_t calculateWorkingTime(int64_t startMs, int64_t stopMs) {
        if (startMs >= stopMs) return 0;
        return (stopMs - startMs) - breakDurationMs;
    }
    
    double calculateWorkingHours(int64_t seconds) {
        return static_cast<double>(seconds) / 3600.0;
    }
    
    int64_t calculateOvertime(int64_t totalSeconds, int64_t expectedPerDay = 28800LL) {
        return totalSeconds - expectedPerDay;
    }
    
    bool isWeekday(int dayOfWeek) {
        return dayOfWeek >= 1 && dayOfWeek <= 5; // Mon-Fri
    }
    
    bool isWeekend(int dayOfWeek) {
        return dayOfWeek == 0 || dayOfWeek == 6;
    }
    
    int getWorkingDaysInMonth(int year, int month) {
        int days = 0;
        int daysInMonth = 31; // Simplified
        if (month == 2) daysInMonth = 28;
        else if (month == 4 || month == 6 || month == 9 || month == 11) daysInMonth = 30;
        
        for (int d = 1; d <= daysInMonth; d++) {
            std::tm tm = {0, 0, 0, d, month-1, year-1900};
            auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
            auto tt = std::chrono::system_clock::to_time_t(tp);
            int dow = std::localtime(&tt)->tm_wday;
            if (isWeekday(dow)) days++;
        }
        return days;
    }
};

// ======== TAX CALCULATOR ========
class TaxCalculator {
    double vatRateFull = 19.0;
    double vatRateReduced = 7.0;
    
public:
    double calculateVat(double netAmount, const std::string& vatType) {
        double rate = (vatType == "REDUCED") ? vatRateReduced : vatRateFull;
        if (vatType == "NONE") rate = 0.0;
        return netAmount * rate / 100.0;
    }
    
    double calculateGross(double netAmount, const std::string& vatType) {
        return netAmount + calculateVat(netAmount, vatType);
    }
    
    double extractVatFromGross(double grossAmount, const std::string& vatType) {
        double rate = (vatType == "REDUCED") ? vatRateReduced : vatRateFull;
        if (vatType == "NONE") return 0.0;
        return grossAmount * rate / (100.0 + rate);
    }
    
    double extractNetFromGross(double grossAmount, const std::string& vatType) {
        return grossAmount - extractVatFromGross(grossAmount, vatType);
    }
    
    void setVatRates(double full, double reduced) {
        vatRateFull = full;
        vatRateReduced = reduced;
    }
};

// ======== DUNNING CALCULATOR ========
class DunningCalculator {
    int dunningLevel1Days = 15;
    int dunningLevel2Days = 30;
    int dunningLevel3Days = 45;
    double dunningFee1 = 5.0;
    double dunningFee2 = 10.0;
    double dunningFee3 = 15.0;
    double interestRate = 9.0; // Above base rate
    
public:
    struct DunningResult {
        int level = 0;
        int daysOverdue = 0;
        double dunningFee = 0.0;
        double interestAmount = 0.0;
        double totalDue = 0.0;
        
        nlohmann::json toJson() const {
            nlohmann::json j;
            j["level"]=level; j["daysOverdue"]=daysOverdue;
            j["dunningFee"]=dunningFee; j["interestAmount"]=interestAmount;
            j["totalDue"]=totalDue;
            return j;
        }
    };
    
    DunningResult calculate(int64_t dueDate, double invoiceAmount, int64_t currentDate) {
        DunningResult result;
        int64_t overdueMs = currentDate - dueDate;
        if (overdueMs <= 0) return result;
        
        result.daysOverdue = static_cast<int>(overdueMs / 86400000LL);
        
        if (result.daysOverdue >= dunningLevel3Days) {
            result.level = 3;
            result.dunningFee = dunningFee3;
        } else if (result.daysOverdue >= dunningLevel2Days) {
            result.level = 2;
            result.dunningFee = dunningFee2;
        } else if (result.daysOverdue >= dunningLevel1Days) {
            result.level = 1;
            result.dunningFee = dunningFee1;
        }
        
        result.interestAmount = invoiceAmount * (interestRate / 100.0) * 
            (static_cast<double>(result.daysOverdue) / 365.0);
        result.totalDue = invoiceAmount + result.dunningFee + result.interestAmount;
        
        return result;
    }
    
    void setLevels(int l1, int l2, int l3) {
        dunningLevel1Days = l1;
        dunningLevel2Days = l2;
        dunningLevel3Days = l3;
    }
};

// ======== HOLIDAY CALENDAR ========
class HolidayCalendar {
    std::vector<std::pair<int,int>> fixedHolidays; // (month, day)
    std::vector<int64_t> customHolidays; // timestamps
    std::string country = "DE";
    std::string state = "";
    
public:
    void loadGermanHolidays(int year) {
        // Fixed holidays for Germany
        fixedHolidays = {
            {1, 1},   // New Year
            {5, 1},   // Labor Day
            {10, 3},  // German Unity Day
            {12, 25}, // Christmas 1
            {12, 26}, // Christmas 2
        };
    }
    
    bool isHoliday(int year, int month, int day) {
        for (auto& [m, d] : fixedHolidays) {
            if (m == month && d == day) return true;
        }
        return false;
    }
    
    void addCustomHoliday(int64_t date) {
        customHolidays.push_back(date);
    }
    
    int getWorkingDays(int year, int month) {
        WorkingTimeCalculator wtc;
        int days = 0;
        int dim = 31;
        if (month == 2) dim = 28;
        else if (month == 4 || month == 6 || month == 9 || month == 11) dim = 30;
        
        for (int d = 1; d <= dim; d++) {
            std::tm tm = {0,0,0,d,month-1,year-1900};
            auto tp = std::chrono::system_clock::from_time_t(std::mktime(&tm));
            auto tt = std::chrono::system_clock::to_time_t(tp);
            int dow = std::localtime(&tt)->tm_wday;
            if (wtc.isWeekday(dow) && !isHoliday(year, month, d)) days++;
        }
        return days;
    }
};

// ======== NUMBER TO WORDS (German) ========
class NumberToWords {
    static const char* onesDE[];
    static const char* tensDE[];
    
public:
    static std::string toGerman(double amount) {
        int euros = static_cast<int>(amount);
        int cents = static_cast<int>(std::round((amount - euros) * 100));
        
        std::string result = convertInteger(euros);
        result += " Euro";
        if (cents > 0) {
            result += " und " + std::to_string(cents) + " Cent";
        }
        return result;
    }
    
private:
    static std::string convertInteger(int n) {
        if (n == 0) return "null";
        if (n < 0) return "minus " + convertInteger(-n);
        if (n < 20) return std::string(onesDE[n]);
        if (n < 100) {
            return std::string(tensDE[n/10]) + (n%10 ? "und" + std::string(onesDE[n%10]) : "");
        }
        if (n < 1000) {
            return std::string(onesDE[n/100]) + "hundert" + (n%100 ? convertInteger(n%100) : "");
        }
        if (n < 1000000) {
            return convertInteger(n/1000) + "tausend" + (n%1000 ? convertInteger(n%1000) : "");
        }
        return convertInteger(n/1000000) + " Million" + (n%1000000 ? " " + convertInteger(n%1000000) : "");
    }
};

const char* NumberToWords::onesDE[] = {
    "null","ein","zwei","drei","vier","funf","sechs","sieben","acht","neun",
    "zehn","elf","zwolf","dreizehn","vierzehn","funfzehn","sechzehn","siebzehn","achtzehn","neunzehn"
};
const char* NumberToWords::tensDE[] = {
    "","zehn","zwanzig","dreißig","vierzig","funfzig","sechzig","siebzig","achtzig","neunzig"
};

// ======== BUSINESS DASHBOARD ========
class BusinessDashboard {
public:
    static nlohmann::json generateDashboard() {
        nlohmann::json dashboard;
        auto now = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        
        dashboard["timestamp"] = now;
        dashboard["activeUsers"] = 0;
        dashboard["openTasks"] = 0;
        dashboard["runningTimesheets"] = 0;
        dashboard["openInvoices"] = 0;
        dashboard["overdueInvoices"] = 0;
        dashboard["pendingVacations"] = 0;
        
        dashboard["financialSummary"] = {
            {"totalRevenueThisMonth", 0.0},
            {"totalExpensesThisMonth", 0.0},
            {"cashBalance", 0.0}
        };
        
        dashboard["recentActivity"] = nlohmann::json::array();
        dashboard["upcomingDeadlines"] = nlohmann::json::array();
        dashboard["systemHealth"] = {{"status","OK"}};
        
        return dashboard;
    }
};

} // namespace
