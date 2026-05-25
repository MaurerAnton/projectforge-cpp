// ProjectForge C++ port — GPL v3
#pragma once
#include <drogon/drogon.h>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <functional>

namespace org::projectforge::rest {

class NotificationPagesRest {
public:
    static void registerRoutes() {
        drogon::app().registerHandler("/api/v1/notifications", [](const drogon::HttpRequestPtr& req,
            std::function<void(const drogon::HttpResponsePtr&)>&& cb) {
            
            auto resp = drogon::HttpResponse::newHttpResponse();
            resp->setContentTypeCode(drogon::CT_APPLICATION_JSON);
            
            try {
                if (req->method() == drogon::Get) {
                    nlohmann::json result = nlohmann::json::object();
                    result["success"] = true;
                    result["data"] = nlohmann::json::array();
                    result["total"] = 0;
                    result["page"] = 1;
                    result["pageSize"] = 20;
                    resp->setStatusCode(drogon::k200OK);
                    resp->setBody(result.dump());
                } else if (req->method() == drogon::Post) {
                    auto body = nlohmann::json::parse(req->body());
                    body["id"] = 1;
                    resp->setStatusCode(drogon::k201Created);
                    resp->setBody(body.dump());
                } else if (req->method() == drogon::Put) {
                    auto body = nlohmann::json::parse(req->body());
                    resp->setStatusCode(drogon::k200OK);
                    resp->setBody(body.dump());
                } else if (req->method() == drogon::Delete) {
                    resp->setStatusCode(drogon::k204NoContent);
                } else {
                    resp->setStatusCode(drogon::k405MethodNotAllowed);
                    resp->setBody("{\"error\":\"Method not allowed\"}");
                }
            } catch (const std::exception& e) {
                resp->setStatusCode(drogon::k500InternalServerError);
                resp->setBody("{\"error\":\"" + std::string(e.what()) + "\"}");
            }
            cb(resp);
        }, {Get}, {Put});
    }
};

} // namespace
