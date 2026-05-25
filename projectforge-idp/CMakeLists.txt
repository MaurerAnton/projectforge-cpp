# projectforge-idp: Identity Provider (OAuth2/OIDC)
add_library(projectforge_idp STATIC
    src/IdpServer.cpp
    src/OAuth2Handler.cpp
    src/OidcHandler.cpp
    src/JwtTokenService.cpp
    src/UserIdentityProvider.cpp
    src/AuthorizationEndpoint.cpp
    src/TokenEndpoint.cpp
    src/ClientRegistry.cpp
)
target_include_directories(projectforge_idp PUBLIC include)
target_link_libraries(projectforge_idp PUBLIC projectforge_rest projectforge_common jwt-cpp::jwt-cpp)
