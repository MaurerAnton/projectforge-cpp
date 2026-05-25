add_library(plugin_todo STATIC src/TodoPlugin.cpp src/TodoDao.cpp)
target_include_directories(plugin_todo PUBLIC include)
target_link_libraries(plugin_todo PUBLIC projectforge_business)
