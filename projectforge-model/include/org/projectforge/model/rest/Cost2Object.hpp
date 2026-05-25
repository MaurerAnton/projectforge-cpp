// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "AbstractBaseObject.hpp"
#include <string>
#include <nlohmann/json.hpp>

namespace org::projectforge::model::rest {

class Cost2Object : public AbstractBaseObject {
public:
    std::string name;
    std::string description;
    int64_t cost1Id = -1;
    int number = 0;

    nlohmann::json toJson() const override {
        auto j = AbstractBaseObject::toJson();
        if (!name.empty()) j["name"] = name;
        if (!description.empty()) j["description"] = description;
        if (cost1Id >= 0) j["cost1Id"] = cost1Id;
        j["number"] = number;
        return j;
    }
};
}