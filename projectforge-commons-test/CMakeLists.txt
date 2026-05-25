# projectforge-commons-test: Test utilities
add_library(projectforge_commons_test STATIC
    src/TestBase.cpp
)
target_include_directories(projectforge_commons_test PUBLIC include)
target_link_libraries(projectforge_commons_test PUBLIC projectforge_common)
