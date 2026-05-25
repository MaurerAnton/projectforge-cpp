// ProjectForge C++ port — GPL v3

#pragma once
#include <string>
#include <vector>
#include <map>
#include <spdlog/spdlog.h>
#include <nlohmann/json.hpp>
#include <chrono>
namespace com { namespace projectforge { namespace workflow { namespace extended {
using json = nlohmann::json;
class Workflow1 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow2 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow3 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow4 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow5 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow6 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow7 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow8 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow9 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow10 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow11 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow12 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow13 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow14 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow15 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow16 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow17 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow18 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow19 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow20 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow21 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow22 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow23 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow24 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow25 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow26 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow27 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow28 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow29 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow30 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow31 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow32 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow33 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow34 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow35 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow36 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow37 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow38 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow39 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow40 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow41 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow42 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow43 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow44 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow45 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow46 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow47 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow48 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow49 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow50 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow51 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow52 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow53 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow54 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow55 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow56 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow57 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow58 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow59 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow60 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow61 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow62 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow63 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow64 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow65 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow66 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow67 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow68 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow69 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow70 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow71 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow72 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow73 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow74 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow75 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow76 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow77 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow78 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow79 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow80 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow81 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow82 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow83 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow84 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow85 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow86 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow87 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow88 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow89 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow90 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow91 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow92 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow93 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow94 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow95 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow96 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow97 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow98 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow99 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow100 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow101 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow102 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow103 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow104 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow105 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow106 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow107 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow108 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow109 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow110 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow111 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow112 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow113 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow114 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow115 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow116 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow117 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow118 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow119 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow120 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow121 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow122 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow123 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow124 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow125 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow126 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow127 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow128 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow129 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow130 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow131 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow132 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow133 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow134 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow135 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow136 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow137 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow138 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow139 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow140 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow141 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow142 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow143 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow144 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow145 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow146 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow147 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow148 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow149 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow150 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow151 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow152 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow153 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow154 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow155 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow156 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow157 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow158 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow159 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow160 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow161 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow162 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow163 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow164 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow165 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow166 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow167 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow168 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow169 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow170 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow171 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow172 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow173 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow174 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow175 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow176 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow177 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow178 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow179 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow180 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow181 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow182 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow183 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow184 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow185 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow186 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow187 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow188 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow189 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow190 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow191 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow192 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow193 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow194 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow195 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow196 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow197 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow198 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow199 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow200 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow201 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow202 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow203 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow204 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow205 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow206 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow207 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow208 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow209 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow210 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow211 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow212 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow213 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow214 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow215 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow216 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow217 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow218 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow219 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow220 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow221 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow222 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow223 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow224 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow225 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow226 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow227 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow228 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow229 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow230 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow231 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow232 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow233 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow234 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow235 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow236 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow237 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow238 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow239 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow240 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow241 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow242 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow243 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow244 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow245 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow246 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow247 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow248 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow249 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow250 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow251 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow252 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow253 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow254 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow255 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow256 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow257 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow258 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow259 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow260 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow261 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow262 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow263 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow264 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow265 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow266 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow267 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow268 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow269 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow270 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow271 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow272 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow273 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow274 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow275 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow276 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow277 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow278 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow279 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow280 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow281 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow282 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow283 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow284 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow285 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow286 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow287 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow288 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow289 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow290 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow291 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow292 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow293 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow294 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow295 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow296 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow297 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow298 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow299 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow300 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow301 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow302 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow303 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow304 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow305 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow306 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow307 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow308 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow309 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow310 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow311 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow312 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow313 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow314 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow315 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow316 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow317 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow318 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow319 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow320 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow321 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow322 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow323 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow324 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow325 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow326 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow327 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow328 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow329 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow330 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow331 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow332 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow333 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow334 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow335 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow336 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow337 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow338 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow339 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow340 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow341 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow342 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow343 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow344 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow345 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow346 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow347 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow348 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow349 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow350 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow351 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow352 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow353 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow354 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow355 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow356 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow357 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow358 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow359 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow360 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow361 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow362 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow363 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow364 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow365 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow366 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow367 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow368 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow369 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow370 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow371 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow372 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow373 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow374 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow375 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow376 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow377 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow378 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow379 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow380 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow381 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow382 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow383 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow384 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow385 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow386 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow387 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow388 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow389 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow390 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow391 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow392 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow393 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow394 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow395 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow396 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow397 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow398 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow399 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow400 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow401 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow402 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow403 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow404 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow405 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow406 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow407 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow408 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow409 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow410 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow411 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow412 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow413 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow414 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow415 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow416 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow417 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow418 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow419 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow420 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow421 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow422 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow423 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow424 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow425 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow426 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow427 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow428 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow429 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow430 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow431 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow432 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow433 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow434 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow435 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow436 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow437 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow438 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow439 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow440 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow441 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow442 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow443 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow444 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow445 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow446 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow447 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow448 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow449 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow450 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow451 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow452 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow453 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow454 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow455 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow456 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow457 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow458 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow459 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow460 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow461 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow462 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow463 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow464 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow465 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow466 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow467 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow468 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow469 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow470 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow471 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow472 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow473 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow474 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow475 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow476 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow477 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow478 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow479 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow480 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow481 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow482 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow483 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow484 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow485 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow486 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow487 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow488 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow489 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow490 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow491 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow492 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow493 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow494 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow495 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow496 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow497 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow498 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow499 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
class Workflow500 {
public:
    struct Step { std::string name,assignee,status="PENDING",action; int order=0;int64_t deadline=0,completedAt=0; std::vector<std::string> transitions; json data; };
    struct Instance { int64_t id;std::string name,status="RUNNING";int currentStep=0;std::vector<Step> steps;int64_t createdAt=0,finishedAt=0;json context; };
    Instance createInstance(const std::string& name) { Instance inst;inst.id=nextId_++;inst.name=name;inst.createdAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();return inst; }
    void addStep(Instance& inst,const Step& step) { inst.steps.push_back(step); }
    bool advanceStep(Instance& inst) { if(inst.currentStep<(int)inst.steps.size()-1){inst.steps[inst.currentStep].status="COMPLETED";inst.steps[inst.currentStep].completedAt=std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();inst.currentStep++;inst.steps[inst.currentStep].status="ACTIVE";return true;}inst.status="COMPLETED";return false; }
    json getStatus(const Instance& inst) { json s;s["id"]=inst.id;s["name"]=inst.name;s["status"]=inst.status;s["currentStep"]=inst.currentStep;s["totalSteps"]=inst.steps.size();return s; }
private:
    int64_t nextId_=1;
};
}}}} // namespace