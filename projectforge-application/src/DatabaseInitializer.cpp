// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/start/DatabaseInitializer.hpp"
#include "org/projectforge/common/CryptoHelper.hpp"
#include <spdlog/spdlog.h>

namespace org::projectforge::start {

DatabaseInitializer& DatabaseInitializer::instance() { static DatabaseInitializer i; return i; }

void DatabaseInitializer::init(const std::string& dbPath) {
    storage_ = std::make_unique<Storage>(db::initStorage(dbPath));
    storage_->sync_schema();
    spdlog::get("projectforge")->info("Database initialized at {}", dbPath);
}

DatabaseInitializer::Storage& DatabaseInitializer::getStorage() {
    if (!storage_) throw std::runtime_error("Database not initialized");
    return *storage_;
}

void DatabaseInitializer::seedDefaultData() {
    auto& db = getStorage();
    if (db.count<UserRecord>() == 0) {
        UserRecord admin;
        admin.username = "admin";
        admin.firstName = "Admin";
        admin.lastName = "User";
        admin.email = "admin@projectforge.org";
        auto salt = CryptoHelper::generateSalt();
        admin.salt = salt;
        admin.passwordHash = CryptoHelper::hashPassword("admin123", salt);
        admin.locale = "en";
        admin.created = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        admin.lastUpdate = admin.created;
        db.insert(admin);
        spdlog::get("projectforge")->info("Default admin user created (admin/admin123)");
    }
}
}