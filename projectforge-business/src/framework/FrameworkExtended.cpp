// ProjectForge C++ port — GPL v3 — www.projectforge.org
#include "org/projectforge/framework/persistence/PersistenceFramework.hpp"
#include "org/projectforge/framework/access/AccessControl.hpp"
#include "org/projectforge/framework/jobs/JobFramework.hpp"
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <threadpool>

namespace org::projectforge::framework {

namespace persistence {
    class DatabaseConnectionPool {
        std::queue<void*> connections;
        std::mutex mtx;std::condition_variable cv;
        int maxConnections=10,activeConnections=0;
    public:
        void* acquire(){std::unique_lock lk(mtx);cv.wait(lk,[this]{return!connections.empty()||activeConnections<maxConnections;});if(!connections.empty()){auto c=connections.front();connections.pop();return c;}activeConnections++;return nullptr;}
        void release(void* conn){std::lock_guard lk(mtx);connections.push(conn);cv.notify_one();}
        int getActive(){std::lock_guard lk(mtx);return activeConnections;}
    };
    
    class TransactionManager {
        std::stack<bool> transactionStack;bool inTransaction=false;
    public:
        void begin(){if(inTransaction)throw std::runtime_error("Nested transactions not supported");inTransaction=true;}
        void commit(){if(!inTransaction)throw std::runtime_error("No active transaction");inTransaction=false;}
        void rollback(){if(!inTransaction)throw std::runtime_error("No active transaction");inTransaction=false;}
        bool isActive()const{return inTransaction;}
    };
    
    class EntityCache {
        struct Entry{void* entity;int64_t timestamp;int64_t ttlMs=300000;};
        std::map<std::string,std::map<int64_t,Entry>> cache;std::mutex mtx;
    public:
        template<typename T> std::optional<T*> get(const std::string& type,int64_t id){
            std::lock_guard lk(mtx);auto it=cache.find(type);if(it==cache.end())return std::nullopt;
            auto jt=it->second.find(id);if(jt==it->second.end())return std::nullopt;
            auto now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
            if(now-jt->second.timestamp>jt->second.ttlMs){it->second.erase(jt);return std::nullopt;}
            return std::optional<T*>(static_cast<T*>(jt->second.entity));
        }
        template<typename T> void put(const std::string& type,int64_t id,T* entity){
            std::lock_guard lk(mtx);cache[type][id]={entity,std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()};
        }
        void invalidate(const std::string& type,int64_t id=-1){std::lock_guard lk(mtx);if(id>=0)cache[type].erase(id);else cache.erase(type);}
        void clear(){std::lock_guard lk(mtx);cache.clear();}
    };
}

namespace access {
    class PermissionCache {
        struct PermEntry{bool allowed;int64_t timestamp;};
        std::map<std::string,PermEntry> cache;std::mutex mtx;int64_t ttlMs=60000;
    public:
        std::optional<bool> get(int64_t userId,const std::string& entityType,int64_t entityId,const std::string& op){
            std::lock_guard lk(mtx);std::string key=std::to_string(userId)+":"+entityType+":"+std::to_string(entityId)+":"+op;
            auto it=cache.find(key);if(it==cache.end())return std::nullopt;
            if(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()-it->second.timestamp>ttlMs){cache.erase(it);return std::nullopt;}
            return it->second.allowed;
        }
        void put(int64_t userId,const std::string& entityType,int64_t entityId,const std::string& op,bool allowed){
            std::lock_guard lk(mtx);cache[std::to_string(userId)+":"+entityType+":"+std::to_string(entityId)+":"+op]={allowed,std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()};
        }
        void clear(){std::lock_guard lk(mtx);cache.clear();}
    };
}

namespace jobs {
    class JobScheduler {
        struct ScheduledJob{std::shared_ptr<AbstractJob> job;int64_t intervalMs;int64_t nextRun;std::string cronExpr;};
        std::vector<ScheduledJob> jobs;std::mutex mtx;std::thread schedulerThread;bool running=false;
    public:
        void start(){running=true;schedulerThread=std::thread([this]{while(running){std::this_thread::sleep_for(std::chrono::seconds(1));tick();}});}
        void stop(){running=false;if(schedulerThread.joinable())schedulerThread.join();}
        void schedule(std::shared_ptr<AbstractJob> job,int64_t intervalMs){std::lock_guard lk(mtx);jobs.push_back({job,intervalMs,std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()+intervalMs});}
        void scheduleCron(std::shared_ptr<AbstractJob> job,const std::string& cronExpr){std::lock_guard lk(mtx);jobs.push_back({job,0,0,cronExpr});}
        void tick(){std::lock_guard lk(mtx);auto now=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();for(auto& j:jobs){if(now>=j.nextRun&&j.intervalMs>0){j.nextRun=now+j.intervalMs;std::thread([j](){j.job->execute();}).detach();}}}
        std::vector<std::shared_ptr<AbstractJob>> getScheduledJobs(){std::lock_guard lk(mtx);std::vector<std::shared_ptr<AbstractJob>> r;for(auto& j:jobs)r.push_back(j.job);return r;}
    };
}

} // namespace
