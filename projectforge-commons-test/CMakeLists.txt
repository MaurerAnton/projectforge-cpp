# projectforge-commons-test
file(GLOB_RECURSE projectforge_commons_test_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE projectforge_commons_test_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

add_library(projectforge_commons_test STATIC ${projectforge_commons_test_SOURCES})
target_include_directories(projectforge_commons_test PUBLIC include)
target_link_libraries(projectforge_commons_test PUBLIC projectforge_common)
