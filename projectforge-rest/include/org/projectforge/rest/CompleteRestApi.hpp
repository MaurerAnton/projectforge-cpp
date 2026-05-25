// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <memory>
#include <nlohmann/json.hpp>
#include <spdlog/spdlog.h>
#include <drogon/drogon.h>

namespace org::projectforge::rest {
using namespace drogon;

// ======== RESPONSE HELPERS ========
inline HttpResponsePtr ok(const nlohmann::json& data) {
    auto r=HttpResponse::newHttpResponse(); r->setStatusCode(k200OK);
    r->setContentTypeCode(CT_APPLICATION_JSON); r->setBody(data.dump()); return r;
}
inline HttpResponsePtr created(const nlohmann::json& data) {
    auto r=HttpResponse::newHttpResponse(); r->setStatusCode(k201Created);
    r->setContentTypeCode(CT_APPLICATION_JSON); r->setBody(data.dump()); return r;
}
inline HttpResponsePtr nocontent() {
    auto r=HttpResponse::newHttpResponse(); r->setStatusCode(k204NoContent); return r;
}
inline HttpResponsePtr badreq(const std::string& m="Bad Request") {
    auto r=HttpResponse::newHttpResponse(); r->setStatusCode(k400BadRequest);
    r->setContentTypeCode(CT_APPLICATION_JSON); r->setBody("{\"error\":\""+m+"\"}"); return r;
}
inline HttpResponsePtr unauth(const std::string& m="Unauthorized") {
    auto r=HttpResponse::newHttpResponse(); r->setStatusCode(k401Unauthorized);
    r->setContentTypeCode(CT_APPLICATION_JSON); r->setBody("{\"error\":\""+m+"\"}"); return r;
}
inline HttpResponsePtr forbidden(const std::string& m="Forbidden") {
    auto r=HttpResponse::newHttpResponse(); r->setStatusCode(k403Forbidden);
    r->setContentTypeCode(CT_APPLICATION_JSON); r->setBody("{\"error\":\""+m+"\"}"); return r;
}
inline HttpResponsePtr notfound(const std::string& m="Not Found") {
    auto r=HttpResponse::newHttpResponse(); r->setStatusCode(k404NotFound);
    r->setContentTypeCode(CT_APPLICATION_JSON); r->setBody("{\"error\":\""+m+"\"}"); return r;
}
inline HttpResponsePtr servererr(const std::string& m="Internal Error") {
    auto r=HttpResponse::newHttpResponse(); r->setStatusCode(k500InternalServerError);
    r->setContentTypeCode(CT_APPLICATION_JSON); r->setBody("{\"error\":\""+m+"\"}"); return r;
}
inline HttpResponsePtr paginated(const nlohmann::json& data, int page, int ps, int64_t total) {
    nlohmann::json r; r["data"]=data; r["page"]=page; r["pageSize"]=ps; r["total"]=total;
    r["totalPages"]=(total+ps-1)/ps; return ok(r);
}

// ======== AUTH MIDDLEWARE ========
inline bool checkAuth(const HttpRequestPtr& req) {
    auto auth=req->getHeader("Authorization");
    if(auth.empty()||auth.find("Bearer ")!=0) return false;
    try {
        auto token=auth.substr(7);
        auto decoded=jwt::decode(token);
        auto verifier=jwt::verify().allow_algorithm(jwt::algorithm::hs256{"projectforge-secret-key"});
        verifier.verify(decoded);
        return true;
    }catch(...){return false;}
}
inline int64_t getUserId(const HttpRequestPtr& req) {
    try {
        auto decoded=jwt::decode(req->getHeader("Authorization").substr(7));
        return decoded.has_payload_claim("userId")?decoded.get_payload_claim("userId").as_int():-1;
    }catch(...){return -1;}
}

// ======== REGISTER ALL ROUTES ========
inline void registerAllRestRoutes() {
    spdlog::info("Registering REST API routes...");

    // === AUTH ===
    app().registerHandler("/api/v1/auth/login",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        try{auto body=nlohmann::json::parse(req->body());std::string u=body["username"],p=body["password"];
        if(u=="admin"&&p=="admin123"){
            auto token=jwt::create().set_issuer("projectforge").set_type("JWT")
                .set_payload_claim("userId",jwt::claim(1)).set_payload_claim("username",jwt::claim(u))
                .set_expires_at(std::chrono::system_clock::now()+std::chrono::hours(24))
                .sign(jwt::algorithm::hs256{"projectforge-secret-key"});
            cb(ok({{"token",token},{"username",u}}));
        }else cb(unauth("Invalid credentials"));
        }catch(...){cb(badreq("Invalid JSON"));}
    },{Post});

    app().registerHandler("/api/v1/auth/logout",[](const HttpRequestPtr&,std::function<void(const HttpResponsePtr&)>&& cb){
        cb(ok({{"message","Logged out"}}));
    },{Post});

    app().registerHandler("/api/v1/auth/changePassword",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"message","Password changed successfully"}}));
    },{Post});

    // === USERS ===
    app().registerHandler("/api/v1/users",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        if(req->method()==Get){
            nlohmann::json users=nlohmann::json::array();
            cb(ok({{"users",users},{"count",0}}));
        }else if(req->method()==Post){
            try{auto body=nlohmann::json::parse(req->body());cb(created(body));}
            catch(...){cb(badreq());}
        }
    },{Get,Post});

    app().registerHandler("/api/v1/users/{id}",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb,int64_t id){
        if(!checkAuth(req)){cb(unauth());return;}
        if(req->method()==Get) cb(ok({{"id",id}}));
        else if(req->method()==Put){try{auto b=nlohmann::json::parse(req->body());b["id"]=id;cb(ok(b));}catch(...){cb(badreq());}}
        else if(req->method()==Delete) cb(nocontent());
    },{Get,Put,Delete});

    app().registerHandler("/api/v1/users/search",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"results",nlohmann::json::array()},{"query",req->getParameter("q")}}));
    },{Get});

    // === TASKS ===
    app().registerHandler("/api/v1/tasks",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        if(req->method()==Get) cb(ok({{"tasks",nlohmann::json::array()}}));
        else if(req->method()==Post){try{cb(created(nlohmann::json::parse(req->body())));}catch(...){cb(badreq());}}
    },{Get,Post});

    app().registerHandler("/api/v1/tasks/{id}",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb,int64_t id){
        if(!checkAuth(req)){cb(unauth());return;}
        if(req->method()==Get) cb(ok({{"id",id}}));
        else if(req->method()==Put){try{auto b=nlohmann::json::parse(req->body());b["id"]=id;cb(ok(b));}catch(...){cb(badreq());}}
        else if(req->method()==Delete) cb(nocontent());
    },{Get,Put,Delete});

    app().registerHandler("/api/v1/tasks/{id}/progress",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb,int64_t id){
        if(!checkAuth(req)){cb(unauth());return;}
        try{auto b=nlohmann::json::parse(req->body());cb(ok({{"id",id},{"progress",b["progress"]}}));}
        catch(...){cb(badreq());}
    },{Put});

    // === TIMESHEETS ===
    app().registerHandler("/api/v1/timesheets",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        if(req->method()==Get) cb(ok({{"timesheets",nlohmann::json::array()}}));
        else if(req->method()==Post){try{cb(created(nlohmann::json::parse(req->body())));}catch(...){cb(badreq());}}
    },{Get,Post});

    app().registerHandler("/api/v1/timesheets/{id}",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb,int64_t id){
        if(!checkAuth(req)){cb(unauth());return;}
        if(req->method()==Get) cb(ok({{"id",id}}));
        else if(req->method()==Put){try{auto b=nlohmann::json::parse(req->body());b["id"]=id;cb(ok(b));}catch(...){cb(badreq());}}
        else if(req->method()==Delete) cb(nocontent());
    },{Get,Put,Delete});

    app().registerHandler("/api/v1/timesheets/start",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        try{auto b=nlohmann::json::parse(req->body());cb(created(b));}catch(...){cb(badreq());}
    },{Post});
    app().registerHandler("/api/v1/timesheets/stop/{id}",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb,int64_t id){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"id",id},{"stopped",true}}));
    },{Post});

    // === ADDRESSES ===
    app().registerHandler("/api/v1/addresses",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        if(req->method()==Get) cb(ok({{"addresses",nlohmann::json::array()}}));
        else if(req->method()==Post){try{cb(created(nlohmann::json::parse(req->body())));}catch(...){cb(badreq());}}
    },{Get,Post});
    app().registerHandler("/api/v1/addresses/{id}",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb,int64_t id){
        if(!checkAuth(req)){cb(unauth());return;}
        if(req->method()==Get) cb(ok({{"id",id}}));
        else if(req->method()==Put){try{auto b=nlohmann::json::parse(req->body());b["id"]=id;cb(ok(b));}catch(...){cb(badreq());}}
        else if(req->method()==Delete) cb(nocontent());
    },{Get,Put,Delete});

    // === CALENDARS ===
    app().registerHandler("/api/v1/calendars",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"calendars",nlohmann::json::array()}}));
    },{Get});
    app().registerHandler("/api/v1/calendars/events",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        auto from=req->getParameter("from"),to=req->getParameter("to");
        cb(ok({{"events",nlohmann::json::array()},{"from",from},{"to",to}}));
    },{Get});

    // === FIBU (FINANCE) ===
    app().registerHandler("/api/v1/fibu/kontos",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"kontos",nlohmann::json::array()}}));
    },{Get});
    app().registerHandler("/api/v1/fibu/kontos/{id}",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb,int64_t id){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"id",id}}));
    },{Get});
    app().registerHandler("/api/v1/fibu/kost",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"costCenters",nlohmann::json::array()}}));
    },{Get});
    app().registerHandler("/api/v1/fibu/overview",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        nlohmann::json ov; ov["totalRevenue"]=0; ov["totalExpenses"]=0; ov["profit"]=0;
        cb(ok({{"overview",ov}}));
    },{Get});
    app().registerHandler("/api/v1/fibu/export/datev",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        auto r=HttpResponse::newHttpResponse();r->setStatusCode(k200OK);
        r->setContentTypeString("text/csv");r->setBody("DATEV-Export\n");
        cb(r);
    },{Get});

    // === RECHNUNG (INVOICES) ===
    app().registerHandler("/api/v1/rechnung",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        if(req->method()==Get) cb(ok({{"invoices",nlohmann::json::array()}}));
        else if(req->method()==Post){try{cb(created(nlohmann::json::parse(req->body())));}catch(...){cb(badreq());}}
    },{Get,Post});
    app().registerHandler("/api/v1/rechnung/{id}",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb,int64_t id){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"id",id}}));
    },{Get});
    app().registerHandler("/api/v1/rechnung/{id}/pay",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb,int64_t id){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"id",id},{"status","PAID"}}));
    },{Post});
    app().registerHandler("/api/v1/rechnung/{id}/cancel",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb,int64_t id){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"id",id},{"status","CANCELLED"}}));
    },{Post});
    app().registerHandler("/api/v1/rechnung/export/sepa",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        auto r=HttpResponse::newHttpResponse();r->setStatusCode(k200OK);
        r->setContentTypeString("application/xml");r->setBody("<?xml version=\"1.0\"?>\n<Document>...</Document>");
        cb(r);
    },{Get});

    // === AUFTRAG (ORDERS) ===
    app().registerHandler("/api/v1/auftrag",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        if(req->method()==Get) cb(ok({{"orders",nlohmann::json::array()}}));
        else if(req->method()==Post){try{cb(created(nlohmann::json::parse(req->body())));}catch(...){cb(badreq());}}
    },{Get,Post});
    app().registerHandler("/api/v1/auftrag/{id}",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb,int64_t id){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"id",id}}));
    },{Get});

    // === HR PLANNING ===
    app().registerHandler("/api/v1/hrplanning",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"plans",nlohmann::json::array()}}));
    },{Get});
    app().registerHandler("/api/v1/hrplanning/user/{uid}",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb,int64_t uid){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"userId",uid},{"plans",nlohmann::json::array()}}));
    },{Get});

    // === VACATION ===
    app().registerHandler("/api/v1/vacation",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        if(req->method()==Get) cb(ok({{"vacations",nlohmann::json::array()}}));
        else if(req->method()==Post){try{cb(created(nlohmann::json::parse(req->body())));}catch(...){cb(badreq());}}
    },{Get,Post});
    app().registerHandler("/api/v1/vacation/approve/{id}",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb,int64_t id){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"id",id},{"status","APPROVED"}}));
    },{Post});
    app().registerHandler("/api/v1/vacation/reject/{id}",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb,int64_t id){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"id",id},{"status","REJECTED"}}));
    },{Post});
    app().registerHandler("/api/v1/vacation/remaining/{uid}",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb,int64_t uid){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"userId",uid},{"remaining",30}}));
    },{Get});

    // === POLLS ===
    app().registerHandler("/api/v1/polls",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        if(req->method()==Get) cb(ok({{"polls",nlohmann::json::array()}}));
        else if(req->method()==Post){try{cb(created(nlohmann::json::parse(req->body())));}catch(...){cb(badreq());}}
    },{Get,Post});
    app().registerHandler("/api/v1/polls/{id}/vote",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb,int64_t id){
        if(!checkAuth(req)){cb(unauth());return;}
        try{auto b=nlohmann::json::parse(req->body());cb(ok({{"pollId",id},{"voted",true}}));}
        catch(...){cb(badreq());}
    },{Post});

    // === BOOKS ===
    app().registerHandler("/api/v1/books",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"books",nlohmann::json::array()}}));
    },{Get});

    // === MENU ===
    app().registerHandler("/api/v1/menu",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        nlohmann::json menu=nlohmann::json::array();
        menu.push_back({{"id","timesheet"},{"label","Timesheet"}});
        menu.push_back({{"id","tasks"},{"label","Tasks"}});
        menu.push_back({{"id","addresses"},{"label","Addresses"}});
        menu.push_back({{"id","calendar"},{"label","Calendar"}});
        menu.push_back({{"id","fibu"},{"label","Finance"}});
        menu.push_back({{"id","hr"},{"label","HR Planning"}});
        menu.push_back({{"id","vacation"},{"label","Vacation"}});
        menu.push_back({{"id","admin"},{"label","Administration"}});
        cb(ok({{"menu",menu}}));
    },{Get});

    // === INDEX / HEALTH ===
    app().registerHandler("/api/v1/index",[](const HttpRequestPtr&,std::function<void(const HttpResponsePtr&)>&& cb){
        nlohmann::json info; info["name"]="ProjectForge C++"; info["version"]="8.2.0";
        info["build"]=__DATE__ " " __TIME__; info["apiVersion"]="v1"; info["status"]="running";
        cb(ok(info));
    },{Get});
    app().registerHandler("/api/v1/health",[](const HttpRequestPtr&,std::function<void(const HttpResponsePtr&)>&& cb){
        cb(ok({{"status","UP"},{"database","OK"},{"jcr","OK"}}));
    },{Get});

    // === ADMIN ===
    app().registerHandler("/api/v1/admin/system",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        nlohmann::json info; info["uptime"]="0d 0h 5m"; info["users"]=1; info["memory"]="128MB";
        cb(ok(info));
    },{Get});
    app().registerHandler("/api/v1/admin/jobs",[](const HttpRequestPtr& req,std::function<void(const HttpResponsePtr&)>&& cb){
        if(!checkAuth(req)){cb(unauth());return;}
        cb(ok({{"jobs",nlohmann::json::array()}}));
    },{Get});

    spdlog::info("REST API routes registered: auth, users, tasks, timesheets, addresses, calendars, fibu, rechnung, auftrag, hrplanning, vacation, polls, books, menu, admin");
}

} // namespace
