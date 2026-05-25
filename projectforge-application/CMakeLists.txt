# projectforge-application: Main entry point
add_executable(projectforge_app
    src/Main.cpp
    src/ProjectForgeServer.cpp
    src/ProjectForgeConfig.cpp
    src/DatabaseInitializer.cpp
    src/PluginLoader.cpp
    src/SpringBootCompat.cpp
)
target_link_libraries(projectforge_app PRIVATE
    projectforge_rest
    projectforge_business
    projectforge_common
    projectforge_carddav
    projectforge_idp
    projectforge_wicket
    drogon::drogon
    spdlog::spdlog
    nlohmann_json::nlohmann_json
    sqlite_orm::sqlite_orm
)
