// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once
#include <string>
#include <vector>
#include <functional>
#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>
#include <memory>
#include <spdlog/spdlog.h>

namespace org::projectforge::framework::jobs {

enum class JobStatus { CREATED, RUNNING, FINISHED, FAILED, CANCELLED };

struct JobResult {
    JobStatus status = JobStatus::CREATED;
    std::string message;
    int progressPercent = 0;
    int64_t startedAt = 0, finishedAt = 0;
    int64_t durationMillis = 0;
    std::string toJson() const {
        std::ostringstream ss;
        ss << "{\"status\":\"" << (int)status << "\",\"message\":\"" << message
           << "\",\"progress\":" << progressPercent << "}";
        return ss.str();
    }
};

class AbstractJob {
public:
    AbstractJob(const std::string& name) : name_(name) {
        createdTime_ = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
    }
    virtual ~AbstractJob() = default;

    virtual void execute() = 0;
    virtual std::string getName() const { return name_; }
    virtual std::string getDescription() const { return description_; }

    JobResult getResult() const { return result_; }
    JobStatus getStatus() const { return status_.load(); }
    int getProgress() const { return progress_.load(); }
    int64_t getCreatedTime() const { return createdTime_; }
    bool isRunning() const { return status_ == JobStatus::RUNNING; }
    bool isFinished() const { return status_ == JobStatus::FINISHED || status_ == JobStatus::FAILED; }

    void cancel() { cancelled_ = true; }
    bool isCancelled() const { return cancelled_; }

    void setDescription(const std::string& d) { description_ = d; }

protected:
    void setProgress(int p) { progress_ = std::clamp(p, 0, 100); }
    void setStatus(JobStatus s) { status_ = s; }
    void setResult(const JobResult& r) { result_ = r; }
    void setMessage(const std::string& m) { result_.message = m; }

    std::string name_, description_;
    std::atomic<JobStatus> status_{JobStatus::CREATED};
    std::atomic<int> progress_{0};
    std::atomic<bool> cancelled_{false};
    int64_t createdTime_ = 0;
    JobResult result_;
};

class JobHandler {
public:
    static JobHandler& instance() { static JobHandler jh; return jh; }

    void addJob(std::shared_ptr<AbstractJob> job) {
        std::lock_guard lock(mutex_);
        jobs_.push_back(job);
        spdlog::info("Job added: {}", job->getName());
    }

    void executeJob(std::shared_ptr<AbstractJob> job) {
        job->setStatus(JobStatus::RUNNING);
        spdlog::info("Job started: {}", job->getName());
        auto start = std::chrono::system_clock::now();
        try {
            job->execute();
            auto end = std::chrono::system_clock::now();
            job->result_.durationMillis = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            if (!job->isCancelled()) {
                job->setStatus(JobStatus::FINISHED);
                job->setProgress(100);
            } else {
                job->setStatus(JobStatus::CANCELLED);
            }
        } catch (const std::exception& e) {
            job->setStatus(JobStatus::FAILED);
            job->setMessage(e.what());
            spdlog::error("Job failed: {} - {}", job->getName(), e.what());
        }
        spdlog::info("Job finished: {} ({})", job->getName(), job->result_.message);
    }

    void runPendingJobs() {
        std::vector<std::shared_ptr<AbstractJob>> pending;
        {
            std::lock_guard lock(mutex_);
            for (auto& job : jobs_) {
                if (job->getStatus() == JobStatus::CREATED) pending.push_back(job);
            }
        }
        for (auto& job : pending) executeJob(job);
    }

    void runAllJobs() {
        std::vector<std::shared_ptr<AbstractJob>> all;
        {
            std::lock_guard lock(mutex_);
            all = jobs_;
        }
        for (auto& job : all) {
            if (!job->isFinished()) executeJob(job);
        }
    }

    void tidyUp(int64_t keepTerminatedMs = 3600000) {
        std::lock_guard lock(mutex_);
        int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
        jobs_.erase(std::remove_if(jobs_.begin(), jobs_.end(), [&](auto& job) {
            if (!job->isFinished()) return false;
            return (now - job->result_.finishedAt) > keepTerminatedMs;
        }), jobs_.end());
    }

    std::vector<std::shared_ptr<AbstractJob>> getJobs() const {
        std::lock_guard lock(mutex_);
        return jobs_;
    }

    std::vector<std::shared_ptr<AbstractJob>> getActiveJobs() const {
        std::lock_guard lock(mutex_);
        std::vector<std::shared_ptr<AbstractJob>> result;
        for (auto& j : jobs_) if (!j->isFinished()) result.push_back(j);
        return result;
    }

private:
    mutable std::mutex mutex_;
    std::vector<std::shared_ptr<AbstractJob>> jobs_;
    JobHandler() = default;
};

} // namespace
