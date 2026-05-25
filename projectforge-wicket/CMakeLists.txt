# projectforge-wicket
file(GLOB_RECURSE projectforge_wicket_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE projectforge_wicket_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

add_library(projectforge_wicket STATIC ${projectforge_wicket_SOURCES})
target_include_directories(projectforge_wicket PUBLIC include)
target_link_libraries(projectforge_wicket PUBLIC projectforge_business projectforge_common spdlog::spdlog nlohmann_json::nlohmann_json)
