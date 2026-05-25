# projectforge-jcr: Java Content Repository abstraction
add_library(projectforge_jcr STATIC
    src/JcrNode.cpp
    src/JcrSession.cpp
    src/JcrRepository.cpp
    src/JcrProperty.cpp
    src/JcrContent.cpp
    src/FileSystemJcrBackend.cpp
    src/SqliteJcrBackend.cpp
    src/ContentRepositoryManager.cpp
    src/JcrUtils.cpp
    src/ZipHandler.cpp
)
target_include_directories(projectforge_jcr PUBLIC include)
target_link_libraries(projectforge_jcr PUBLIC
    nlohmann_json::nlohmann_json
    spdlog::spdlog
    sqlite_orm::sqlite_orm
)
