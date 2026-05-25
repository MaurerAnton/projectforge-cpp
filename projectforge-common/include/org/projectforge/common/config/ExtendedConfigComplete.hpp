// ProjectForge C++ port — GPL v3

#pragma once
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
namespace com { namespace projectforge { namespace config { namespace extended {
using json = nlohmann::json;
struct ConfigEntry1 {
    std::string key="config.1",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=1;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry2 {
    std::string key="config.2",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=2;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry3 {
    std::string key="config.3",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=3;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry4 {
    std::string key="config.4",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=4;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry5 {
    std::string key="config.5",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=5;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry6 {
    std::string key="config.6",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=6;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry7 {
    std::string key="config.7",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=7;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry8 {
    std::string key="config.8",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=8;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry9 {
    std::string key="config.9",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=9;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry10 {
    std::string key="config.10",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=10;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry11 {
    std::string key="config.11",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=11;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry12 {
    std::string key="config.12",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=12;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry13 {
    std::string key="config.13",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=13;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry14 {
    std::string key="config.14",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=14;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry15 {
    std::string key="config.15",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=15;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry16 {
    std::string key="config.16",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=16;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry17 {
    std::string key="config.17",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=17;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry18 {
    std::string key="config.18",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=18;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry19 {
    std::string key="config.19",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=19;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry20 {
    std::string key="config.20",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=20;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry21 {
    std::string key="config.21",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=21;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry22 {
    std::string key="config.22",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=22;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry23 {
    std::string key="config.23",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=23;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry24 {
    std::string key="config.24",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=24;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry25 {
    std::string key="config.25",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=25;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry26 {
    std::string key="config.26",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=26;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry27 {
    std::string key="config.27",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=27;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry28 {
    std::string key="config.28",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=28;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry29 {
    std::string key="config.29",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=29;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry30 {
    std::string key="config.30",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=30;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry31 {
    std::string key="config.31",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=31;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry32 {
    std::string key="config.32",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=32;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry33 {
    std::string key="config.33",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=33;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry34 {
    std::string key="config.34",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=34;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry35 {
    std::string key="config.35",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=35;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry36 {
    std::string key="config.36",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=36;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry37 {
    std::string key="config.37",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=37;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry38 {
    std::string key="config.38",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=38;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry39 {
    std::string key="config.39",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=39;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry40 {
    std::string key="config.40",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=40;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry41 {
    std::string key="config.41",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=41;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry42 {
    std::string key="config.42",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=42;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry43 {
    std::string key="config.43",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=43;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry44 {
    std::string key="config.44",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=44;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry45 {
    std::string key="config.45",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=45;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry46 {
    std::string key="config.46",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=46;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry47 {
    std::string key="config.47",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=47;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry48 {
    std::string key="config.48",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=48;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry49 {
    std::string key="config.49",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=49;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry50 {
    std::string key="config.50",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=50;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry51 {
    std::string key="config.51",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=51;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry52 {
    std::string key="config.52",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=52;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry53 {
    std::string key="config.53",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=53;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry54 {
    std::string key="config.54",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=54;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry55 {
    std::string key="config.55",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=55;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry56 {
    std::string key="config.56",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=56;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry57 {
    std::string key="config.57",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=57;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry58 {
    std::string key="config.58",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=58;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry59 {
    std::string key="config.59",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=59;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry60 {
    std::string key="config.60",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=60;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry61 {
    std::string key="config.61",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=61;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry62 {
    std::string key="config.62",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=62;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry63 {
    std::string key="config.63",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=63;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry64 {
    std::string key="config.64",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=64;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry65 {
    std::string key="config.65",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=65;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry66 {
    std::string key="config.66",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=66;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry67 {
    std::string key="config.67",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=67;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry68 {
    std::string key="config.68",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=68;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry69 {
    std::string key="config.69",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=69;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry70 {
    std::string key="config.70",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=70;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry71 {
    std::string key="config.71",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=71;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry72 {
    std::string key="config.72",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=72;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry73 {
    std::string key="config.73",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=73;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry74 {
    std::string key="config.74",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=74;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry75 {
    std::string key="config.75",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=75;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry76 {
    std::string key="config.76",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=76;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry77 {
    std::string key="config.77",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=77;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry78 {
    std::string key="config.78",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=78;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry79 {
    std::string key="config.79",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=79;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry80 {
    std::string key="config.80",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=80;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry81 {
    std::string key="config.81",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=81;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry82 {
    std::string key="config.82",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=82;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry83 {
    std::string key="config.83",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=83;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry84 {
    std::string key="config.84",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=84;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry85 {
    std::string key="config.85",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=85;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry86 {
    std::string key="config.86",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=86;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry87 {
    std::string key="config.87",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=87;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry88 {
    std::string key="config.88",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=88;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry89 {
    std::string key="config.89",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=89;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry90 {
    std::string key="config.90",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=90;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry91 {
    std::string key="config.91",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=91;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry92 {
    std::string key="config.92",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=92;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry93 {
    std::string key="config.93",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=93;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry94 {
    std::string key="config.94",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=94;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry95 {
    std::string key="config.95",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=95;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry96 {
    std::string key="config.96",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=96;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry97 {
    std::string key="config.97",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=97;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry98 {
    std::string key="config.98",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=98;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry99 {
    std::string key="config.99",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=99;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry100 {
    std::string key="config.100",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=100;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry101 {
    std::string key="config.101",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=101;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry102 {
    std::string key="config.102",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=102;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry103 {
    std::string key="config.103",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=103;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry104 {
    std::string key="config.104",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=104;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry105 {
    std::string key="config.105",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=105;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry106 {
    std::string key="config.106",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=106;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry107 {
    std::string key="config.107",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=107;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry108 {
    std::string key="config.108",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=108;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry109 {
    std::string key="config.109",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=109;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry110 {
    std::string key="config.110",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=110;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry111 {
    std::string key="config.111",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=111;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry112 {
    std::string key="config.112",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=112;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry113 {
    std::string key="config.113",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=113;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry114 {
    std::string key="config.114",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=114;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry115 {
    std::string key="config.115",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=115;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry116 {
    std::string key="config.116",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=116;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry117 {
    std::string key="config.117",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=117;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry118 {
    std::string key="config.118",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=118;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry119 {
    std::string key="config.119",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=119;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry120 {
    std::string key="config.120",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=120;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry121 {
    std::string key="config.121",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=121;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry122 {
    std::string key="config.122",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=122;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry123 {
    std::string key="config.123",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=123;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry124 {
    std::string key="config.124",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=124;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry125 {
    std::string key="config.125",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=125;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry126 {
    std::string key="config.126",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=126;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry127 {
    std::string key="config.127",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=127;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry128 {
    std::string key="config.128",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=128;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry129 {
    std::string key="config.129",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=129;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry130 {
    std::string key="config.130",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=130;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry131 {
    std::string key="config.131",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=131;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry132 {
    std::string key="config.132",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=132;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry133 {
    std::string key="config.133",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=133;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry134 {
    std::string key="config.134",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=134;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry135 {
    std::string key="config.135",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=135;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry136 {
    std::string key="config.136",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=136;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry137 {
    std::string key="config.137",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=137;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry138 {
    std::string key="config.138",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=138;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry139 {
    std::string key="config.139",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=139;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry140 {
    std::string key="config.140",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=140;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry141 {
    std::string key="config.141",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=141;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry142 {
    std::string key="config.142",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=142;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry143 {
    std::string key="config.143",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=143;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry144 {
    std::string key="config.144",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=144;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry145 {
    std::string key="config.145",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=145;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry146 {
    std::string key="config.146",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=146;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry147 {
    std::string key="config.147",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=147;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry148 {
    std::string key="config.148",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=148;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry149 {
    std::string key="config.149",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=149;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry150 {
    std::string key="config.150",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=150;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry151 {
    std::string key="config.151",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=151;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry152 {
    std::string key="config.152",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=152;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry153 {
    std::string key="config.153",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=153;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry154 {
    std::string key="config.154",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=154;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry155 {
    std::string key="config.155",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=155;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry156 {
    std::string key="config.156",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=156;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry157 {
    std::string key="config.157",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=157;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry158 {
    std::string key="config.158",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=158;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry159 {
    std::string key="config.159",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=159;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry160 {
    std::string key="config.160",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=160;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry161 {
    std::string key="config.161",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=161;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry162 {
    std::string key="config.162",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=162;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry163 {
    std::string key="config.163",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=163;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry164 {
    std::string key="config.164",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=164;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry165 {
    std::string key="config.165",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=165;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry166 {
    std::string key="config.166",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=166;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry167 {
    std::string key="config.167",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=167;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry168 {
    std::string key="config.168",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=168;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry169 {
    std::string key="config.169",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=169;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry170 {
    std::string key="config.170",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=170;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry171 {
    std::string key="config.171",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=171;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry172 {
    std::string key="config.172",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=172;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry173 {
    std::string key="config.173",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=173;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry174 {
    std::string key="config.174",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=174;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry175 {
    std::string key="config.175",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=175;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry176 {
    std::string key="config.176",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=176;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry177 {
    std::string key="config.177",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=177;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry178 {
    std::string key="config.178",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=178;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry179 {
    std::string key="config.179",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=179;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry180 {
    std::string key="config.180",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=180;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry181 {
    std::string key="config.181",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=181;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry182 {
    std::string key="config.182",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=182;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry183 {
    std::string key="config.183",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=183;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry184 {
    std::string key="config.184",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=184;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry185 {
    std::string key="config.185",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=185;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry186 {
    std::string key="config.186",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=186;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry187 {
    std::string key="config.187",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=187;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry188 {
    std::string key="config.188",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=188;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry189 {
    std::string key="config.189",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=189;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry190 {
    std::string key="config.190",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=190;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry191 {
    std::string key="config.191",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=191;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry192 {
    std::string key="config.192",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=192;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry193 {
    std::string key="config.193",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=193;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry194 {
    std::string key="config.194",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=194;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry195 {
    std::string key="config.195",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=195;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry196 {
    std::string key="config.196",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=196;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry197 {
    std::string key="config.197",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=197;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry198 {
    std::string key="config.198",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=198;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry199 {
    std::string key="config.199",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=199;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry200 {
    std::string key="config.200",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=200;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry201 {
    std::string key="config.201",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=201;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry202 {
    std::string key="config.202",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=202;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry203 {
    std::string key="config.203",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=203;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry204 {
    std::string key="config.204",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=204;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry205 {
    std::string key="config.205",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=205;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry206 {
    std::string key="config.206",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=206;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry207 {
    std::string key="config.207",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=207;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry208 {
    std::string key="config.208",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=208;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry209 {
    std::string key="config.209",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=209;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry210 {
    std::string key="config.210",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=210;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry211 {
    std::string key="config.211",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=211;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry212 {
    std::string key="config.212",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=212;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry213 {
    std::string key="config.213",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=213;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry214 {
    std::string key="config.214",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=214;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry215 {
    std::string key="config.215",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=215;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry216 {
    std::string key="config.216",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=216;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry217 {
    std::string key="config.217",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=217;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry218 {
    std::string key="config.218",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=218;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry219 {
    std::string key="config.219",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=219;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry220 {
    std::string key="config.220",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=220;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry221 {
    std::string key="config.221",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=221;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry222 {
    std::string key="config.222",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=222;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry223 {
    std::string key="config.223",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=223;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry224 {
    std::string key="config.224",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=224;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry225 {
    std::string key="config.225",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=225;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry226 {
    std::string key="config.226",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=226;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry227 {
    std::string key="config.227",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=227;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry228 {
    std::string key="config.228",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=228;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry229 {
    std::string key="config.229",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=229;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry230 {
    std::string key="config.230",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=230;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry231 {
    std::string key="config.231",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=231;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry232 {
    std::string key="config.232",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=232;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry233 {
    std::string key="config.233",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=233;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry234 {
    std::string key="config.234",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=234;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry235 {
    std::string key="config.235",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=235;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry236 {
    std::string key="config.236",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=236;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry237 {
    std::string key="config.237",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=237;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry238 {
    std::string key="config.238",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=238;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry239 {
    std::string key="config.239",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=239;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry240 {
    std::string key="config.240",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=240;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry241 {
    std::string key="config.241",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=241;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry242 {
    std::string key="config.242",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=242;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry243 {
    std::string key="config.243",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=243;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry244 {
    std::string key="config.244",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=244;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry245 {
    std::string key="config.245",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=245;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry246 {
    std::string key="config.246",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=246;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry247 {
    std::string key="config.247",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=247;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry248 {
    std::string key="config.248",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=248;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry249 {
    std::string key="config.249",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=249;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry250 {
    std::string key="config.250",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=250;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry251 {
    std::string key="config.251",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=251;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry252 {
    std::string key="config.252",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=252;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry253 {
    std::string key="config.253",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=253;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry254 {
    std::string key="config.254",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=254;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry255 {
    std::string key="config.255",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=255;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry256 {
    std::string key="config.256",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=256;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry257 {
    std::string key="config.257",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=257;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry258 {
    std::string key="config.258",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=258;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry259 {
    std::string key="config.259",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=259;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry260 {
    std::string key="config.260",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=260;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry261 {
    std::string key="config.261",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=261;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry262 {
    std::string key="config.262",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=262;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry263 {
    std::string key="config.263",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=263;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry264 {
    std::string key="config.264",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=264;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry265 {
    std::string key="config.265",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=265;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry266 {
    std::string key="config.266",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=266;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry267 {
    std::string key="config.267",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=267;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry268 {
    std::string key="config.268",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=268;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry269 {
    std::string key="config.269",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=269;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry270 {
    std::string key="config.270",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=270;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry271 {
    std::string key="config.271",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=271;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry272 {
    std::string key="config.272",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=272;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry273 {
    std::string key="config.273",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=273;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry274 {
    std::string key="config.274",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=274;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry275 {
    std::string key="config.275",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=275;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry276 {
    std::string key="config.276",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=276;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry277 {
    std::string key="config.277",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=277;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry278 {
    std::string key="config.278",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=278;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry279 {
    std::string key="config.279",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=279;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry280 {
    std::string key="config.280",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=280;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry281 {
    std::string key="config.281",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=281;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry282 {
    std::string key="config.282",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=282;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry283 {
    std::string key="config.283",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=283;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry284 {
    std::string key="config.284",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=284;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry285 {
    std::string key="config.285",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=285;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry286 {
    std::string key="config.286",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=286;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry287 {
    std::string key="config.287",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=287;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry288 {
    std::string key="config.288",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=288;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry289 {
    std::string key="config.289",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=289;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry290 {
    std::string key="config.290",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=290;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry291 {
    std::string key="config.291",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=291;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry292 {
    std::string key="config.292",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=292;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry293 {
    std::string key="config.293",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=293;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry294 {
    std::string key="config.294",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=294;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry295 {
    std::string key="config.295",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=295;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry296 {
    std::string key="config.296",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=296;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry297 {
    std::string key="config.297",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=297;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry298 {
    std::string key="config.298",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=298;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry299 {
    std::string key="config.299",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=299;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
struct ConfigEntry300 {
    std::string key="config.300",value,defaultValue,description,category="general",subcategory,type="string",validation;
    bool required=false,encrypted=false,readonly=false,hidden=false,advanced=false,deprecated=false;
    int minLength=0,maxLength=65535,minValue=0,maxValue=0,displayOrder=300;
    std::string placeholder,helpText,tooltip,groupName;
    std::vector<std::string> allowedValues,examples;
    json toJson() const { json j;j["key"]=key;j["value"]=value;j["type"]=type;j["category"]=category;if(!description.empty())j["description"]=description;return j; }
};
}}}} // namespace