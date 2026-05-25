# projectforge-rest
file(GLOB_RECURSE projectforge_rest_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE projectforge_rest_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

add_library(projectforge_rest STATIC ${projectforge_rest_SOURCES})
target_include_directories(projectforge_rest PUBLIC include)
target_link_libraries(projectforge_rest PUBLIC projectforge_business projectforge_common httplib::httplib nlohmann_json::nlohmann_json spdlog::spdlog jwt-cpp::jwt-cpp)
