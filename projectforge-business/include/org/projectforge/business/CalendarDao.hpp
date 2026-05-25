#pragma once

#include <org/projectforge/business/BaseDao.hpp>
#include <string>
#include <vector>
#include <optional>
#include <cstdint>

namespace org::projectforge::business::calendar {

struct CalendarEvent {
    int64_t id = 0;
    std::string uid; // RFC 5545 UID
    std::string subject;
    std::string description;
    std::string location;
    std::string note;
    int64_t start_date = 0;
    int64_t end_date = 0;
    bool all_day = false;
    std::string recurrence_rule; // iCal RRULE
    std::string recurrence_id;
    std::string recurrence_ex_date;
    std::string organizer;
    std::string attendees; // JSON array of attendee strings
    int32_t priority = 0;
    std::string status; // CONFIRMED, TENTATIVE, CANCELLED
    std::string access; // PUBLIC, PRIVATE, CONFIDENTIAL
    int64_t created_at = 0;
    int64_t updated_at = 0;
    int64_t owner_id = 0;
    int64_t task_id = 0;
    bool reminder = false;
    int32_t reminder_minutes_before = 15;
    int32_t duration_minutes = 0;
    std::string color;
    std::string ical_uid;
};

inline auto make_calendar_event_table() {
    using namespace sqlite_orm;
    return make_table("t_calendar_event",
        make_column("id", &CalendarEvent::id, primary_key().autoincrement()),
        make_column("uid", &CalendarEvent::uid),
        make_column("subject", &CalendarEvent::subject),
        make_column("description", &CalendarEvent::description),
        make_column("location", &CalendarEvent::location),
        make_column("note", &CalendarEvent::note),
        make_column("start_date", &CalendarEvent::start_date),
        make_column("end_date", &CalendarEvent::end_date),
        make_column("all_day", &CalendarEvent::all_day),
        make_column("recurrence_rule", &CalendarEvent::recurrence_rule),
        make_column("recurrence_id", &CalendarEvent::recurrence_id),
        make_column("recurrence_ex_date", &CalendarEvent::recurrence_ex_date),
        make_column("organizer", &CalendarEvent::organizer),
        make_column("attendees", &CalendarEvent::attendees),
        make_column("priority", &CalendarEvent::priority),
        make_column("status", &CalendarEvent::status),
        make_column("access", &CalendarEvent::access),
        make_column("created_at", &CalendarEvent::created_at),
        make_column("updated_at", &CalendarEvent::updated_at),
        make_column("owner_id", &CalendarEvent::owner_id),
        make_column("task_id", &CalendarEvent::task_id),
        make_column("reminder", &CalendarEvent::reminder),
        make_column("reminder_minutes_before", &CalendarEvent::reminder_minutes_before),
        make_column("duration_minutes", &CalendarEvent::duration_minutes),
        make_column("color", &CalendarEvent::color),
        make_column("ical_uid", &CalendarEvent::ical_uid));
}

struct CalendarSubscription {
    int64_t id = 0;
    int64_t user_id = 0;
    std::string url;
    std::string name;
    std::string color;
    int64_t last_sync = 0;
    int32_t sync_interval_minutes = 60;
    bool active = true;
};

inline auto make_calendar_subscription_table() {
    using namespace sqlite_orm;
    return make_table("t_calendar_subscription",
        make_column("id", &CalendarSubscription::id, primary_key().autoincrement()),
        make_column("user_id", &CalendarSubscription::user_id),
        make_column("url", &CalendarSubscription::url),
        make_column("name", &CalendarSubscription::name),
        make_column("color", &CalendarSubscription::color),
        make_column("last_sync", &CalendarSubscription::last_sync),
        make_column("sync_interval_minutes", &CalendarSubscription::sync_interval_minutes),
        make_column("active", &CalendarSubscription::active));
}

class CalendarDao : public BaseDao<CalendarEvent> {
public:
    explicit CalendarDao(std::shared_ptr<sqlite_orm::database> db);

    std::vector<CalendarEvent> findByOwner(int64_t ownerId) const;
    std::vector<CalendarEvent> findByDateRange(int64_t from, int64_t to) const;
    std::vector<CalendarEvent> findByDateRangeAndOwner(int64_t ownerId, int64_t from, int64_t to) const;
    std::vector<CalendarEvent> findByTask(int64_t taskId) const;
    std::vector<CalendarEvent> findUpcoming(int64_t userId, int limit = 10) const;
    std::vector<CalendarEvent> findRecurring() const;
    std::vector<CalendarEvent> findConflicting(int64_t userId, int64_t start, int64_t end, int64_t excludeId = 0) const;
    std::vector<CalendarEvent> search(const std::string& query) const;

    std::vector<CalendarEvent> expandRecurrence(const CalendarEvent& event, int64_t from, int64_t to) const;
    CalendarEvent createEvent(const CalendarEvent& event);
    CalendarEvent updateEvent(const CalendarEvent& event);

    std::vector<CalendarEvent> getReminders(int64_t now, int64_t windowSeconds) const;
    bool markReminded(int64_t eventId);

    // Subscriptions
    std::vector<CalendarSubscription> getSubscriptions(int64_t userId) const;
    CalendarSubscription saveSubscription(const CalendarSubscription& sub);
    bool deleteSubscription(int64_t subId);
    bool updateSubscriptionSyncTime(int64_t subId, int64_t lastSync);

    // iCal export/import
    std::string exportAsICal(int64_t eventId) const;
    std::string exportRangeAsICal(int64_t userId, int64_t from, int64_t to) const;
    std::vector<CalendarEvent> importFromICal(const std::string& icalData, int64_t userId);
    bool isConflicting(int64_t userId, int64_t start, int64_t end, int64_t excludeId = 0) const;

    json toJson(const CalendarEvent& event) const override;
    CalendarEvent fromJson(const json& j) const override;

    // Team calendar
    std::vector<CalendarEvent> findByUserIds(const std::vector<int64_t>& userIds, int64_t from, int64_t to) const;
};

} // namespace org::projectforge::business::calendar
