// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

namespace org::projectforge::plugins::banking {

struct BankAccountEntity {
    int64_t id=-1; std::string iban, bic, bankName, accountHolder, accountNumber;
    int64_t addressId=-1; bool active=true; double balance=0.0;
    nlohmann::json toJson() const {
        nlohmann::json j; j["id"]=id; j["iban"]=iban; j["bic"]=bic;
        j["bankName"]=bankName; j["balance"]=balance;
        return j;
    }
};

class BankingPlugin {
public:
    static void init() {}
    static std::string getName() { return "Banking Plugin"; }
    static std::string getVersion() { return "1.0.0"; }
};
}