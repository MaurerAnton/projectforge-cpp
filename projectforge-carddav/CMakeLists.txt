# projectforge-carddav
file(GLOB_RECURSE projectforge_carddav_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE projectforge_carddav_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

add_library(projectforge_carddav STATIC ${projectforge_carddav_SOURCES})
target_include_directories(projectforge_carddav PUBLIC include)
target_link_libraries(projectforge_carddav PUBLIC projectforge_rest projectforge_common)
