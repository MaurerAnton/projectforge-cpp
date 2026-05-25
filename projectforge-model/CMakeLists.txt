# projectforge-model
file(GLOB_RECURSE projectforge_model_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE projectforge_model_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

add_library(projectforge_model STATIC ${projectforge_model_SOURCES})
target_include_directories(projectforge_model PUBLIC include)
target_link_libraries(projectforge_model PUBLIC nlohmann_json::nlohmann_json sqlite_orm::sqlite_orm)
