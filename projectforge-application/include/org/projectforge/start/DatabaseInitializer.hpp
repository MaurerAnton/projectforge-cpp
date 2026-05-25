// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <sqlite_orm/sqlite_orm.h>

namespace org::projectforge::start {

namespace db {
    using namespace sqlite_orm;

    inline auto initStorage(const std::string& path) {
        return make_storage(path,
            make_table("users",
                make_column("id", &UserRecord::id, primary_key().autoincrement()),
                make_column("username", &UserRecord::username, unique()),
                make_column("password_hash", &UserRecord::passwordHash),
                make_column("salt", &UserRecord::salt),
                make_column("first_name", &UserRecord::firstName),
                make_column("last_name", &UserRecord::lastName),
                make_column("email", &UserRecord::email),
                make_column("locale", &UserRecord::locale),
                make_column("deactivated", &UserRecord::deactivated),
                make_column("local_user", &UserRecord::localUser),
                make_column("restricted_user", &UserRecord::restrictedUser),
                make_column("created", &UserRecord::created),
                make_column("last_update", &UserRecord::lastUpdate)
            ),
            make_table("tasks",
                make_column("id", &TaskRecord::id, primary_key().autoincrement()),
                make_column("title", &TaskRecord::title),
                make_column("description", &TaskRecord::description),
                make_column("parent_task_id", &TaskRecord::parentTaskId),
                make_column("responsible_user_id", &TaskRecord::responsibleUserId),
                make_column("status", &TaskRecord::status),
                make_column("priority", &TaskRecord::priority),
                make_column("progress", &TaskRecord::progress),
                make_column("start_date", &TaskRecord::startDate),
                make_column("deadline", &TaskRecord::deadline),
                make_column("created", &TaskRecord::created),
                make_column("last_update", &TaskRecord::lastUpdate)
            ),
            make_table("timesheets",
                make_column("id", &TimesheetRecord::id, primary_key().autoincrement()),
                make_column("user_id", &TimesheetRecord::userId),
                make_column("task_id", &TimesheetRecord::taskId),
                make_column("start_time", &TimesheetRecord::startTime),
                make_column("stop_time", &TimesheetRecord::stopTime),
                make_column("duration", &TimesheetRecord::duration),
                make_column("description", &TimesheetRecord::description),
                make_column("created", &TimesheetRecord::created),
                make_column("last_update", &TimesheetRecord::lastUpdate)
            )
        );
    }
}

struct UserRecord {
    int64_t id = -1;
    std::string username;
    std::string passwordHash;
    std::string salt;
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string locale = "en";
    bool deactivated = false;
    bool localUser = true;
    bool restrictedUser = false;
    int64_t created = 0;
    int64_t lastUpdate = 0;
};

struct TaskRecord {
    int64_t id = -1;
    std::string title;
    std::string description;
    int64_t parentTaskId = -1;
    int64_t responsibleUserId = -1;
    std::string status;
    int priority = 3;
    int progress = 0;
    int64_t startDate = 0;
    int64_t deadline = 0;
    int64_t created = 0;
    int64_t lastUpdate = 0;
};

struct TimesheetRecord {
    int64_t id = -1;
    int64_t userId = -1;
    int64_t taskId = -1;
    int64_t startTime = 0;
    int64_t stopTime = 0;
    int64_t duration = 0;
    std::string description;
    int64_t created = 0;
    int64_t lastUpdate = 0;
};

class DatabaseInitializer {
public:
    using Storage = decltype(db::initStorage(std::declval<std::string>()));
    static DatabaseInitializer& instance();
    void init(const std::string& dbPath);
    Storage& getStorage();
    void seedDefaultData();

private:
    std::unique_ptr<Storage> storage_;
};
}