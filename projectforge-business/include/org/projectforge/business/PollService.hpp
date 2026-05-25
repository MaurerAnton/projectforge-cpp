#pragma once

#include <string>
#include <vector>
#include <optional>
#include <memory>
#include <cstdint>
#include <nlohmann/json.hpp>

namespace sqlite_orm { class database; }

namespace org::projectforge::business::poll {

using json = nlohmann::json;

struct Poll {
    int64_t id = 0;
    std::string title;
    std::string description;
    int64_t created_by = 0;
    int64_t created_at = 0;
    int64_t expires_at = 0;
    bool active = true;
    bool anonymous = false;
    bool multiple_choice = false;
    std::string poll_type; // TEXT, DATE, DATETIME
};

struct PollOption {
    int64_t id = 0;
    int64_t poll_id = 0;
    std::string text;
    int64_t date_value = 0;
    int32_t order_position = 0;
};

struct PollVote {
    int64_t id = 0;
    int64_t poll_id = 0;
    int64_t option_id = 0;
    int64_t user_id = 0;
    std::string comment;
    int64_t voted_at = 0;
};

class PollService {
public:
    explicit PollService(std::shared_ptr<sqlite_orm::database> db);

    Poll createPoll(const Poll& poll);
    Poll updatePoll(const Poll& poll);
    bool deletePoll(int64_t pollId);
    std::optional<Poll> getPoll(int64_t pollId) const;
    std::vector<Poll> getActivePolls() const;
    std::vector<Poll> getPollsByUser(int64_t userId) const;
    std::vector<Poll> getExpiredPolls(int64_t now) const;

    // Options
    std::vector<PollOption> getOptions(int64_t pollId) const;
    PollOption addOption(const PollOption& option);
    bool removeOption(int64_t optionId);
    bool updateOption(const PollOption& option);

    // Voting
    bool castVote(int64_t pollId, int64_t optionId, int64_t userId, const std::string& comment = "");
    bool castMultipleVotes(int64_t pollId, const std::vector<int64_t>& optionIds, int64_t userId);
    bool removeVote(int64_t pollId, int64_t userId);
    std::vector<PollVote> getVotes(int64_t pollId) const;
    std::optional<PollVote> getUserVote(int64_t pollId, int64_t userId) const;
    bool hasUserVoted(int64_t pollId, int64_t userId) const;

    // Results
    struct OptionResult {
        int64_t option_id;
        std::string text;
        size_t vote_count;
        double percentage;
        std::vector<std::string> voters; // empty if anonymous
    };
    struct PollResult {
        int64_t poll_id;
        std::string title;
        size_t total_votes;
        size_t total_voters;
        std::vector<OptionResult> options;
        bool is_expired;
    };
    PollResult getResults(int64_t pollId) const;

    bool closePoll(int64_t pollId);
    bool reopenPoll(int64_t pollId);
    json toJson(const Poll& poll) const;
    Poll fromJson(const json& j) const;

private:
    std::shared_ptr<sqlite_orm::database> db_;
};

} // namespace org::projectforge::business::poll
