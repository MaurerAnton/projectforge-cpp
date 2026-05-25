# projectforge-wicket: Web UI layer (ported to C++ server-side rendering)
add_library(projectforge_wicket STATIC
    src/WicketApplication.cpp
    src/BasePage.cpp
    src/BaseEditPage.cpp
    src/BaseListPage.cpp
    src/AbstractForm.cpp
    src/FormComponent.cpp
    src/DataTable.cpp
    src/PagingNavigator.cpp
    src/SearchFilter.cpp
    src/TemplateEngine.cpp
    src/ResourceLoader.cpp
    src/UserPagesWicket.cpp
    src/AddressPagesWicket.cpp
    src/TimesheetPagesWicket.cpp
    src/TaskPagesWicket.cpp
    src/FibuPagesWicket.cpp
    src/RechnungEditPage.cpp
    src/CustomerEditPage.cpp
    src/KontoEditPage.cpp
    src/AdminPagesWicket.cpp
    src/CalendarPagesWicket.cpp
    src/ComponentsFactory.cpp
)
target_include_directories(projectforge_wicket PUBLIC include)
target_link_libraries(projectforge_wicket PUBLIC
    projectforge_business
    projectforge_common
    spdlog::spdlog
    nlohmann_json::nlohmann_json
)
