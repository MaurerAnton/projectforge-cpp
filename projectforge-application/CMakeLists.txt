# projectforge-application — Main executable
file(GLOB_RECURSE APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE APP_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

add_executable(projectforge ${APP_SOURCES})
target_include_directories(projectforge PUBLIC include)
target_link_libraries(projectforge PRIVATE
    -Wl,--whole-archive
    projectforge_common
    projectforge_model
    projectforge_jcr
    projectforge_business
    projectforge_rest
    projectforge_carddav
    projectforge_idp
    projectforge_wicket
    projectforge_plugins
    -Wl,--no-whole-archive
    spdlog::spdlog
    fmt::fmt
    nlohmann_json::nlohmann_json
    Threads::Threads
    ${CMAKE_DL_LIBS}
)
