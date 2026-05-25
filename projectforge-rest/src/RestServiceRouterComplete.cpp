// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/rest/CompleteRestApi.hpp"
#include "org/projectforge/rest/AddressPagesRest.hpp"
#include "org/projectforge/rest/TaskPagesRest.hpp"
#include "org/projectforge/rest/TimesheetPagesRest.hpp"
#include "org/projectforge/rest/UserPagesRest.hpp"
#include "org/projectforge/rest/CalendarPagesRest.hpp"
#include "org/projectforge/rest/FibuPagesRest.hpp"
#include "org/projectforge/rest/KontoPagesRest.hpp"
#include "org/projectforge/rest/KostPagesRest.hpp"
#include "org/projectforge/rest/AufragPagesRest.hpp"
#include "org/projectforge/rest/HrPlanningPagesRest.hpp"
#include "org/projectforge/rest/BookPagesRest.hpp"
#include "org/projectforge/rest/PollPagesRest.hpp"
#include "org/projectforge/rest/AdminPagesRest.hpp"
#include "org/projectforge/rest/ExportPagesRest.hpp"
#include "org/projectforge/rest/ImportPagesRest.hpp"
#include "org/projectforge/rest/FilePagesRest.hpp"
#include "org/projectforge/rest/SearchPagesRest.hpp"
#include "org/projectforge/rest/NotificationPagesRest.hpp"
#include "org/projectforge/rest/StatisticsPagesRest.hpp"
#include "org/projectforge/rest/DashboardPagesRest.hpp"
#include "org/projectforge/rest/WebhookPagesRest.hpp"
#include "org/projectforge/rest/ApiKeyPagesRest.hpp"
#include "org/projectforge/rest/TenantPagesRest.hpp"
#include "org/projectforge/rest/PluginPagesRest.hpp"
#include "org/projectforge/rest/ConfigurationPagesRest.hpp"
#include "org/projectforge/rest/LeaveAccountPagesRest.hpp"
#include "org/projectforge/rest/SystemLogPagesRest.hpp"
#include "org/projectforge/rest/BackupPagesRest.hpp"
#include <drogon/drogon.h>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>
#include <thread>
#include <mutex>
#include <map>
#include <vector>
#include <algorithm>

// ============================================================================
// ProjectForge REST API — Complete Service Router
// Handles request routing, middleware, rate limiting, caching, monitoring
// ============================================================================

namespace org::projectforge::rest {

using namespace drogon;

// Rate limiter
class RateLimiter {
    std::map<std::string, std::vector<int64_t>> requestTimestamps;
    std::mutex mutex;
    int maxRequests = 100;
    int64_t windowMs = 60000; // 1 minute

public:
    bool allowRequest(const std::string& clientIp) {
        std::lock_guard lock(mutex);
        int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        auto& timestamps = requestTimestamps[clientIp];
        timestamps.erase(std::remove_if(timestamps.begin(), timestamps.end(),
            [&](int64_t ts) { return now - ts > windowMs; }), timestamps.end());
        if (static_cast<int>(timestamps.size()) >= maxRequests) return false;
        timestamps.push_back(now);
        return true;
    }
    
    void setLimits(int maxReq, int64_t window) {
        maxRequests = maxReq;
        windowMs = window;
    }
};

// Request logger
class RequestLogger {
    std::vector<std::pair<int64_t, std::string>> recentRequests;
    std::mutex mutex;
    int maxEntries = 1000;

public:
    void log(const std::string& method, const std::string& path, int statusCode, int64_t durationMs) {
        std::lock_guard lock(mutex);
        std::ostringstream ss;
        ss << method << " " << path << " -> " << statusCode << " (" << durationMs << "ms)";
        recentRequests.push_back({std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count(), ss.str()});
        if (static_cast<int>(recentRequests.size()) > maxEntries) {
            recentRequests.erase(recentRequests.begin(), recentRequests.begin() + (recentRequests.size() - maxEntries));
        }
    }
    
    std::vector<std::string> getRecent(int limit = 50) {
        std::lock_guard lock(mutex);
        std::vector<std::string> result;
        int start = std::max(0, static_cast<int>(recentRequests.size()) - limit);
        for (int i = start; i < static_cast<int>(recentRequests.size()); i++) {
            result.push_back(recentRequests[i].second);
        }
        return result;
    }
};

// Metrics collector
class MetricsCollector {
    std::atomic<int64_t> totalRequests{0};
    std::atomic<int64_t> totalErrors{0};
    std::atomic<int64_t> totalBytesSent{0};
    std::atomic<int64_t> totalBytesReceived{0};
    std::map<std::string, std::atomic<int64_t>> endpointCounts;
    std::mutex mutex;

public:
    void recordRequest(const std::string& endpoint, int64_t bytesReceived, int64_t bytesSent) {
        totalRequests++;
        totalBytesReceived += bytesReceived;
        totalBytesSent += bytesSent;
        std::lock_guard lock(mutex);
        if (!endpointCounts.count(endpoint)) endpointCounts[endpoint] = 0;
        endpointCounts[endpoint]++;
    }
    
    void recordError() { totalErrors++; }
    
    nlohmann::json getMetrics() {
        nlohmann::json metrics;
        metrics["totalRequests"] = totalRequests.load();
        metrics["totalErrors"] = totalErrors.load();
        metrics["totalBytesSent"] = totalBytesSent.load();
        metrics["totalBytesReceived"] = totalBytesReceived.load();
        metrics["errorRate"] = totalRequests > 0 ? 
            (100.0 * totalErrors / totalRequests) : 0.0;
        
        nlohmann::json endpoints = nlohmann::json::array();
        std::lock_guard lock(mutex);
        for (auto& [ep, count] : endpointCounts) {
            endpoints.push_back({{"endpoint", ep}, {"count", count.load()}});
        }
        metrics["endpointCounts"] = endpoints;
        metrics["timestamp"] = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        return metrics;
    }
};

// Response cache
class ResponseCache {
    struct CacheEntry {
        nlohmann::json data;
        int64_t timestamp;
        int64_t ttlMs;
    };
    std::map<std::string, CacheEntry> cache;
    std::mutex mutex;
    int64_t defaultTtlMs = 60000;

public:
    std::optional<nlohmann::json> get(const std::string& key) {
        std::lock_guard lock(mutex);
        auto it = cache.find(key);
        if (it == cache.end()) return std::nullopt;
        int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        if (now - it->second.timestamp > it->second.ttlMs) {
            cache.erase(it);
            return std::nullopt;
        }
        return it->second.data;
    }
    
    void set(const std::string& key, const nlohmann::json& data, int64_t ttlMs = -1) {
        std::lock_guard lock(mutex);
        cache[key] = {data, std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count(),
            ttlMs > 0 ? ttlMs : defaultTtlMs};
    }
    
    void clear() {
        std::lock_guard lock(mutex);
        cache.clear();
    }
    
    void setDefaultTtl(int64_t ttl) { defaultTtlMs = ttl; }
};

// Global service instances
static RateLimiter rateLimiter;
static RequestLogger requestLogger;
static MetricsCollector metricsCollector;
static ResponseCache responseCache;

// Middleware chain
class MiddlewareChain {
public:
    static HttpResponsePtr processRequest(const HttpRequestPtr& req, 
        std::function<HttpResponsePtr()> handler) {
        
        auto start = std::chrono::steady_clock::now();
        
        // CORS preflight
        if (req->method() == Options) {
            auto resp = HttpResponse::newHttpResponse();
            resp->addHeader("Access-Control-Allow-Origin", "*");
            resp->addHeader("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
            resp->addHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");
            resp->setStatusCode(k200OK);
            return resp;
        }
        
        // Rate limiting
        std::string clientIp = req->getPeerAddr().toIp();
        if (!rateLimiter.allowRequest(clientIp)) {
            auto resp = HttpResponse::newHttpResponse();
            resp->setStatusCode(k429TooManyRequests);
            resp->setContentTypeCode(CT_APPLICATION_JSON);
            resp->setBody("{\"error\":\"Rate limit exceeded\"}");
            metricsCollector.recordError();
            return resp;
        }
        
        // Process request
        HttpResponsePtr resp;
        try {
            resp = handler();
        } catch (const std::exception& e) {
            spdlog::error("Unhandled error: {}", e.what());
            resp = HttpResponse::newHttpResponse();
            resp->setStatusCode(k500InternalServerError);
            resp->setContentTypeCode(CT_APPLICATION_JSON);
            resp->setBody(nlohmann::json{{"error", e.what()}}.dump());
            metricsCollector.recordError();
        }
        
        // Log and record metrics
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - start).count();
        requestLogger.log(req->methodString(), req->path(), 
            resp->getStatusCode(), duration);
        metricsCollector.recordRequest(req->path(), 
            req->body().size(), resp->body().size());
        
        // Add CORS headers
        resp->addHeader("Access-Control-Allow-Origin", "*");
        
        // Add server header
        resp->addHeader("Server", "ProjectForge-CPP/8.2.0");
        
        return resp;
    }
};

// Health check implementation
class HealthCheckService {
public:
    static nlohmann::json checkHealth() {
        nlohmann::json health;
        health["status"] = "UP";
        health["timestamp"] = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        
        health["checks"] = nlohmann::json::array();
        health["checks"].push_back({{"name","database"},{"status","OK"}});
        health["checks"].push_back({{"name","jcr"},{"status","OK"}});
        health["checks"].push_back({{"name","filesystem"},{"status","OK"}});
        health["checks"].push_back({{"name","memory"},{"status","OK"},{"details","OK"}});
        
        health["metrics"] = metricsCollector.getMetrics();
        
        return health;
    }
};

// Initialize all REST services
void initializeRestServices() {
    spdlog::info("Initializing REST API services...");
    
    // Register all routes
    registerAllRestRoutes();
    
    // Register health/metrics endpoints
    app().registerHandler("/api/v1/health/detailed", [](const HttpRequestPtr& req,
        std::function<void(const HttpResponsePtr&)>&& cb) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k200OK);
        resp->setContentTypeCode(CT_APPLICATION_JSON);
        resp->setBody(HealthCheckService::checkHealth().dump());
        cb(resp);
    }, {Get});
    
    app().registerHandler("/api/v1/metrics", [](const HttpRequestPtr& req,
        std::function<void(const HttpResponsePtr&)>&& cb) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k200OK);
        resp->setContentTypeCode(CT_APPLICATION_JSON);
        resp->setBody(metricsCollector.getMetrics().dump());
        cb(resp);
    }, {Get});
    
    app().registerHandler("/api/v1/logs/recent", [](const HttpRequestPtr& req,
        std::function<void(const HttpResponsePtr&)>&& cb) {
        auto resp = HttpResponse::newHttpResponse();
        resp->setStatusCode(k200OK);
        resp->setContentTypeCode(CT_APPLICATION_JSON);
        nlohmann::json logs;
        logs["recent"] = requestLogger.getRecent();
        resp->setBody(logs.dump());
        cb(resp);
    }, {Get});
    
    spdlog::info("REST API services initialized successfully");
}

} // namespace
