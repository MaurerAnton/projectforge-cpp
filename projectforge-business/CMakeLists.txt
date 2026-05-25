# projectforge-business
file(GLOB_RECURSE projectforge_business_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE projectforge_business_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

add_library(projectforge_business STATIC ${projectforge_business_SOURCES})
target_include_directories(projectforge_business PUBLIC include)
target_link_libraries(projectforge_business PUBLIC projectforge_common projectforge_model projectforge_jcr spdlog::spdlog nlohmann_json::nlohmann_json sqlite_orm::sqlite_orm)
