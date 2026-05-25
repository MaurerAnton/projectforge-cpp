add_library(plugin_memo STATIC src/MemoPlugin.cpp src/MemoDao.cpp)
target_include_directories(plugin_memo PUBLIC include)
target_link_libraries(plugin_memo PUBLIC projectforge_business)
