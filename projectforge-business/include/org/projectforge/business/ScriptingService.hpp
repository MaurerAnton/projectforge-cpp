#pragma once

#include <string>
#include <vector>
#include <memory>
#include <functional>
#include <map>
#include <cstdint>
#include <nlohmann/json.hpp>

namespace sqlite_orm { class database; }

namespace org::projectforge::business::scripting {

using json = nlohmann::json;

struct Script {
    int64_t id = 0;
    std::string name;
    std::string description;
    std::string script_type; // GROOVY, PYTHON, JAVASCRIPT, SHELL
    std::string source_code;
    std::string compiled_cache;
    bool active = true;
    bool system_script = false;
    int64_t created_at = 0;
    int64_t updated_at = 0;
    int64_t created_by = 0;
};

struct ScriptParameter {
    int64_t id = 0;
    int64_t script_id = 0;
    std::string name;
    std::string param_type; // STRING, INTEGER, DOUBLE, BOOLEAN, DATE
    std::string default_value;
    std::string description;
    bool required = false;
    int32_t order_position = 0;
};

struct ScriptExecution {
    int64_t id = 0;
    int64_t script_id = 0;
    int64_t executed_by = 0;
    int64_t started_at = 0;
    int64_t finished_at = 0;
    std::string status; // RUNNING, SUCCESS, FAILED, CANCELLED
    std::string output;
    std::string error_output;
    int32_t exit_code = 0;
    json parameters;
};

class ScriptingService {
public:
    explicit ScriptingService(std::shared_ptr<sqlite_orm::database> db);

    // Script management
    std::vector<Script> getAllScripts() const;
    std::optional<Script> getScript(int64_t scriptId) const;
    std::optional<Script> getScriptByName(const std::string& name) const;
    Script saveScript(const Script& script);
    bool deleteScript(int64_t scriptId);
    std::vector<Script> getScriptsByType(const std::string& type) const;

    // Parameters
    std::vector<ScriptParameter> getParameters(int64_t scriptId) const;
    ScriptParameter addParameter(const ScriptParameter& param);
    bool updateParameter(const ScriptParameter& param);
    bool removeParameter(int64_t paramId);

    // Execution
    ScriptExecution executeScript(int64_t scriptId, const json& params, int64_t userId);
    ScriptExecution executeScriptByName(const std::string& name, const json& params, int64_t userId);
    bool cancelExecution(int64_t executionId);
    std::vector<ScriptExecution> getExecutionHistory(int64_t scriptId, int limit = 50) const;
    std::optional<ScriptExecution> getExecution(int64_t executionId) const;

    // Validation
    bool validateScript(const std::string& sourceCode, const std::string& scriptType, std::string& errorMsg) const;
    bool compileScript(int64_t scriptId);

    // Built-in scripts
    std::vector<std::string> getBuiltinScriptNames() const;
    bool runMaintenanceScripts();

private:
    std::shared_ptr<sqlite_orm::database> db_;

    std::string executePython(const std::string& code, const json& params) const;
    std::string executeJavaScript(const std::string& code, const json& params) const;
    std::string executeShell(const std::string& code, const json& params) const;
    std::string executeGroovy(const std::string& code, const json& params) const;
    bool runSubprocess(const std::string& command, std::string& output, std::string& error, int32_t timeoutSec = 30) const;
};

} // namespace org::projectforge::business::scripting
