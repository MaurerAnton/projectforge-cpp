# projectforge-model: Data transfer objects / REST model
add_library(projectforge_model STATIC
    src/AbstractBaseObject.cpp
    src/UserObject.cpp
    src/TaskObject.cpp
    src/TimesheetObject.cpp
    src/TimesheetTemplateObject.cpp
    src/Cost2Object.cpp
    src/AddressObject.cpp
    src/CalendarObject.cpp
    src/CustomerDateAndTimeSerialize.cpp
    src/CustomerDateAndTimeDeserialize.cpp
    src/RestPaths.cpp
)
target_include_directories(projectforge_model PUBLIC include)
target_link_libraries(projectforge_model PUBLIC
    nlohmann_json::nlohmann_json
    sqlite_orm::sqlite_orm
)
