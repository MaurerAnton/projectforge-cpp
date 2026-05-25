# projectforge-business: Core business logic
add_library(projectforge_business STATIC
    src/BaseDao.cpp
    src/UserDao.cpp
    src/GroupDao.cpp
    src/TaskDao.cpp
    src/TimesheetDao.cpp
    src/AddressDao.cpp
    src/CalendarDao.cpp
    src/BookDao.cpp
    src/FibuDao.cpp
    src/RechnungDao.cpp
    src/KontoDao.cpp
    src/AuftragDao.cpp
    src/KostDao.cpp
    src/DatevDao.cpp
    src/GanttDao.cpp
    src/HrDao.cpp
    src/TeamCalendarDao.cpp
    src/VacationDao.cpp
    src/ConfigurationDao.cpp
    src/AdminService.cpp
    src/AccessChecker.cpp
    src/LoginService.cpp
    src/LdapService.cpp
    src/PollService.cpp
    src/ScriptingService.cpp
    src/JobService.cpp
    src/ImageService.cpp
    src/EmailService.cpp
    src/ExportService.cpp
    src/PdfService.cpp
    src/CacheManager.cpp
    src/DataTransferService.cpp
)
target_include_directories(projectforge_business PUBLIC include)
target_link_libraries(projectforge_business PUBLIC
    projectforge_common
    projectforge_model
    projectforge_jcr
    spdlog::spdlog
    nlohmann_json::nlohmann_json
    sqlite_orm::sqlite_orm
)
