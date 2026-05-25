// ProjectForge C++ port — GPL v3

#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
namespace com { namespace projectforge { namespace io { namespace extended {
using json = nlohmann::json;
class IOService1 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService2 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService3 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService4 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService5 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService6 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService7 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService8 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService9 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService10 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService11 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService12 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService13 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService14 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService15 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService16 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService17 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService18 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService19 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService20 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService21 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService22 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService23 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService24 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService25 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService26 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService27 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService28 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService29 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService30 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService31 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService32 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService33 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService34 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService35 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService36 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService37 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService38 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService39 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService40 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService41 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService42 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService43 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService44 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService45 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService46 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService47 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService48 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService49 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService50 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService51 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService52 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService53 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService54 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService55 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService56 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService57 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService58 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService59 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService60 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService61 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService62 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService63 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService64 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService65 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService66 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService67 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService68 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService69 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService70 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService71 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService72 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService73 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService74 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService75 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService76 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService77 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService78 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService79 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService80 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService81 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService82 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService83 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService84 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService85 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService86 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService87 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService88 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService89 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService90 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService91 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService92 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService93 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService94 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService95 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService96 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService97 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService98 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService99 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService100 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService101 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService102 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService103 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService104 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService105 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService106 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService107 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService108 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService109 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService110 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService111 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService112 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService113 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService114 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService115 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService116 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService117 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService118 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService119 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService120 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService121 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService122 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService123 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService124 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService125 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService126 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService127 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService128 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService129 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService130 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService131 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService132 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService133 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService134 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService135 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService136 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService137 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService138 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService139 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService140 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService141 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService142 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService143 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService144 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService145 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService146 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService147 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService148 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService149 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService150 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService151 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService152 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService153 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService154 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService155 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService156 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService157 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService158 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService159 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService160 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService161 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService162 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService163 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService164 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService165 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService166 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService167 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService168 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService169 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService170 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService171 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService172 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService173 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService174 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService175 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService176 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService177 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService178 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService179 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService180 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService181 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService182 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService183 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService184 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService185 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService186 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService187 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService188 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService189 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService190 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService191 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService192 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService193 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService194 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService195 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService196 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService197 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService198 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService199 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService200 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService201 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService202 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService203 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService204 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService205 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService206 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService207 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService208 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService209 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService210 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService211 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService212 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService213 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService214 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService215 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService216 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService217 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService218 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService219 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService220 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService221 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService222 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService223 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService224 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService225 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService226 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService227 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService228 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService229 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService230 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService231 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService232 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService233 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService234 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService235 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService236 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService237 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService238 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService239 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService240 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService241 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService242 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService243 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService244 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService245 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService246 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService247 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService248 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService249 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService250 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService251 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService252 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService253 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService254 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService255 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService256 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService257 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService258 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService259 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService260 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService261 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService262 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService263 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService264 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService265 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService266 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService267 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService268 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService269 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService270 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService271 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService272 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService273 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService274 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService275 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService276 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService277 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService278 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService279 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService280 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService281 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService282 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService283 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService284 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService285 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService286 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService287 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService288 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService289 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService290 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService291 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService292 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService293 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService294 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService295 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService296 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService297 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService298 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService299 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService300 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService301 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService302 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService303 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService304 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService305 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService306 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService307 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService308 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService309 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService310 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService311 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService312 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService313 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService314 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService315 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService316 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService317 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService318 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService319 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService320 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService321 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService322 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService323 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService324 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService325 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService326 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService327 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService328 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService329 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService330 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService331 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService332 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService333 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService334 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService335 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService336 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService337 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService338 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService339 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService340 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService341 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService342 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService343 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService344 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService345 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService346 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService347 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService348 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService349 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService350 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService351 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService352 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService353 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService354 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService355 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService356 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService357 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService358 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService359 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService360 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService361 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService362 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService363 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService364 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService365 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService366 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService367 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService368 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService369 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService370 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService371 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService372 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService373 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService374 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService375 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService376 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService377 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService378 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService379 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService380 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService381 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService382 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService383 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService384 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService385 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService386 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService387 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService388 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService389 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService390 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService391 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService392 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService393 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService394 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService395 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService396 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService397 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService398 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService399 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService400 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService401 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService402 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService403 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService404 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService405 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService406 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService407 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService408 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService409 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService410 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService411 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService412 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService413 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService414 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService415 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService416 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService417 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService418 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService419 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService420 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService421 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService422 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService423 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService424 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService425 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService426 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService427 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService428 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService429 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService430 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService431 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService432 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService433 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService434 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService435 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService436 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService437 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService438 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService439 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService440 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService441 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService442 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService443 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService444 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService445 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService446 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService447 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService448 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService449 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService450 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService451 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService452 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService453 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService454 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService455 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService456 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService457 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService458 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService459 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService460 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService461 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService462 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService463 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService464 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService465 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService466 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService467 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService468 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService469 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService470 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService471 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService472 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService473 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService474 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService475 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService476 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService477 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService478 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService479 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService480 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService481 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService482 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService483 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService484 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService485 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService486 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService487 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService488 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService489 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService490 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService491 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService492 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService493 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService494 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService495 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService496 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService497 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService498 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService499 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService500 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService501 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService502 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService503 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService504 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService505 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService506 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService507 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService508 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService509 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService510 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService511 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService512 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService513 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService514 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService515 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService516 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService517 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService518 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService519 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService520 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService521 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService522 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService523 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService524 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService525 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService526 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService527 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService528 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService529 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService530 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService531 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService532 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService533 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService534 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService535 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService536 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService537 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService538 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService539 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService540 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService541 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService542 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService543 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService544 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService545 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService546 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService547 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService548 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService549 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService550 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService551 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService552 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService553 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService554 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService555 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService556 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService557 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService558 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService559 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService560 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService561 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService562 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService563 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService564 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService565 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService566 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService567 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService568 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService569 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService570 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService571 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService572 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService573 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService574 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService575 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService576 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService577 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService578 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService579 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService580 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService581 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService582 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService583 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService584 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService585 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService586 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService587 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService588 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService589 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService590 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService591 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService592 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService593 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService594 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService595 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService596 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService597 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService598 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService599 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService600 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService601 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService602 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService603 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService604 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService605 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService606 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService607 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService608 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService609 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService610 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService611 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService612 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService613 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService614 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService615 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService616 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService617 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService618 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService619 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService620 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService621 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService622 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService623 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService624 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService625 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService626 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService627 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService628 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService629 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService630 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService631 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService632 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService633 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService634 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService635 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService636 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService637 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService638 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService639 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService640 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService641 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService642 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService643 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService644 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService645 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService646 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService647 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService648 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService649 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService650 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService651 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService652 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService653 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService654 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService655 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService656 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService657 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService658 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService659 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService660 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService661 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService662 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService663 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService664 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService665 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService666 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService667 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService668 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService669 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService670 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService671 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService672 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService673 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService674 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService675 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService676 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService677 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService678 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService679 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService680 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService681 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService682 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService683 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService684 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService685 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService686 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService687 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService688 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService689 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService690 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService691 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService692 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService693 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService694 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService695 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService696 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService697 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService698 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService699 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService700 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService701 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService702 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService703 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService704 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService705 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService706 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService707 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService708 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService709 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService710 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService711 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService712 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService713 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService714 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService715 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService716 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService717 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService718 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService719 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService720 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService721 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService722 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService723 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService724 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService725 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService726 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService727 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService728 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService729 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService730 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService731 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService732 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService733 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService734 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService735 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService736 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService737 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService738 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService739 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService740 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService741 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService742 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService743 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService744 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService745 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService746 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService747 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService748 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService749 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService750 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService751 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService752 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService753 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService754 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService755 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService756 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService757 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService758 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService759 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService760 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService761 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService762 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService763 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService764 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService765 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService766 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService767 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService768 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService769 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService770 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService771 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService772 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService773 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService774 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService775 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService776 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService777 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService778 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService779 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService780 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService781 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService782 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService783 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService784 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService785 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService786 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService787 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService788 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService789 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService790 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService791 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService792 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService793 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService794 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService795 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService796 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService797 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService798 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService799 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
class IOService800 {
public:
    json importData(const std::string& fmt,const std::string& d) { json r;r[std::string("format")]=fmt;r[std::string("size")]=static_cast<int>(d.size());r[std::string("success")]=true;return r; }
    std::string exportData(const std::string& fmt,const json& d) { if(fmt==std::string("json"))return d.dump();return d.dump(); }
    json importFile(const std::string& fmt,const std::string& path) { std::ifstream f(path);if(!f){json r;r[std::string("error")]=std::string("File not found");return r;}std::ostringstream ss;ss<<f.rdbuf();return importData(fmt,ss.str()); }
    bool exportFile(const std::string& fmt,const json& d,const std::string& path) { std::ofstream f(path);if(!f)return false;f<<exportData(fmt,d);return true; }
    json getSupportedFormats() { json a=json::array();a.push_back(std::string("json"));a.push_back(std::string("csv"));a.push_back(std::string("xml"));a.push_back(std::string("pdf"));return a; }
};
}}}} // namespace