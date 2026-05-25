# projectforge-jcr
file(GLOB_RECURSE projectforge_jcr_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE projectforge_jcr_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

add_library(projectforge_jcr STATIC ${projectforge_jcr_SOURCES})
target_include_directories(projectforge_jcr PUBLIC include)
target_link_libraries(projectforge_jcr PUBLIC nlohmann_json::nlohmann_json spdlog::spdlog sqlite_orm::sqlite_orm)
