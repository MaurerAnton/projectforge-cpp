# projectforge-rest: REST API layer
add_library(projectforge_rest STATIC
    src/RestController.cpp
    src/RestRouter.cpp
    src/RestAuth.cpp
    src/JsonSerializer.cpp
    src/ResponseBuilder.cpp
    src/UserPagesRest.cpp
    src/TimesheetPagesRest.cpp
    src/TaskPagesRest.cpp
    src/AddressPagesRest.cpp
    src/CalendarPagesRest.cpp
    src/FibuPagesRest.cpp
    src/RechnungPagesRest.cpp
    src/KontoPagesRest.cpp
    src/MyMenuPageRest.cpp
    src/ChangePasswordPageRest.cpp
    src/IndexRest.cpp
    src/VacationExportPageRest.cpp
    src/HRPlanningPagesRest.cpp
    src/VisitorbookPagesRest.cpp
)
target_include_directories(projectforge_rest PUBLIC include)
target_link_libraries(projectforge_rest PUBLIC
    projectforge_business
    projectforge_common
    httplib::httplib
    nlohmann_json::nlohmann_json
    spdlog::spdlog
    jwt-cpp::jwt-cpp
)
