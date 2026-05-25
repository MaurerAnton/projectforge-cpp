// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include "org/projectforge/business/BaseDao.hpp"
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <spdlog/spdlog.h>

namespace org::projectforge::business::system {

struct ConfigurationEntry {
    DECLARE_ENTITY_FIELDS();
    std::string key;
    std::string value;
    std::string description;
    std::string type = "STRING";
    bool encrypted = false;
};

class ConfigurationDao : public BaseDao<ConfigurationEntry> {
public:
    explicit ConfigurationDao(Storage& storage) : BaseDao<ConfigurationEntry>(storage) {}
    std::optional<std::string> getValue(const std::string& key) {
        auto all = getAll();
        for(auto& c : all) if(c.key==key && !c.deleted) return c.value;
        return std::nullopt;
    }
    void setValue(const std::string& key, const std::string& value) {
        auto all = getAll();
        for(auto& c : all) {
            if(c.key==key) { c.value=value; save(c); return; }
        }
        ConfigurationEntry e; e.key=key; e.value=value; save(e);
    }
    bool getBool(const std::string& key, bool def=false) {
        auto v = getValue(key);
        if(!v.has_value()) return def;
        std::string s = *v;
        for(char& c : s) c=std::tolower(c);
        return s=="true"||s=="1"||s=="yes";
    }
    int getInt(const std::string& key, int def=0) {
        auto v = getValue(key); return v.has_value()?std::stoi(*v):def;
    }
};

struct SystemLogEntry {
    DECLARE_ENTITY_FIELDS();
    std::string level;
    std::string message;
    std::string category;
    int64_t timestamp = 0;
    int64_t userId = -1;
};

class SystemLogDao : public BaseDao<SystemLogEntry> {
public:
    explicit SystemLogDao(Storage& storage) : BaseDao<SystemLogEntry>(storage) {}
    void log(const std::string& level, const std::string& msg, const std::string& cat="SYSTEM", int64_t uid=-1) {
        SystemLogEntry e;
        e.level=level; e.message=msg; e.category=cat; e.userId=uid;
        e.timestamp=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        save(e);
        spdlog::info("[{}] {}",cat,msg);
    }
    std::vector<SystemLogEntry> getRecent(int limit=100) {
        auto all = getAll();
        std::sort(all.begin(),all.end(),[](auto&a,auto&b){return a.timestamp>b.timestamp;});
        if((int)all.size()>limit) all.resize(limit);
        return all;
    }
    std::vector<SystemLogEntry> getByCategory(const std::string& cat, int limit=100) {
        auto all = getAll(); std::vector<SystemLogEntry> r;
        for(auto& l : all) if(l.category==cat) r.push_back(l);
        return r;
    }
};

// Backup service
class BackupService {
public:
    static void createBackup(const std::string& dbPath, const std::string& backupDir) {
        auto now = std::chrono::system_clock::now();
        auto t = std::chrono::system_clock::to_time_t(now);
        std::ostringstream fn;
        fn<<"projectforge_backup_"<<std::put_time(std::localtime(&t),"%Y%m%d_%H%M%S")<<".db";
        std::string backupPath = backupDir + "/" + fn.str();
        std::filesystem::create_directories(backupDir);
        std::filesystem::copy_file(dbPath, backupPath, std::filesystem::copy_options::overwrite_existing);
        spdlog::info("Backup created: {}", backupPath);
    }
    static void purgeOldBackups(const std::string& backupDir, int keepDays=30) {
        auto cutoff = std::chrono::system_clock::now() - std::chrono::hours(24*keepDays);
        for(auto& entry : std::filesystem::directory_iterator(backupDir)) {
            if(entry.is_regular_file()) {
                auto ftime = entry.last_write_time();
                if(decltype(ftime)::clock::to_time_t(ftime) < std::chrono::system_clock::to_time_t(cutoff)) {
                    std::filesystem::remove(entry.path());
                }
            }
        }
    }
};

} // namespace
