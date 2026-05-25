// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <map>
#include <vector>
#include <drogon/drogon.h>
#include <jwt-cpp/jwt.h>

namespace org::projectforge::idp {

class OAuth2Handler {
public:
    struct OAuth2Client {
        std::string clientId, clientSecret, redirectUri, name;
        std::vector<std::string> allowedScopes;
    };

    static void registerAuthorizationEndpoint() {
        drogon::app().registerHandler("/oauth2/authorize", [](const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& cb) {
            auto clientId = req->getParameter("client_id");
            auto redirectUri = req->getParameter("redirect_uri");
            auto state = req->getParameter("state");
            auto responseType = req->getParameter("response_type");

            auto resp = drogon::HttpResponse::newHttpResponse();
            if(responseType!="code") {
                resp->setStatusCode(drogon::k400BadRequest);
                resp->setBody("Unsupported response_type");
                cb(resp); return;
            }

            std::string authCode = "auth_code_" + std::to_string(std::chrono::system_clock::now().time_since_epoch().count());
            std::string redirectUrl = redirectUri + "?code=" + authCode;
            if(!state.empty()) redirectUrl += "&state=" + state;
            resp->setStatusCode(drogon::k302Found);
            resp->addHeader("Location", redirectUrl);
            cb(resp);
        });
    }

    static void registerTokenEndpoint() {
        drogon::app().registerHandler("/oauth2/token", [](const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& cb) {
            auto body = req->body();
            auto grantType = extractParam(body, "grant_type");
            auto code = extractParam(body, "code");

            auto resp = drogon::HttpResponse::newHttpResponse();
            resp->setContentTypeCode(drogon::CT_APPLICATION_JSON);

            if(grantType=="authorization_code") {
                auto token = jwt::create()
                    .set_issuer("projectforge-idp")
                    .set_type("JWT")
                    .set_subject("user")
                    .set_issued_at(std::chrono::system_clock::now())
                    .set_expires_at(std::chrono::system_clock::now()+std::chrono::hours(1))
                    .sign(jwt::algorithm::hs256{"idp-secret"});

                nlohmann::json j;
                j["access_token"] = token;
                j["token_type"] = "Bearer";
                j["expires_in"] = 3600;
                j["refresh_token"] = "refresh_" + std::to_string(std::chrono::system_clock::now().time_since_epoch().count());
                resp->setBody(j.dump());
            } else if(grantType=="refresh_token") {
                auto token = jwt::create()
                    .set_issuer("projectforge-idp")
                    .set_expires_at(std::chrono::system_clock::now()+std::chrono::hours(1))
                    .sign(jwt::algorithm::hs256{"idp-secret"});
                nlohmann::json j;
                j["access_token"] = token;
                j["token_type"] = "Bearer";
                j["expires_in"] = 3600;
                resp->setBody(j.dump());
            } else {
                resp->setStatusCode(drogon::k400BadRequest);
                resp->setBody("{\"error\":\"unsupported_grant_type\"}");
            }
            cb(resp);
        });
    }

    static void registerUserInfoEndpoint() {
        drogon::app().registerHandler("/oauth2/userinfo", [](const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& cb) {
            auto auth = req->getHeader("Authorization");
            auto resp = drogon::HttpResponse::newHttpResponse();
            resp->setContentTypeCode(drogon::CT_APPLICATION_JSON);
            if(auth.empty()||auth.find("Bearer ")!=0) {
                resp->setStatusCode(drogon::k401Unauthorized);
                resp->setBody("{\"error\":\"unauthorized\"}");
                cb(resp); return;
            }
            nlohmann::json userInfo;
            userInfo["sub"] = "user123";
            userInfo["name"] = "Test User";
            userInfo["email"] = "test@projectforge.org";
            resp->setStatusCode(drogon::k200OK);
            resp->setBody(userInfo.dump());
            cb(resp);
        });
    }

    static void registerOpenIdConfiguration() {
        drogon::app().registerHandler("/.well-known/openid-configuration", [](const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& cb) {
            nlohmann::json config;
            config["issuer"] = "https://projectforge.local";
            config["authorization_endpoint"] = "https://projectforge.local/oauth2/authorize";
            config["token_endpoint"] = "https://projectforge.local/oauth2/token";
            config["userinfo_endpoint"] = "https://projectforge.local/oauth2/userinfo";
            config["jwks_uri"] = "https://projectforge.local/.well-known/jwks.json";
            config["scopes_supported"] = {"openid","profile","email"};
            config["response_types_supported"] = {"code","token","id_token"};
            config["grant_types_supported"] = {"authorization_code","refresh_token"};
            config["id_token_signing_alg_values_supported"] = {"HS256"};
            auto resp = drogon::HttpResponse::newHttpResponse();
            resp->setContentTypeCode(drogon::CT_APPLICATION_JSON);
            resp->setBody(config.dump());
            cb(resp);
        });
    }

private:
    static std::string extractParam(const std::string& body, const std::string& key) {
        auto pos = body.find(key+"=");
        if(pos==std::string::npos) return "";
        pos+=key.size()+1;
        auto end = body.find('&',pos);
        return body.substr(pos, end==std::string::npos ? body.size()-pos : end-pos);
    }
};

} // namespace
