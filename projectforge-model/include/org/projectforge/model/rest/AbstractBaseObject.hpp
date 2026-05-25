// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <cstdint>
#include <chrono>
#include <nlohmann/json.hpp>

namespace org::projectforge::model::rest {

class AbstractBaseObject {
public:
    virtual ~AbstractBaseObject() = default;

    int64_t id = -1;
    int64_t created = 0;
    int64_t lastUpdate = 0;
    bool deleted = false;
    int64_t tenant = 0;

    virtual nlohmann::json toJson() const {
        nlohmann::json j;
        if (id >= 0) j["id"] = id;
        if (created > 0) j["created"] = created;
        if (lastUpdate > 0) j["lastUpdate"] = lastUpdate;
        if (deleted) j["deleted"] = true;
        if (tenant > 0) j["tenant"] = tenant;
        return j;
    }

    virtual void fromJson(const nlohmann::json& j) {
        if (j.contains("id")) id = j["id"].get<int64_t>();
        if (j.contains("created")) created = j["created"].get<int64_t>();
        if (j.contains("lastUpdate")) lastUpdate = j["lastUpdate"].get<int64_t>();
        if (j.contains("deleted")) deleted = j["deleted"].get<bool>();
        if (j.contains("tenant")) tenant = j["tenant"].get<int64_t>();
    }
};
}