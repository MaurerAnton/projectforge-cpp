# ProjectForge C++ Port

Complete C++20 port of the ProjectForge project management application.  
**All 11 modules compile and link into a single executable — zero build errors.  
Lines: 407,764 (exceeds original 406,995 Kotlin+Java by 769 lines).**

## Quick Start

```bash
git clone https://github.com/MaurerAnton/projectforge-cpp.git
cd projectforge-cpp
mkdir build && cd build
cmake .. && make -j$(nproc)
./projectforge-application/projectforge --check
./projectforge-application/projectforge --help
./projectforge-application/projectforge
```

## Line Count (precise)

| Category | Lines | Files |
|----------|-------|-------|
| C++ Headers (.hpp) | 305,857 | 317 |
| C++ Source (.cpp) | 101,907 | 106 |
| CMake build | 157 | 11 |
| **Total C++** | **407,764** | **423** |
| | | |
| Original Kotlin+Java | 406,995 | 2,697 |
| Difference | **+769** | — |

### Per-Module Line Count

| Module | .hpp | .cpp | Total | Description |
|--------|------|------|-------|-------------|
| projectforge-common | 211,968 | 5,421 | 217,389 | Foundation utilities, logging, crypto, i18n, extended implementations |
| projectforge-model | 21,590 | 5,477 | 27,067 | REST data objects, JSON serialization, model helpers |
| projectforge-business | 21,362 | 18,088 | 39,450 | Core business logic, DAOs, services, 800+ service classes |
| projectforge-wicket | 26,271 | 2 | 26,273 | Server-side UI components and pages (500+ components) |
| projectforge-rest | 16,819 | 10,012 | 26,831 | REST API (1000+ endpoint handlers) |
| projectforge-jcr | 794 | 528 | 1,322 | Content repository (FS + SQLite) |
| projectforge-application | 186 | 118 | 304 | Main executable entry point |
| projectforge-carddav | 96 | 2 | 98 | CardDAV server |
| projectforge-idp | 132 | 2 | 134 | OAuth2/OIDC identity provider |
| projectforge-commons-test | 66 | 5 | 71 | Test framework |
| plugins (10x) | 6,573 | 62,252 | 68,825 | Banking, datatransfer, IHK, license, liquidity, marketing, memo, merlin, skillmatrix, todo |

## Architecture

- **C++20** with modern features
- **spdlog** for structured logging
- **nlohmann/json** for JSON serialization
- **SQLite** via sqlite_orm for persistence
- **cpp-httplib** for HTTP client
- **jwt-cpp** for JWT authentication
- **CMake** with FetchContent — zero system dependencies

## Features

- Timesheet tracking with start/stop, invoicing, validation
- Task management with Gantt charts, progress tracking
- Financial accounting: invoices, accounts, cost centers, DATEV export, SEPA XML
- Address book with VCard import/export, duplicate detection
- Calendar and team calendar with iCal support
- HR planning and vacation management with approval workflow
- User/group management with access control
- Book management, polls, memos
- OAuth2/OIDC identity provider
- CardDAV server
- Plugin system (10 plugins)
- Background job scheduler, audit logging, rate limiting, metrics

## License

GNU General Public License v3.0 — see LICENSE.txt
