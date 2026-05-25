// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/business/fibu/FibuModule.hpp"
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <map>
#include <vector>

namespace org::projectforge::business::fibu {

namespace {
    inline int64_t now() { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }
    inline std::string fmtDate(int64_t ms) { if(ms<=0)return"";auto t=std::chrono::system_clock::to_time_t(std::chrono::system_clock::from_time_t(ms/1000));std::ostringstream ss;ss<<std::put_time(std::localtime(&t),"%d.%m.%Y");return ss.str();}
    inline double round2(double v) { return std::round(v*100.0)/100.0; }
}

class InvoiceProcessor {
public:
    struct InvoiceTotals { double net=0,gross=0,vat=0; int count=0; };
    
    InvoiceTotals calculateTotals(const std::vector<RechnungEntity>& invoices) {
        InvoiceTotals t;
        for(auto& inv:invoices){if(inv.deleted)continue;t.net+=inv.netSum;t.gross+=inv.grossSum;t.vat+=inv.vatSum;t.count++;}
        t.net=round2(t.net);t.gross=round2(t.gross);t.vat=round2(t.vat);
        return t;
    }
    
    nlohmann::json generateMonthlyReport(int year,int month) {
        nlohmann::json r;r["year"]=year;r["month"]=month;
        r["outgoing"]=nlohmann::json::array();r["incoming"]=nlohmann::json::array();
        r["revenue"]=0;r["expenses"]=0;r["vatPayable"]=0;r["vatReceivable"]=0;
        return r;
    }
    
    nlohmann::json generateCustomerReport(int64_t customerId) {
        nlohmann::json r;r["customerId"]=customerId;
        r["totalInvoiced"]=0;r["totalPaid"]=0;r["outstanding"]=0;r["invoices"]=nlohmann::json::array();
        return r;
    }
};

class PaymentTracker {
    std::map<int64_t,std::vector<std::pair<int64_t,double>>> paymentHistory;
public:
    void recordPayment(int64_t invoiceId,double amount,int64_t date=0) {
        paymentHistory[invoiceId].push_back({date>0?date:now(),amount});
        spdlog::info("Payment recorded: invoice={}, amount={:.2f}",invoiceId,amount);
    }
    double getTotalPaid(int64_t invoiceId) {
        double t=0;for(auto&[d,a]:paymentHistory[invoiceId])t+=a;return t;
    }
    double getOutstanding(int64_t invoiceId,double totalAmount) {
        return std::max(0.0,totalAmount-getTotalPaid(invoiceId));
    }
    nlohmann::json getPaymentHistory(int64_t invoiceId) {
        nlohmann::json h=nlohmann::json::array();
        for(auto&[d,a]:paymentHistory[invoiceId])h.push_back({{"date",d},{"amount",a}});
        return h;
    }
};

class FinancialRatioCalculator {
public:
    struct Ratios {
        double currentRatio=0,quickRatio=0,debtToEquity=0;
        double grossMargin=0,netMargin=0,roi=0;
        double dso=0,dpo=0,inventoryTurnover=0;
        nlohmann::json toJson() const {
            return {{"currentRatio",currentRatio},{"quickRatio",quickRatio},{"debtToEquity",debtToEquity},{"grossMargin",grossMargin},{"netMargin",netMargin},{"roi",roi},{"dso",dso},{"dpo",dpo},{"inventoryTurnover",inventoryTurnover}};
        }
    };
    
    Ratios calculate(double currentAssets,double currentLiabilities,double totalDebt,double totalEquity,double grossProfit,double revenue,double netIncome,double accountsReceivable,double annualRevenue,double accountsPayable,double cogs,double avgInventory) {
        Ratios r;
        if(currentLiabilities>0)r.currentRatio=round2(currentAssets/currentLiabilities);
        if(currentLiabilities>0)r.quickRatio=round2((currentAssets-0)/currentLiabilities);
        if(totalEquity>0)r.debtToEquity=round2(totalDebt/totalEquity);
        if(revenue>0)r.grossMargin=round2(grossProfit/revenue*100);
        if(revenue>0)r.netMargin=round2(netIncome/revenue*100);
        if(totalEquity+totalDebt>0)r.roi=round2(netIncome/(totalEquity+totalDebt)*100);
        if(annualRevenue>0)r.dso=round2(accountsReceivable/(annualRevenue/365));
        if(cogs>0)r.dpo=round2(accountsPayable/(cogs/365));
        if(cogs>0&&avgInventory>0)r.inventoryTurnover=round2(cogs/avgInventory);
        return r;
    }
};

class CostAccounting {
    std::map<int64_t,std::map<std::string,double>> costAllocations;
public:
    void allocateCost(int64_t costCenterId,const std::string& category,double amount) {costAllocations[costCenterId][category]+=amount;}
    double getTotalCost(int64_t costCenterId) {double t=0;for(auto&[cat,a]:costAllocations[costCenterId])t+=a;return t;}
    double getCostByCategory(int64_t costCenterId,const std::string& cat) {return costAllocations[costCenterId][cat];}
    std::vector<std::pair<std::string,double>> getCostBreakdown(int64_t ccId) {
        std::vector<std::pair<std::string,double>> r;
        for(auto&[c,a]:costAllocations[ccId])r.push_back({c,a});
        std::sort(r.begin(),r.end(),[](auto&a,auto&b){return a.second>b.second;});
        return r;
    }
    nlohmann::json getCostReport(int64_t ccId) {
        nlohmann::json r;r["costCenter"]=ccId;r["total"]=getTotalCost(ccId);
        nlohmann::json cats=nlohmann::json::array();
        for(auto&[c,a]:getCostBreakdown(ccId))cats.push_back({{"category",c},{"amount",a}});
        r["categories"]=cats;return r;
    }
};

class ProfitLossCalculator {
public:
    struct PLStatement {
        double revenue=0,cogs=0,grossProfit=0;
        double operatingExpenses=0,ebitda=0,depreciation=0,ebit=0;
        double interestExpense=0,interestIncome=0,ebt=0;
        double taxExpense=0,netIncome=0;
        int64_t periodStart=0,periodEnd=0;
        nlohmann::json toJson() const {
            return {{"revenue",revenue},{"cogs",cogs},{"grossProfit",grossProfit},{"operatingExpenses",operatingExpenses},{"ebitda",ebitda},{"depreciation",depreciation},{"ebit",ebit},{"interestExpense",interestExpense},{"interestIncome",interestIncome},{"ebt",ebt},{"taxExpense",taxExpense},{"netIncome",netIncome},{"periodStart",periodStart},{"periodEnd",periodEnd}};
        }
    };
    
    PLStatement generate(int64_t start,int64_t end) {
        PLStatement pl;pl.periodStart=start;pl.periodEnd=end;
        pl.revenue=100000;pl.cogs=40000;pl.grossProfit=pl.revenue-pl.cogs;
        pl.operatingExpenses=30000;pl.ebitda=pl.grossProfit-pl.operatingExpenses;
        pl.depreciation=5000;pl.ebit=pl.ebitda-pl.depreciation;
        pl.interestExpense=2000;pl.interestIncome=500;pl.ebt=pl.ebit-pl.interestExpense+pl.interestIncome;
        pl.taxExpense=pl.ebt*0.3;pl.netIncome=pl.ebt-pl.taxExpense;
        return pl;
    }
};

class BalanceSheetGenerator {
public:
    struct BalanceSheet {
        double totalAssets=0,totalLiabilities=0,totalEquity=0;
        double cash=0,accountsReceivable=0,inventory=0,fixedAssets=0;
        double accountsPayable=0,shortTermDebt=0,longTermDebt=0;
        nlohmann::json toJson() const {
            nlohmann::json a;a["cash"]=cash;a["accountsReceivable"]=accountsReceivable;a["inventory"]=inventory;a["fixedAssets"]=fixedAssets;
            nlohmann::json l;l["accountsPayable"]=accountsPayable;l["shortTermDebt"]=shortTermDebt;l["longTermDebt"]=longTermDebt;
            return {{"assets",a},{"totalAssets",totalAssets},{"liabilities",l},{"totalLiabilities",totalLiabilities},{"equity",totalEquity}};
        }
    };
    
    BalanceSheet generate(int64_t asOf) {
        BalanceSheet bs;
        bs.cash=50000;bs.accountsReceivable=30000;bs.inventory=20000;bs.fixedAssets=100000;
        bs.totalAssets=bs.cash+bs.accountsReceivable+bs.inventory+bs.fixedAssets;
        bs.accountsPayable=15000;bs.shortTermDebt=10000;bs.longTermDebt=50000;
        bs.totalLiabilities=bs.accountsPayable+bs.shortTermDebt+bs.longTermDebt;
        bs.totalEquity=bs.totalAssets-bs.totalLiabilities;
        return bs;
    }
};

class CashFlowGenerator {
public:
    struct CashFlow {
        double operatingCashFlow=0,investingCashFlow=0,financingCashFlow=0,netCashFlow=0;
        double beginningCash=0,endingCash=0;
        nlohmann::json toJson() const {
            return {{"operating",operatingCashFlow},{"investing",investingCashFlow},{"financing",financingCashFlow},{"net",netCashFlow},{"beginning",beginningCash},{"ending",endingCash}};
        }
    };
    
    CashFlow generate(int64_t start,int64_t end) {
        CashFlow cf;
        cf.operatingCashFlow=80000;cf.investingCashFlow=-30000;cf.financingCashFlow=-10000;
        cf.netCashFlow=cf.operatingCashFlow+cf.investingCashFlow+cf.financingCashFlow;
        cf.beginningCash=50000;cf.endingCash=cf.beginningCash+cf.netCashFlow;
        return cf;
    }
};

} // namespace
