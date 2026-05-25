# ProjectForge C++ Port

Complete C++20 port of the ProjectForge project management application.

## Overview

ProjectForge is a comprehensive project management system covering:
- Timesheet tracking
- Task management with Gantt charts
- Financial accounting (invoices, accounts, cost centers, DATEV export, SEPA)
- Address book with VCard import/export
- Calendar and team calendar with iCal support
- HR planning and vacation management
- User/group management with access control
- Book management, polls, memos
- OAuth2/OIDC identity provider
- CardDAV server
- Plugin system (banking, data transfer, marketing, skill matrix, etc.)

## Architecture

The C++ port uses:
- **C++20** with modern features
- **Drogon** for HTTP serving
- **SQLite** via sqlite_orm for persistence
- **nlohmann/json** for serialization
- **spdlog** for logging
- **jwt-cpp** for JWT authentication
- **CMake** with FetchContent for dependency management

## Building

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
./bin/projectforge_app --port 8080
```

## Modules

| Module | Lines | Description |
|--------|-------|-------------|
| projectforge-common | ~3K | Foundation utilities |
| projectforge-model | ~1K | REST data objects |
| projectforge-jcr | ~1K | Content repository |
| projectforge-business | ~40K | Core business logic |
| projectforge-rest | ~10K | REST API |
| projectforge-wicket | ~8K | Server-side rendering |
| projectforge-application | ~1K | Entry point |
| projectforge-carddav | ~1K | CardDAV server |
| projectforge-idp | ~1K | OAuth2/OIDC |
| projectforge-commons-test | ~0.5K | Test framework |
| plugins (10x) | ~8K | Plugin implementations |

## License

GNU General Public License v3.0 — see LICENSE.txt
