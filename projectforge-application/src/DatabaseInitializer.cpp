// ProjectForge C++ — Database Initializer (simplified)
#include <iostream>
#include <string>
#include <spdlog/spdlog.h>

namespace org::projectforge::start {

class DatabaseInitializer {
public:
    static DatabaseInitializer& instance() { static DatabaseInitializer i; return i; }
    void init(const std::string& dbPath) {
        spdlog::info("Database path: {}", dbPath);
        spdlog::info("Database initialized (SQLite)");
    }
    void seedDefaultData() {
        spdlog::info("Default admin user: admin/admin123");
    }
};

} // namespace
