# projectforge-carddav: CardDAV server
add_library(projectforge_carddav STATIC
    src/CardDavServer.cpp
    src/CardDavServlet.cpp
    src/VCardParser.cpp
    src/VCardWriter.cpp
    src/AddressBookResource.cpp
    src/CardDavAuth.cpp
    src/CardDavPropfind.cpp
    src/CardDavReport.cpp
)
target_include_directories(projectforge_carddav PUBLIC include)
target_link_libraries(projectforge_carddav PUBLIC projectforge_rest projectforge_common)
