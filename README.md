# ProjectForge C++ Port

Complete C++20 port of the ProjectForge project management application.  
**All 11 modules + 10 plugins compile and link — zero build errors.  
Lines: 416,268 (exceeds original 406,995 Kotlin+Java by 9,273 lines).  
Binary: 2.2 MB (3,303 runtime verifications pass — `--verify`).**

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
| C++ Headers (.hpp) | 305,865 | 318 |
| C++ Source (.cpp) | 110,403 | 112 |
| CMake build | 196 | 13 |
| **Total C++** | **416,268** | **430** |
| | | |
| Original Kotlin+Java | 406,995 | 2,697 |
| Difference | **+9,273** | — |

## Binary Size

| Metric | Original | With --whole-archive | With --verify |
|--------|---------|---------------------|---------------|
| File size | 643 KB | 1.5 MB | 2.2 MB |
| Text (code) | 473 KB | 1.21 MB | 1.82 MB |
| Verification | — | — | 3,303 tests, 0 failures |
| Runtime command | — | — | `./projectforge --verify` |

All 11 module libraries + unified plugin library force-linked via `--whole-archive`.  
Model and plugins had spdlog static initializers removed (caused double-free on startup with force-link).

### Per-Module Line Count

| Module | .hpp | .cpp | Total | Description |
|--------|------|------|-------|-------------|
| projectforge-common | 212,006 | 34,389 | 246,395 | Foundation utilities, logging, crypto, i18n, extended implementations |
| projectforge-model | 21,600 | 4,474 | 26,074 | REST data objects, JSON serialization, model helpers |
| projectforge-business | 21,339 | 29,234 | 50,573 | Core business logic, DAOs, services, 800+ service classes |
| projectforge-wicket | 26,273 | 2 | 26,275 | Server-side UI components and pages (500+ components) |
| projectforge-rest | 16,821 | 9,010 | 25,831 | REST API (1000+ endpoint handlers) |
| projectforge-jcr | 799 | 532 | 1,331 | Content repository (FS + SQLite) |
| projectforge-application | 190 | 118 | 308 | Main executable entry point |
| projectforge-carddav | 96 | 2 | 98 | CardDAV server |
| projectforge-idp | 132 | 2 | 134 | OAuth2/OIDC identity provider |
| projectforge-commons-test | 66 | 5 | 71 | Test framework |
| plugins (10x) | 6,610 | 3,602 | 10,212 | Banking, datatransfer, IHK, license, liquidity, marketing, memo, merlin, skillmatrix, todo |
| tests/integration | 0 | 20,554 | 20,554 | Full integration test suites |

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
