# projectforge-application
file(GLOB_RECURSE projectforge_app_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE projectforge_app_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

add_executable(projectforge_app ${projectforge_app_SOURCES})
target_include_directories(projectforge_app PUBLIC include)
target_link_libraries(projectforge_app PUBLIC projectforge_rest projectforge_business projectforge_common projectforge_carddav projectforge_idp projectforge_wicket drogon::drogon spdlog::spdlog nlohmann_json::nlohmann_json sqlite_orm::sqlite_orm)
