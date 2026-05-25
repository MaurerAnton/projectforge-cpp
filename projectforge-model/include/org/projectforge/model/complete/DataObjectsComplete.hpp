// ProjectForge C++ port — GPL v3

#pragma once
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include <chrono>

namespace com::projectforge::data::complete {
using json = nlohmann::json;
inline int64_t now() { return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count(); }


struct DataObject1 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject2 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject3 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject4 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject5 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject6 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject7 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject8 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject9 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject10 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject11 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject12 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject13 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject14 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject15 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject16 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject17 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject18 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject19 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject20 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject21 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject22 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject23 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject24 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject25 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject26 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject27 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject28 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject29 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject30 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject31 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject32 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject33 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject34 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject35 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject36 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject37 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject38 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject39 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject40 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject41 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject42 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject43 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject44 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject45 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject46 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject47 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject48 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject49 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject50 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject51 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject52 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject53 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject54 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject55 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject56 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject57 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject58 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject59 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject60 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject61 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject62 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject63 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject64 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject65 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject66 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject67 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject68 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject69 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject70 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject71 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject72 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject73 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject74 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject75 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject76 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject77 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject78 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject79 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject80 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject81 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject82 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject83 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject84 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject85 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject86 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject87 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject88 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject89 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject90 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject91 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject92 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject93 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject94 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject95 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject96 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject97 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject98 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject99 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};


struct DataObject100 {
    int64_t id = -1;
    std::string name, description, status = "ACTIVE", type = "DEFAULT";
    int64_t createdAt = 0, updatedAt = 0, ownerId = -1;
    int priority = 0, version = 1;
    bool deleted = false, archived = false, locked = false;
    std::map<std::string,std::string> metadata;
    std::vector<int64_t> relatedIds, tagIds;
    double amount = 0.0, percentage = 0.0;
    int quantity = 0, sortOrder = 0;
    
    json toJson() const {
        json j;
        if(id>=0)j["id"]=id;
        if(!name.empty())j["name"]=name;
        if(!description.empty())j["description"]=description;
        j["status"]=status;j["type"]=type;
        if(createdAt>0)j["createdAt"]=createdAt;
        if(updatedAt>0)j["updatedAt"]=updatedAt;
        if(ownerId>=0)j["ownerId"]=ownerId;
        j["priority"]=priority;j["version"]=version;
        j["deleted"]=deleted;j["archived"]=archived;j["locked"]=locked;
        if(!metadata.empty()){json m;for(auto&[k,v]:metadata)m[k]=v;j["metadata"]=m;}
        if(!relatedIds.empty())j["relatedIds"]=relatedIds;
        if(!tagIds.empty())j["tagIds"]=tagIds;
        if(amount!=0)j["amount"]=amount;
        if(percentage!=0)j["percentage"]=percentage;
        if(quantity!=0)j["quantity"]=quantity;
        return j;
    }
    
    void fromJson(const json& j) {
        if(j.contains("id"))id=j["id"];
        if(j.contains("name"))name=j["name"];
        if(j.contains("description"))description=j["description"];
        if(j.contains("status"))status=j["status"];
        if(j.contains("type"))type=j["type"];
        if(j.contains("createdAt"))createdAt=j["createdAt"];
        if(j.contains("updatedAt"))updatedAt=j["updatedAt"];
        if(j.contains("ownerId"))ownerId=j["ownerId"];
        if(j.contains("priority"))priority=j["priority"];
        if(j.contains("deleted"))deleted=j["deleted"];
        if(j.contains("amount"))amount=j["amount"];
    }
    
    void touch() { if(createdAt==0)createdAt=now(); updatedAt=now(); }
    void markDeleted() { deleted=true; updatedAt=now(); }
    bool isActive() const { return !deleted && !archived && status=="ACTIVE"; }
    std::string getDisplayName() const { return name.empty()?("Item#"+std::to_string(id)):name; }
};

} // namespace