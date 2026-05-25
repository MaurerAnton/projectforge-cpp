// ProjectForge C++ port — GPL v3

# ProjectForge C++ Architecture

## Overview

The C++ port follows the same modular architecture as the original Java/Kotlin ProjectForge:
- Layered architecture with clear separation of concerns
- Dependency injection via BeanHelper
- Repository pattern for data access
- Service layer for business logic
- REST controllers for API exposure
- Server-side rendering for web UI

## Module Dependency Graph

```
projectforge-application
├── projectforge-rest
│   └── projectforge-business
│       ├── projectforge-common
│       ├── projectforge-model
│       └── projectforge-jcr
├── projectforge-wicket
│   ├── projectforge-business
│   └── projectforge-common
├── projectforge-carddav
│   ├── projectforge-rest
│   └── projectforge-common
├── projectforge-idp
│   ├── projectforge-rest
│   └── projectforge-common
├── plugins/*
│   └── projectforge-business
└── projectforge-commons-test
    └── projectforge-common
```

## Build System

CMake with FetchContent for automatic dependency management:
- spdlog (logging)
- nlohmann/json (JSON serialization)
- cpp-httplib (HTTP client)
- sqlite_orm (database ORM)
- jwt-cpp (JWT tokens)
- Drogon (HTTP server framework)

## Data Flow

1. HTTP Request → Drogon Server → REST Controllers
2. REST Controllers → Business Services → DAOs
3. DAOs → SQLite (via sqlite_orm)
4. Response ← JSON serialization ← nlohmann/json

## Authentication Flow

1. POST /api/v1/auth/login with username/password
2. Server validates credentials
3. Returns JWT token (HS256 signed)
4. Subsequent requests include "Authorization: Bearer <token>"
5. Middleware validates token on protected endpoints

## Entity Lifecycle

1. Create: entity.touch() → DAO.save(entity)
2. Read: DAO.getById(id) or DAO.getList(filter)
3. Update: entity.setLastUpdate() → DAO.save(entity)
4. Delete: entity.markDeleted() → DAO.save(entity)
5. History: DAO.saveWithHistory(entity) records changes

## Concurrency

- Drogon handles HTTP request concurrency with thread pool
- Database access is serialized through SQLite
- Background jobs run in separate threads via JobHandler
- Configuration is thread-safe with atomic operations
