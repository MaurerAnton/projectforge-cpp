// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <drogon/drogon.h>

namespace org::projectforge::carddav {

class VCardParser {
public:
    struct VCard {
        std::string uid, fullName, organization, email, phone, mobilePhone, street, city, zipCode, country, note;
        std::string toVCard() const {
            std::ostringstream ss;
            ss<<"BEGIN:VCARD\\nVERSION:4.0\\n";
            if(!uid.empty()) ss<<"UID:"<<uid<<"\\n";
            if(!fullName.empty()) ss<<"FN:"<<fullName<<"\\n";
            if(!organization.empty()) ss<<"ORG:"<<organization<<"\\n";
            if(!email.empty()) ss<<"EMAIL:"<<email<<"\\n";
            if(!phone.empty()) ss<<"TEL;TYPE=work:"<<phone<<"\\n";
            if(!mobilePhone.empty()) ss<<"TEL;TYPE=cell:"<<mobilePhone<<"\\n";
            if(!street.empty()||!city.empty()) ss<<"ADR:;;"<<street<<";"<<city<<";;"<<zipCode<<";"<<country<<"\\n";
            if(!note.empty()) ss<<"NOTE:"<<note<<"\\n";
            ss<<"END:VCARD\\n";
            return ss.str();
        }
    };

    static std::vector<VCard> parseMultiple(const std::string& data) {
        std::vector<VCard> cards;
        VCard current;
        bool inVCard=false;
        std::istringstream ss(data);
        std::string line;
        while(std::getline(ss,line)) {
            if(line.empty()||line=="\\r") continue;
            if(line=="BEGIN:VCARD") { current=VCard{}; inVCard=true; continue; }
            if(line=="END:VCARD") { if(inVCard) cards.push_back(current); inVCard=false; continue; }
            if(!inVCard) continue;
            auto colon=line.find(':');
            if(colon==std::string::npos) continue;
            std::string key=line.substr(0,colon);
            std::string val=line.substr(colon+1);
            auto semi=key.find(';'); if(semi!=std::string::npos) key=key.substr(0,semi);
            std::transform(key.begin(),key.end(),key.begin(),::toupper);
            if(key=="UID") current.uid=val;
            else if(key=="FN") current.fullName=val;
            else if(key=="ORG") current.organization=val;
            else if(key=="EMAIL") current.email=val;
            else if(key=="TEL"&&line.find("TYPE=cell")!=std::string::npos) current.mobilePhone=val;
            else if(key=="TEL") current.phone=val;
            else if(key=="ADR") { auto parts=splitAdr(val); if(parts.size()>2)current.street=parts[2]; if(parts.size()>3)current.city=parts[3]; if(parts.size()>5)current.zipCode=parts[5]; }
            else if(key=="NOTE") current.note=val;
        }
        if(inVCard) cards.push_back(current);
        return cards;
    }
private:
    static std::vector<std::string> splitAdr(const std::string& a) {
        std::vector<std::string> r; std::string c;
        for(size_t i=0;i<a.size();++i) {
            if(a[i]==';'){r.push_back(c);c.clear();}
            else if(a[i]=='\\'&&i+1<a.size()&&a[i+1]==';'){c+=';';++i;}
            else c+=a[i];
        }
        r.push_back(c); return r;
    }
};

class CardDavServer {
public:
    static void registerRoutes() {
        drogon::app().registerHandler("/carddav/{addressbook:.+}", [](const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& cb, const std::string& ab) {
            auto resp = drogon::HttpResponse::newHttpResponse();
            if(req->method()==drogon::Options) {
                resp->setStatusCode(drogon::k200OK);
                resp->addHeader("DAV","1,3,access-control,addressbook");
                resp->addHeader("Allow","OPTIONS,GET,PUT,DELETE,PROPFIND,REPORT");
                cb(resp); return;
            }
            if(req->method()==drogon::Get) {
                resp->setStatusCode(drogon::k200OK);
                resp->setContentTypeString("text/vcard; charset=utf-8");
                VCardParser::VCard vc; vc.uid="test"; vc.fullName="Test User"; vc.email="test@example.com";
                resp->setBody(vc.toVCard());
                cb(resp); return;
            }
            resp->setStatusCode(drogon::k405MethodNotAllowed);
            cb(resp);
        });
    }
};

} // namespace
