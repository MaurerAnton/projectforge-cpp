# projectforge-common
file(GLOB_RECURSE projectforge_common_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE projectforge_common_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

add_library(projectforge_common STATIC ${projectforge_common_SOURCES})
target_include_directories(projectforge_common PUBLIC 
    include
    ${nlohmann_json_SOURCE_DIR}/include
)
target_link_libraries(projectforge_common PUBLIC
    spdlog::spdlog
    nlohmann_json::nlohmann_json
    Threads::Threads
)
