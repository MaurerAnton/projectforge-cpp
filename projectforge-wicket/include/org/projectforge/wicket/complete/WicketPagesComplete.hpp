// ProjectForge C++ port — GPL v3

#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>

namespace com::projectforge::wicket::complete {

using json = nlohmann::json;

inline std::string esc(const std::string& s) { std::string r; for(char c:s){switch(c){case'&':r+="&amp;";break;case'<':r+="&lt;";break;case'>':r+="&gt;";break;case'"':r+="&quot;";break;default:r+=c;}}return r; }
inline std::string tag(const std::string& t,const std::string& c="",const std::string& a=""){ return"<"+t+(a.empty()?"":" "+a)+">"+c+"</"+t+">"; }
inline std::string attr(const std::string& k,const std::string& v){ return k+"=\""+v+"\""; }


class DashboardPage0 {
public:
    DashboardPage0(const std::string& title="Dashboard") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("Dashboard") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the Dashboard page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class TimesheetPage1 {
public:
    TimesheetPage1(const std::string& title="Timesheet") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("Timesheet") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the Timesheet page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class TimesheetListPage2 {
public:
    TimesheetListPage2(const std::string& title="TimesheetList") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("TimesheetList") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the TimesheetList page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class TimesheetEditPage3 {
public:
    TimesheetEditPage3(const std::string& title="TimesheetEdit") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("TimesheetEdit") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the TimesheetEdit page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class TaskListPage4 {
public:
    TaskListPage4(const std::string& title="TaskList") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("TaskList") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the TaskList page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class TaskEditPage5 {
public:
    TaskEditPage5(const std::string& title="TaskEdit") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("TaskEdit") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the TaskEdit page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class TaskTreePage6 {
public:
    TaskTreePage6(const std::string& title="TaskTree") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("TaskTree") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the TaskTree page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AddressListPage7 {
public:
    AddressListPage7(const std::string& title="AddressList") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AddressList") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AddressList page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AddressEditPage8 {
public:
    AddressEditPage8(const std::string& title="AddressEdit") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AddressEdit") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AddressEdit page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class CalendarPage9 {
public:
    CalendarPage9(const std::string& title="Calendar") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("Calendar") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the Calendar page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class CalendarEventPage10 {
public:
    CalendarEventPage10(const std::string& title="CalendarEvent") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("CalendarEvent") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the CalendarEvent page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class FinancePage11 {
public:
    FinancePage11(const std::string& title="Finance") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("Finance") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the Finance page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class InvoiceListPage12 {
public:
    InvoiceListPage12(const std::string& title="InvoiceList") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("InvoiceList") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the InvoiceList page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class InvoiceEditPage13 {
public:
    InvoiceEditPage13(const std::string& title="InvoiceEdit") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("InvoiceEdit") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the InvoiceEdit page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AccountListPage14 {
public:
    AccountListPage14(const std::string& title="AccountList") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AccountList") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AccountList page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AccountEditPage15 {
public:
    AccountEditPage15(const std::string& title="AccountEdit") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AccountEdit") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AccountEdit page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class CostCenterListPage16 {
public:
    CostCenterListPage16(const std::string& title="CostCenterList") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("CostCenterList") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the CostCenterList page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class OrderListPage17 {
public:
    OrderListPage17(const std::string& title="OrderList") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("OrderList") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the OrderList page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class OrderEditPage18 {
public:
    OrderEditPage18(const std::string& title="OrderEdit") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("OrderEdit") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the OrderEdit page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class HRPlanningPage19 {
public:
    HRPlanningPage19(const std::string& title="HRPlanning") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("HRPlanning") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the HRPlanning page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class HREditPage20 {
public:
    HREditPage20(const std::string& title="HREdit") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("HREdit") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the HREdit page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class VacationListPage21 {
public:
    VacationListPage21(const std::string& title="VacationList") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("VacationList") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the VacationList page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class VacationEditPage22 {
public:
    VacationEditPage22(const std::string& title="VacationEdit") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("VacationEdit") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the VacationEdit page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class LeaveRequestPage23 {
public:
    LeaveRequestPage23(const std::string& title="LeaveRequest") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("LeaveRequest") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the LeaveRequest page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class LeaveApprovalPage24 {
public:
    LeaveApprovalPage24(const std::string& title="LeaveApproval") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("LeaveApproval") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the LeaveApproval page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class BookListPage25 {
public:
    BookListPage25(const std::string& title="BookList") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("BookList") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the BookList page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class BookEditPage26 {
public:
    BookEditPage26(const std::string& title="BookEdit") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("BookEdit") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the BookEdit page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class PollListPage27 {
public:
    PollListPage27(const std::string& title="PollList") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("PollList") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the PollList page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class PollEditPage28 {
public:
    PollEditPage28(const std::string& title="PollEdit") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("PollEdit") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the PollEdit page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class PollResultsPage29 {
public:
    PollResultsPage29(const std::string& title="PollResults") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("PollResults") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the PollResults page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class MemoListPage30 {
public:
    MemoListPage30(const std::string& title="MemoList") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("MemoList") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the MemoList page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class MemoEditPage31 {
public:
    MemoEditPage31(const std::string& title="MemoEdit") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("MemoEdit") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the MemoEdit page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class NoteListPage32 {
public:
    NoteListPage32(const std::string& title="NoteList") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("NoteList") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the NoteList page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class NoteEditPage33 {
public:
    NoteEditPage33(const std::string& title="NoteEdit") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("NoteEdit") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the NoteEdit page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class DocumentListPage34 {
public:
    DocumentListPage34(const std::string& title="DocumentList") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("DocumentList") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the DocumentList page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class DocumentUploadPage35 {
public:
    DocumentUploadPage35(const std::string& title="DocumentUpload") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("DocumentUpload") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the DocumentUpload page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class FileManagerPage36 {
public:
    FileManagerPage36(const std::string& title="FileManager") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("FileManager") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the FileManager page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class ReportListPage37 {
public:
    ReportListPage37(const std::string& title="ReportList") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("ReportList") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the ReportList page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class ReportGeneratePage38 {
public:
    ReportGeneratePage38(const std::string& title="ReportGenerate") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("ReportGenerate") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the ReportGenerate page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class ExportCenterPage39 {
public:
    ExportCenterPage39(const std::string& title="ExportCenter") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("ExportCenter") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the ExportCenter page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class ImportCenterPage40 {
public:
    ImportCenterPage40(const std::string& title="ImportCenter") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("ImportCenter") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the ImportCenter page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class NotificationCenterPage41 {
public:
    NotificationCenterPage41(const std::string& title="NotificationCenter") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("NotificationCenter") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the NotificationCenter page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class UserProfilePage42 {
public:
    UserProfilePage42(const std::string& title="UserProfile") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("UserProfile") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the UserProfile page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class UserSettingsPage43 {
public:
    UserSettingsPage43(const std::string& title="UserSettings") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("UserSettings") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the UserSettings page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class UserPasswordPage44 {
public:
    UserPasswordPage44(const std::string& title="UserPassword") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("UserPassword") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the UserPassword page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AdminPanelPage45 {
public:
    AdminPanelPage45(const std::string& title="AdminPanel") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AdminPanel") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AdminPanel page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AdminUsersPage46 {
public:
    AdminUsersPage46(const std::string& title="AdminUsers") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AdminUsers") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AdminUsers page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AdminGroupsPage47 {
public:
    AdminGroupsPage47(const std::string& title="AdminGroups") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AdminGroups") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AdminGroups page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AdminRightsPage48 {
public:
    AdminRightsPage48(const std::string& title="AdminRights") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AdminRights") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AdminRights page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AdminConfigPage49 {
public:
    AdminConfigPage49(const std::string& title="AdminConfig") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AdminConfig") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AdminConfig page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AdminSystemPage50 {
public:
    AdminSystemPage50(const std::string& title="AdminSystem") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AdminSystem") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AdminSystem page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AdminLogsPage51 {
public:
    AdminLogsPage51(const std::string& title="AdminLogs") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AdminLogs") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AdminLogs page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AdminBackupPage52 {
public:
    AdminBackupPage52(const std::string& title="AdminBackup") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AdminBackup") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AdminBackup page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AdminJobsPage53 {
public:
    AdminJobsPage53(const std::string& title="AdminJobs") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AdminJobs") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AdminJobs page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AdminPluginsPage54 {
public:
    AdminPluginsPage54(const std::string& title="AdminPlugins") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AdminPlugins") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AdminPlugins page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AuditLogPage55 {
public:
    AuditLogPage55(const std::string& title="AuditLog") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AuditLog") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AuditLog page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class SearchResultsPage56 {
public:
    SearchResultsPage56(const std::string& title="SearchResults") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("SearchResults") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the SearchResults page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AdvancedSearchPage57 {
public:
    AdvancedSearchPage57(const std::string& title="AdvancedSearch") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AdvancedSearch") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AdvancedSearch page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class GlobalSearchPage58 {
public:
    GlobalSearchPage58(const std::string& title="GlobalSearch") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("GlobalSearch") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the GlobalSearch page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class HelpCenterPage59 {
public:
    HelpCenterPage59(const std::string& title="HelpCenter") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("HelpCenter") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the HelpCenter page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class AboutPagePage60 {
public:
    AboutPagePage60(const std::string& title="AboutPage") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("AboutPage") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the AboutPage page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};


class ContactPagePage61 {
public:
    ContactPagePage61(const std::string& title="ContactPage") : title_(title) {}
    
    std::string render(const std::string& content="") {
        std::ostringstream ss;
        ss << "<!DOCTYPE html><html><head><meta charset=\"utf-8\">";
        ss << "<title>" << esc(title_) << " - ProjectForge</title>";
        ss << "<link rel=\"stylesheet\" href=\"/css/app.css\"></head><body>";
        ss << renderHeader();
        ss << "<main class=\"content " << toLower("ContactPage") << "-page\">";
        ss << "<h1>" << esc(title_) << "</h1>";
        if (!content.empty()) ss << content;
        else ss << renderDefaultContent();
        ss << "</main>";
        ss << renderFooter();
        ss << "<script src=\"/js/app.js\"></script></body></html>";
        return ss.str();
    }
    
    std::string renderHeader() {
        std::ostringstream ss;
        ss << "<header class=\"app-header\"><nav class=\"main-nav\">";
        ss << tag("a","Timesheet",attr("href","/timesheet"));
        ss << tag("a","Tasks",attr("href","/tasks"));
        ss << tag("a","Calendar",attr("href","/calendar"));
        ss << tag("a","Finance",attr("href","/finance"));
        ss << "</nav></header>";
        return ss.str();
    }
    
    std::string renderFooter() {
        return "<footer><p>ProjectForge C++ v8.2.0</p></footer>";
    }
    
    std::string renderDefaultContent() {
        std::ostringstream ss;
        ss << "<div class=\"placeholder\">";
        ss << "<p>This is the ContactPage page.</p>";
        ss << "<p>Content will be loaded dynamically.</p>";
        ss << "</div>";
        return ss.str();
    }
    
    std::string renderTable(const std::vector<std::vector<std::string>>& rows) {
        std::ostringstream ss;
        ss << "<table class=\"data-table\"><thead><tr>";
        if (!rows.empty()) for(auto& h:rows[0]) ss << "<th>" << esc(h) << "</th>";
        ss << "</tr></thead><tbody>";
        for(size_t i=1;i<rows.size();i++) {
            ss << "<tr>";
            for(auto& c:rows[i]) ss << "<td>" << esc(c) << "</td>";
            ss << "</tr>";
        }
        ss << "</tbody></table>";
        return ss.str();
    }
    
    std::string renderForm(const std::string& action="", const std::map<std::string,std::string>& fields={}) {
        std::ostringstream ss;
        ss << "<form method=\"post\" action=\"" << esc(action) << "\">";
        for(auto&[k,v]:fields) ss << "<label>"<<esc(k)<<"</label><input name=\""<<esc(k)<<"\" value=\""<<esc(v)<<"\">";
        ss << "<button type=\"submit\">Save</button></form>";
        return ss.str();
    }
    
    std::string renderPagination(int page,int total) {
        std::ostringstream ss;
        ss << "<nav class=\"pagination\">";
        if(page>0) ss << tag("a","Prev",attr("href","?page="+std::to_string(page-1)));
        ss << "<span>Page " << (page+1) << " of " << total << "</span>";
        if(page<total-1) ss << tag("a","Next",attr("href","?page="+std::to_string(page+1)));
        ss << "</nav>"; return ss.str();
    }
    
    std::string renderBreadcrumb(const std::vector<std::pair<std::string,std::string>>& items) {
        std::ostringstream ss; ss << "<nav class=\"breadcrumb\">";
        for(size_t i=0;i<items.size();i++) {
            if(i>0) ss << " / ";
            ss << (i<items.size()-1?tag("a",items[i].first,attr("href",items[i].second)):"<span>"+esc(items[i].first)+"</span>");
        }
        ss << "</nav>"; return ss.str();
    }

private:
    std::string title_;
};

} // namespace