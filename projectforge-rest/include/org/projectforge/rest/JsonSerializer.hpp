// ProjectForge C++ port — GPL v3 — www.projectforge.org
#pragma once

#include <nlohmann/json.hpp>
#include <org/projectforge/model/rest/UserObject.hpp>
#include <org/projectforge/model/rest/TaskObject.hpp>
#include <org/projectforge/model/rest/TimesheetObject.hpp>
#include <org/projectforge/model/rest/AddressObject.hpp>
#include <org/projectforge/model/rest/CalendarObject.hpp>
#include <org/projectforge/model/rest/Cost2Object.hpp>
#include <org/projectforge/business/UserDao.hpp>
#include <org/projectforge/business/TaskDao.hpp>
#include <org/projectforge/business/TimesheetDao.hpp>
#include <org/projectforge/business/AddressDao.hpp>
#include <org/projectforge/business/CalendarDao.hpp>
#include <org/projectforge/business/KontoDao.hpp>
#include <org/projectforge/business/RechnungDao.hpp>
#include <org/projectforge/business/AuftragDao.hpp>
#include <org/projectforge/business/BookDao.hpp>
#include <org/projectforge/business/VacationDao.hpp>
#include <org/projectforge/business/HrDao.hpp>
#include <string>
#include <vector>
#include <cstdint>
#include <optional>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <set>

namespace org::projectforge::rest {

using json = nlohmann::json;

class JsonSerializer {
public:
    // === User serialization ===
    static json serializeUser(const org::projectforge::business::user::User& user) {
        json j;
        j["id"] = user.id;
        j["username"] = user.username;
        if (!user.first_name.empty()) j["firstName"] = user.first_name;
        if (!user.last_name.empty()) j["lastName"] = user.last_name;
        if (!user.email.empty()) j["email"] = user.email;
        if (!user.organization.empty()) j["organization"] = user.organization;
        if (!user.phone.empty()) j["phone"] = user.phone;
        if (!user.mobile_phone.empty()) j["mobilePhone"] = user.mobile_phone;
        if (!user.description.empty()) j["description"] = user.description;
        if (!user.locale.empty()) j["locale"] = user.locale;
        if (!user.timezone.empty()) j["timezone"] = user.timezone;
        j["active"] = user.active;
        j["localUser"] = user.local_user;
        j["restrictedUser"] = user.restricted_user;
        j["tfaEnabled"] = user.tfa_enabled;
        if (!user.avatar_url.empty()) j["avatarUrl"] = user.avatar_url;
        if (!user.type.empty()) j["type"] = user.type;
        if (!user.hr_status.empty()) j["hrStatus"] = user.hr_status;
        if (!user.description_of_employment.empty()) j["descriptionOfEmployment"] = user.description_of_employment;
        j["receivesBusinessMails"] = user.receives_business_mails;
        j["receivesNewsletter"] = user.receives_newsletter;
        if (user.last_login > 0) j["lastLogin"] = user.last_login;
        if (user.created_at > 0) j["createdAt"] = user.created_at;
        if (user.updated_at > 0) j["updatedAt"] = user.updated_at;
        if (user.kost2_id > 0) j["kost2Id"] = user.kost2_id;
        return j;
    }

    static json serializeUsers(const std::vector<org::projectforge::business::user::User>& users) {
        json arr = json::array();
        for (auto& u : users) arr.push_back(serializeUser(u));
        return arr;
    }

    static org::projectforge::business::user::User deserializeUser(const json& j) {
        org::projectforge::business::user::User u;
        if (j.contains("id")) u.id = j["id"].get<int64_t>();
        if (j.contains("username")) u.username = j["username"].get<std::string>();
        if (j.contains("password")) u.password_hash = j["password"].get<std::string>();
        if (j.contains("email")) u.email = j["email"].get<std::string>();
        if (j.contains("firstName")) u.first_name = j["firstName"].get<std::string>();
        if (j.contains("lastName")) u.last_name = j["lastName"].get<std::string>();
        if (j.contains("organization")) u.organization = j["organization"].get<std::string>();
        if (j.contains("phone")) u.phone = j["phone"].get<std::string>();
        if (j.contains("mobilePhone")) u.mobile_phone = j["mobilePhone"].get<std::string>();
        if (j.contains("description")) u.description = j["description"].get<std::string>();
        if (j.contains("locale")) u.locale = j["locale"].get<std::string>();
        if (j.contains("timezone")) u.timezone = j["timezone"].get<std::string>();
        if (j.contains("active")) u.active = j["active"].get<bool>();
        if (j.contains("localUser")) u.local_user = j["localUser"].get<bool>();
        if (j.contains("restrictedUser")) u.restricted_user = j["restrictedUser"].get<bool>();
        if (j.contains("type")) u.type = j["type"].get<std::string>();
        if (j.contains("hrStatus")) u.hr_status = j["hrStatus"].get<std::string>();
        if (j.contains("descriptionOfEmployment")) u.description_of_employment = j["descriptionOfEmployment"].get<std::string>();
        if (j.contains("kost2Id")) u.kost2_id = j["kost2Id"].get<int64_t>();
        if (j.contains("receivesBusinessMails")) u.receives_business_mails = j["receivesBusinessMails"].get<bool>();
        if (j.contains("receivesNewsletter")) u.receives_newsletter = j["receivesNewsletter"].get<bool>();
        return u;
    }

    // === Task serialization ===
    static json serializeTask(const org::projectforge::business::task::Task& task) {
        json j;
        j["id"] = task.id;
        j["title"] = task.title;
        if (!task.description.empty()) j["description"] = task.description;
        if (!task.reference.empty()) j["reference"] = task.reference;
        if (!task.task_path.empty()) j["taskPath"] = task.task_path;
        if (task.parent_task_id > 0) j["parentTaskId"] = task.parent_task_id;
        if (task.responsible_user_id > 0) j["responsibleUserId"] = task.responsible_user_id;
        if (task.assigned_user_id > 0) j["assignedUserId"] = task.assigned_user_id;
        if (task.reporter_user_id > 0) j["reporterUserId"] = task.reporter_user_id;
        j["priority"] = task.priority;
        j["status"] = task.status;
        if (!task.task_type.empty()) j["taskType"] = task.task_type;
        if (task.deadline > 0) j["deadline"] = task.deadline;
        if (task.start_date > 0) j["startDate"] = task.start_date;
        j["progress"] = task.progress;
        j["storyPoints"] = task.story_points;
        j["plannedHours"] = task.planned_hours;
        j["actualHours"] = task.actual_hours;
        j["remainingHours"] = task.remaining_hours;
        if (task.max_hours > 0) j["maxHours"] = task.max_hours;
        j["billable"] = task.billable;
        if (task.kost2_id > 0) j["kost2Id"] = task.kost2_id;
        if (task.project_id > 0) j["projectId"] = task.project_id;
        if (!task.latest_comment.empty()) j["latestComment"] = task.latest_comment;
        j["orderPosition"] = task.order_position;
        if (task.created_at > 0) j["createdAt"] = task.created_at;
        if (task.updated_at > 0) j["updatedAt"] = task.updated_at;
        if (task.resolved_at > 0) j["resolvedAt"] = task.resolved_at;
        if (task.closed_at > 0) j["closedAt"] = task.closed_at;
        j["durationHours"] = task.duration_hours;
        j["durationMinutes"] = task.duration_minutes;
        return j;
    }

    static json serializeTasks(const std::vector<org::projectforge::business::task::Task>& tasks) {
        json arr = json::array();
        for (auto& t : tasks) arr.push_back(serializeTask(t));
        return arr;
    }

    static org::projectforge::business::task::Task deserializeTask(const json& j) {
        org::projectforge::business::task::Task t;
        if (j.contains("id")) t.id = j["id"].get<int64_t>();
        if (j.contains("title")) t.title = j["title"].get<std::string>();
        if (j.contains("description")) t.description = j["description"].get<std::string>();
        if (j.contains("reference")) t.reference = j["reference"].get<std::string>();
        if (j.contains("parentTaskId")) t.parent_task_id = j["parentTaskId"].get<int64_t>();
        if (j.contains("responsibleUserId")) t.responsible_user_id = j["responsibleUserId"].get<int64_t>();
        if (j.contains("assignedUserId")) t.assigned_user_id = j["assignedUserId"].get<int64_t>();
        if (j.contains("reporterUserId")) t.reporter_user_id = j["reporterUserId"].get<int64_t>();
        if (j.contains("priority")) t.priority = j["priority"].get<int32_t>();
        if (j.contains("status")) t.status = j["status"].get<std::string>();
        if (j.contains("taskType")) t.task_type = j["taskType"].get<std::string>();
        if (j.contains("deadline")) t.deadline = j["deadline"].get<int64_t>();
        if (j.contains("startDate")) t.start_date = j["startDate"].get<int64_t>();
        if (j.contains("progress")) t.progress = j["progress"].get<int32_t>();
        if (j.contains("storyPoints")) t.story_points = j["storyPoints"].get<int32_t>();
        if (j.contains("plannedHours")) t.planned_hours = j["plannedHours"].get<double>();
        if (j.contains("actualHours")) t.actual_hours = j["actualHours"].get<double>();
        if (j.contains("remainingHours")) t.remaining_hours = j["remainingHours"].get<double>();
        if (j.contains("maxHours")) t.max_hours = j["maxHours"].get<int64_t>();
        if (j.contains("billable")) t.billable = j["billable"].get<bool>();
        if (j.contains("kost2Id")) t.kost2_id = j["kost2Id"].get<int64_t>();
        if (j.contains("projectId")) t.project_id = j["projectId"].get<int64_t>();
        if (j.contains("latestComment")) t.latest_comment = j["latestComment"].get<std::string>();
        if (j.contains("orderPosition")) t.order_position = j["orderPosition"].get<int32_t>();
        if (j.contains("durationHours")) t.duration_hours = j["durationHours"].get<int64_t>();
        if (j.contains("durationMinutes")) t.duration_minutes = j["durationMinutes"].get<int64_t>();
        return t;
    }

    // === Task Comment serialization ===
    static json serializeTaskComment(const org::projectforge::business::task::TaskComment& comment) {
        json j;
        j["id"] = comment.id;
        j["taskId"] = comment.task_id;
        j["userId"] = comment.user_id;
        j["comment"] = comment.comment;
        if (comment.created_at > 0) j["createdAt"] = comment.created_at;
        if (comment.updated_at > 0) j["updatedAt"] = comment.updated_at;
        return j;
    }

    static json serializeTaskComments(const std::vector<org::projectforge::business::task::TaskComment>& comments) {
        json arr = json::array();
        for (auto& c : comments) arr.push_back(serializeTaskComment(c));
        return arr;
    }

    // === Timesheet serialization ===
    static json serializeTimesheet(const org::projectforge::business::timesheet::Timesheet& ts) {
        json j;
        j["id"] = ts.id;
        j["userId"] = ts.user_id;
        if (ts.task_id > 0) j["taskId"] = ts.task_id;
        if (ts.start_time > 0) j["startTime"] = ts.start_time;
        if (ts.stop_time > 0) j["stopTime"] = ts.stop_time;
        j["durationSeconds"] = ts.duration_seconds;
        if (!ts.description.empty()) j["description"] = ts.description;
        if (!ts.location.empty()) j["location"] = ts.location;
        j["billable"] = ts.billable;
        j["booked"] = ts.booked;
        if (ts.kost2_id > 0) j["kost2Id"] = ts.kost2_id;
        j["costToBill"] = ts.cost_to_bill;
        if (!ts.status.empty()) j["status"] = ts.status;
        if (ts.created_at > 0) j["createdAt"] = ts.created_at;
        if (ts.updated_at > 0) j["updatedAt"] = ts.updated_at;
        if (ts.latitude != 0.0) j["latitude"] = ts.latitude;
        if (ts.longitude != 0.0) j["longitude"] = ts.longitude;
        if (ts.week_of_year > 0) j["weekOfYear"] = ts.week_of_year;
        if (!ts.reference.empty()) j["reference"] = ts.reference;
        return j;
    }

    static json serializeTimesheets(const std::vector<org::projectforge::business::timesheet::Timesheet>& sheets) {
        json arr = json::array();
        for (auto& s : sheets) arr.push_back(serializeTimesheet(s));
        return arr;
    }

    static org::projectforge::business::timesheet::Timesheet deserializeTimesheet(const json& j) {
        org::projectforge::business::timesheet::Timesheet ts;
        if (j.contains("id")) ts.id = j["id"].get<int64_t>();
        if (j.contains("taskId")) ts.task_id = j["taskId"].get<int64_t>();
        if (j.contains("startTime")) ts.start_time = j["startTime"].get<int64_t>();
        if (j.contains("stopTime")) ts.stop_time = j["stopTime"].get<int64_t>();
        if (j.contains("durationSeconds")) ts.duration_seconds = j["durationSeconds"].get<int64_t>();
        if (j.contains("description")) ts.description = j["description"].get<std::string>();
        if (j.contains("location")) ts.location = j["location"].get<std::string>();
        if (j.contains("billable")) ts.billable = j["billable"].get<bool>();
        if (j.contains("booked")) ts.booked = j["booked"].get<bool>();
        if (j.contains("kost2Id")) ts.kost2_id = j["kost2Id"].get<int64_t>();
        if (j.contains("costToBill")) ts.cost_to_bill = j["costToBill"].get<double>();
        if (j.contains("status")) ts.status = j["status"].get<std::string>();
        if (j.contains("reference")) ts.reference = j["reference"].get<std::string>();
        if (j.contains("latitude")) ts.latitude = j["latitude"].get<double>();
        if (j.contains("longitude")) ts.longitude = j["longitude"].get<double>();
        return ts;
    }

    // === Address serialization ===
    static json serializeAddress(const org::projectforge::business::address::Address& addr) {
        json j;
        j["id"] = addr.id;
        if (!addr.name.empty()) j["name"] = addr.name;
        if (!addr.first_name.empty()) j["firstName"] = addr.first_name;
        if (!addr.form_of_address.empty()) j["formOfAddress"] = addr.form_of_address;
        if (!addr.title.empty()) j["title"] = addr.title;
        if (!addr.organization.empty()) j["organization"] = addr.organization;
        if (!addr.division.empty()) j["division"] = addr.division;
        if (!addr.position_text.empty()) j["position"] = addr.position_text;
        if (!addr.street.empty()) j["street"] = addr.street;
        if (!addr.zip_code.empty()) j["zipCode"] = addr.zip_code;
        if (!addr.city.empty()) j["city"] = addr.city;
        if (!addr.country.empty()) j["country"] = addr.country;
        if (!addr.state.empty()) j["state"] = addr.state;
        if (!addr.phone_business.empty()) j["phoneBusiness"] = addr.phone_business;
        if (!addr.phone_mobile.empty()) j["phoneMobile"] = addr.phone_mobile;
        if (!addr.phone_private.empty()) j["phonePrivate"] = addr.phone_private;
        if (!addr.fax_business.empty()) j["faxBusiness"] = addr.fax_business;
        if (!addr.email.empty()) j["email"] = addr.email;
        if (!addr.website.empty()) j["website"] = addr.website;
        if (!addr.communication_language.empty()) j["communicationLanguage"] = addr.communication_language;
        if (!addr.comment.empty()) j["comment"] = addr.comment;
        if (!addr.address_status.empty()) j["addressStatus"] = addr.address_status;
        if (!addr.vat_id.empty()) j["vatId"] = addr.vat_id;
        if (!addr.contact_status.empty()) j["contactStatus"] = addr.contact_status;
        if (addr.birthday > 0) j["birthday"] = addr.birthday;
        if (addr.latitude != 0.0) j["latitude"] = addr.latitude;
        if (addr.longitude != 0.0) j["longitude"] = addr.longitude;
        j["favorite"] = addr.favorite;
        if (addr.created_at > 0) j["createdAt"] = addr.created_at;
        if (addr.updated_at > 0) j["updatedAt"] = addr.updated_at;
        return j;
    }

    static json serializeAddresses(const std::vector<org::projectforge::business::address::Address>& addrs) {
        json arr = json::array();
        for (auto& a : addrs) arr.push_back(serializeAddress(a));
        return arr;
    }

    static org::projectforge::business::address::Address deserializeAddress(const json& j) {
        org::projectforge::business::address::Address a;
        if (j.contains("id")) a.id = j["id"].get<int64_t>();
        if (j.contains("name")) a.name = j["name"].get<std::string>();
        if (j.contains("firstName")) a.first_name = j["firstName"].get<std::string>();
        if (j.contains("formOfAddress")) a.form_of_address = j["formOfAddress"].get<std::string>();
        if (j.contains("title")) a.title = j["title"].get<std::string>();
        if (j.contains("organization")) a.organization = j["organization"].get<std::string>();
        if (j.contains("division")) a.division = j["division"].get<std::string>();
        if (j.contains("position")) a.position_text = j["position"].get<std::string>();
        if (j.contains("street")) a.street = j["street"].get<std::string>();
        if (j.contains("zipCode")) a.zip_code = j["zipCode"].get<std::string>();
        if (j.contains("city")) a.city = j["city"].get<std::string>();
        if (j.contains("country")) a.country = j["country"].get<std::string>();
        if (j.contains("state")) a.state = j["state"].get<std::string>();
        if (j.contains("phoneBusiness")) a.phone_business = j["phoneBusiness"].get<std::string>();
        if (j.contains("phoneMobile")) a.phone_mobile = j["phoneMobile"].get<std::string>();
        if (j.contains("phonePrivate")) a.phone_private = j["phonePrivate"].get<std::string>();
        if (j.contains("email")) a.email = j["email"].get<std::string>();
        if (j.contains("website")) a.website = j["website"].get<std::string>();
        if (j.contains("comment")) a.comment = j["comment"].get<std::string>();
        if (j.contains("addressStatus")) a.address_status = j["addressStatus"].get<std::string>();
        if (j.contains("vatId")) a.vat_id = j["vatId"].get<std::string>();
        if (j.contains("contactStatus")) a.contact_status = j["contactStatus"].get<std::string>();
        if (j.contains("birthday")) a.birthday = j["birthday"].get<int64_t>();
        if (j.contains("favorite")) a.favorite = j["favorite"].get<bool>();
        return a;
    }

    // === Calendar serialization ===
    static json serializeCalendarEvent(const org::projectforge::business::calendar::CalendarEvent& evt) {
        json j;
        j["id"] = evt.id;
        if (!evt.uid.empty()) j["uid"] = evt.uid;
        if (!evt.subject.empty()) j["subject"] = evt.subject;
        if (!evt.description.empty()) j["description"] = evt.description;
        if (!evt.location.empty()) j["location"] = evt.location;
        if (!evt.note.empty()) j["note"] = evt.note;
        if (evt.start_date > 0) j["startDate"] = evt.start_date;
        if (evt.end_date > 0) j["endDate"] = evt.end_date;
        j["allDay"] = evt.all_day;
        if (!evt.recurrence_rule.empty()) j["recurrenceRule"] = evt.recurrence_rule;
        if (!evt.organizer.empty()) j["organizer"] = evt.organizer;
        j["priority"] = evt.priority;
        if (!evt.status.empty()) j["status"] = evt.status;
        if (!evt.access.empty()) j["access"] = evt.access;
        if (evt.owner_id > 0) j["ownerId"] = evt.owner_id;
        if (evt.task_id > 0) j["taskId"] = evt.task_id;
        j["reminder"] = evt.reminder;
        j["reminderMinutesBefore"] = evt.reminder_minutes_before;
        j["durationMinutes"] = evt.duration_minutes;
        if (!evt.color.empty()) j["color"] = evt.color;
        if (!evt.ical_uid.empty()) j["icalUid"] = evt.ical_uid;
        if (evt.created_at > 0) j["createdAt"] = evt.created_at;
        if (evt.updated_at > 0) j["updatedAt"] = evt.updated_at;
        return j;
    }

    static json serializeCalendarEvents(const std::vector<org::projectforge::business::calendar::CalendarEvent>& events) {
        json arr = json::array();
        for (auto& e : events) arr.push_back(serializeCalendarEvent(e));
        return arr;
    }

    // === Konto serialization ===
    static json serializeKonto(const org::projectforge::business::fibu::Konto& konto) {
        json j;
        j["id"] = konto.id;
        j["kontonummer"] = konto.kontonummer;
        j["name"] = konto.name;
        if (!konto.description.empty()) j["description"] = konto.description;
        j["type"] = konto.type;
        if (!konto.category.empty()) j["category"] = konto.category;
        if (!konto.steuer_schluessel.empty()) j["steuerSchluessel"] = konto.steuer_schluessel;
        j["balance"] = konto.balance;
        j["openingBalance"] = konto.opening_balance;
        if (konto.opening_balance_date > 0) j["openingBalanceDate"] = konto.opening_balance_date;
        j["currency"] = konto.currency;
        if (!konto.iban.empty()) j["iban"] = konto.iban;
        if (!konto.bic.empty()) j["bic"] = konto.bic;
        if (!konto.bank_name.empty()) j["bankName"] = konto.bank_name;
        j["active"] = konto.active;
        j["isBankAccount"] = konto.is_bank_account;
        if (!konto.datev_kontonummer.empty()) j["datevKontonummer"] = konto.datev_kontonummer;
        return j;
    }

    static json serializeKontos(const std::vector<org::projectforge::business::fibu::Konto>& kontos) {
        json arr = json::array();
        for (auto& k : kontos) arr.push_back(serializeKonto(k));
        return arr;
    }

    // === Rechnung serialization ===
    static json serializeRechnung(const org::projectforge::business::fibu::Rechnung& r) {
        json j;
        j["id"] = r.id;
        if (!r.number.empty()) j["number"] = r.number;
        if (r.customer_id > 0) j["customerId"] = r.customer_id;
        if (r.contact_id > 0) j["contactId"] = r.contact_id;
        if (!r.subject.empty()) j["subject"] = r.subject;
        if (r.date > 0) j["date"] = r.date;
        if (r.due_date > 0) j["dueDate"] = r.due_date;
        if (r.delivery_date > 0) j["deliveryDate"] = r.delivery_date;
        if (r.payment_date > 0) j["paymentDate"] = r.payment_date;
        if (!r.status.empty()) j["status"] = r.status;
        if (!r.type.empty()) j["type"] = r.type;
        j["netAmount"] = r.net_amount;
        j["grossAmount"] = r.gross_amount;
        j["vatAmount"] = r.vat_amount;
        j["vatRate"] = r.vat_rate;
        j["currency"] = r.currency;
        if (!r.payment_method.empty()) j["paymentMethod"] = r.payment_method;
        if (!r.payment_terms.empty()) j["paymentTerms"] = r.payment_terms;
        if (!r.comment.empty()) j["comment"] = r.comment;
        if (!r.header_text.empty()) j["headerText"] = r.header_text;
        if (!r.footer_text.empty()) j["footerText"] = r.footer_text;
        if (r.kost2_id > 0) j["kost2Id"] = r.kost2_id;
        if (r.project_id > 0) j["projectId"] = r.project_id;
        if (r.auftrag_id > 0) j["auftragId"] = r.auftrag_id;
        j["exported"] = r.exported;
        if (r.exported_date > 0) j["exportedDate"] = r.exported_date;
        if (r.created_by > 0) j["createdBy"] = r.created_by;
        if (r.created_at > 0) j["createdAt"] = r.created_at;
        return j;
    }

    // === Auftrag serialization ===
    static json serializeAuftrag(const org::projectforge::business::fibu::Auftrag& a) {
        json j;
        j["id"] = a.id;
        if (!a.nummer.empty()) j["nummer"] = a.nummer;
        if (!a.titel.empty()) j["titel"] = a.titel;
        if (!a.beschreibung.empty()) j["beschreibung"] = a.beschreibung;
        if (a.kunde_id > 0) j["kundeId"] = a.kunde_id;
        if (a.kontakt_id > 0) j["kontaktId"] = a.kontakt_id;
        if (a.projekt_id > 0) j["projektId"] = a.projekt_id;
        if (!a.status.empty()) j["status"] = a.status;
        if (a.erstellungsdatum > 0) j["erstellungsdatum"] = a.erstellungsdatum;
        if (a.angebotsdatum > 0) j["angebotsdatum"] = a.angebotsdatum;
        if (a.bestaetigungsdatum > 0) j["bestaetigungsdatum"] = a.bestaetigungsdatum;
        if (a.lieferdatum > 0) j["lieferdatum"] = a.lieferdatum;
        if (a.faelligkeitsdatum > 0) j["faelligkeitsdatum"] = a.faelligkeitsdatum;
        j["nettosumme"] = a.nettosumme;
        j["bruttosumme"] = a.bruttosumme;
        j["mwstSumme"] = a.mwst_summe;
        j["mwstSatz"] = a.mwst_satz;
        j["waehrung"] = a.waehrung;
        if (!a.zahlungsbedingungen.empty()) j["zahlungsbedingungen"] = a.zahlungsbedingungen;
        if (!a.referenz.empty()) j["referenz"] = a.referenz;
        if (a.created_by > 0) j["createdBy"] = a.created_by;
        if (a.verantwortlicher_id > 0) j["verantwortlicherId"] = a.verantwortlicher_id;
        return j;
    }

    // === Vacation serialization ===
    static json serializeVacation(const org::projectforge::business::vacation::Vacation& v) {
        json j;
        j["id"] = v.id;
        j["userId"] = v.user_id;
        j["startDate"] = v.start_date;
        j["endDate"] = v.end_date;
        j["days"] = v.days;
        j["halfDayBegin"] = v.half_day_begin;
        j["halfDayEnd"] = v.half_day_end;
        j["type"] = v.type;
        j["status"] = v.status;
        if (!v.comment.empty()) j["comment"] = v.comment;
        if (v.requested_at > 0) j["requestedAt"] = v.requested_at;
        if (v.approved_at > 0) j["approvedAt"] = v.approved_at;
        if (v.approved_by > 0) j["approvedBy"] = v.approved_by;
        if (v.substitute_user_id > 0) j["substituteUserId"] = v.substitute_user_id;
        j["substitutionAccepted"] = v.substitution_accepted;
        return j;
    }

    static json serializeVacations(const std::vector<org::projectforge::business::vacation::Vacation>& vacs) {
        json arr = json::array();
        for (auto& v : vacs) arr.push_back(serializeVacation(v));
        return arr;
    }

    // === HR Planning serialization ===
    static json serializeHrPlanningEntry(const org::projectforge::business::humanresources::HrPlanningEntry& e) {
        json j;
        j["id"] = e.id;
        j["userId"] = e.user_id;
        if (e.task_id > 0) j["taskId"] = e.task_id;
        if (e.projekt_id > 0) j["projektId"] = e.projekt_id;
        if (e.start_date > 0) j["startDate"] = e.start_date;
        if (e.end_date > 0) j["endDate"] = e.end_date;
        j["plannedHours"] = e.planned_hours;
        j["actualHours"] = e.actual_hours;
        if (!e.status.empty()) j["status"] = e.status;
        if (!e.description.empty()) j["description"] = e.description;
        if (e.kost2_id > 0) j["kost2Id"] = e.kost2_id;
        if (e.week_of_year > 0) j["weekOfYear"] = e.week_of_year;
        if (e.year > 0) j["year"] = e.year;
        return j;
    }

    // === Book serialization ===
    static json serializeBook(const org::projectforge::business::book::Book& book) {
        json j;
        j["id"] = book.id;
        j["title"] = book.title;
        if (!book.author.empty()) j["author"] = book.author;
        if (!book.isbn.empty()) j["isbn"] = book.isbn;
        if (!book.publisher.empty()) j["publisher"] = book.publisher;
        if (!book.description.empty()) j["description"] = book.description;
        j["publicationYear"] = book.publication_year;
        j["edition"] = book.edition;
        j["totalPages"] = book.total_pages;
        if (book.owner_id > 0) j["ownerId"] = book.owner_id;
        if (book.borrowed_by > 0) j["borrowedBy"] = book.borrowed_by;
        if (book.borrowed_date > 0) j["borrowedDate"] = book.borrowed_date;
        if (book.due_date > 0) j["dueDate"] = book.due_date;
        if (!book.status.empty()) j["status"] = book.status;
        if (!book.category.empty()) j["category"] = book.category;
        j["eBook"] = book.e_book;
        return j;
    }

    // === Filter serialization ===
    static json serializeUserFilter(const org::projectforge::business::user::UserFilter& filter) {
        json j;
        j["id"] = filter.id;
        j["userId"] = filter.user_id;
        j["filterName"] = filter.filter_name;
        if (!filter.filter_data.empty()) {
            try { j["filterData"] = json::parse(filter.filter_data); }
            catch (...) { j["filterData"] = filter.filter_data; }
        }
        j["shared"] = filter.shared;
        if (filter.created_at > 0) j["createdAt"] = filter.created_at;
        return j;
    }

    // === General helpers ===
    static json serializePaginated(const json& data, size_t total, size_t page, size_t pageSize) {
        size_t totalPages = pageSize > 0 ? (total + pageSize - 1) / pageSize : 0;
        return {
            {"data", data},
            {"pagination", {
                {"page", page},
                {"pageSize", pageSize},
                {"total", total},
                {"totalPages", totalPages},
                {"hasNext", page < totalPages},
                {"hasPrevious", page > 1}
            }}
        };
    }

    static json createErrorResponse(const std::string& message, int statusCode = 400) {
        return {
            {"status", statusCode},
            {"error", statusCode >= 500 ? "Internal Server Error" :
                      statusCode == 404 ? "Not Found" :
                      statusCode == 403 ? "Forbidden" :
                      statusCode == 401 ? "Unauthorized" : "Bad Request"},
            {"message", message},
            {"timestamp", std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count()}
        };
    }

    static json createSuccessResponse(const std::string& message) {
        return {{"success", true}, {"message", message}};
    }

    static json createIdResponse(int64_t id) {
        return {{"id", id}};
    }

    // Field selection (sparse fieldsets)
    static json selectFields(const json& obj, const std::string& fieldsStr) {
        if (fieldsStr.empty()) return obj;
        std::set<std::string> fields;
        std::istringstream ss(fieldsStr);
        std::string field;
        while (std::getline(ss, field, ',')) {
            if (!field.empty()) fields.insert(field);
        }
        json result;
        for (auto& f : fields) {
            if (obj.contains(f)) result[f] = obj[f];
        }
        return result.empty() ? obj : result;
    }

    static json selectFields(const json& arr, const std::vector<std::string>& fields) {
        if (fields.empty()) return arr;
        std::set<std::string> fieldSet(fields.begin(), fields.end());
        if (arr.is_array()) {
            json result = json::array();
            for (auto& item : arr) {
                json filtered;
                for (auto& f : fieldSet) {
                    if (item.contains(f)) filtered[f] = item[f];
                }
                result.push_back(filtered.empty() ? item : filtered);
            }
            return result;
        }
        return arr;
    }

    // Expand/include related resources
    static json expandRelations(const json& obj, const std::string& expandStr,
                                std::function<json(const std::string&, int64_t)> relationLoader) {
        if (expandStr.empty() || !relationLoader) return obj;
        json result = obj;
        std::istringstream ss(expandStr);
        std::string relation;
        while (std::getline(ss, relation, ',')) {
            if (!relation.empty() && obj.contains("id")) {
                int64_t id = obj["id"].get<int64_t>();
                json relData = relationLoader(relation, id);
                if (!relData.empty()) result[relation] = relData;
            }
        }
        return result;
    }

    // CSV serialization for exports
    static std::string toCsv(const std::vector<json>& objects, const std::vector<std::string>& columns,
                             const std::string& delimiter = ",", bool includeHeader = true) {
        std::ostringstream ss;
        if (includeHeader && !columns.empty()) {
            for (size_t i = 0; i < columns.size(); ++i) {
                if (i > 0) ss << delimiter;
                ss << escapeCsvField(columns[i]);
            }
            ss << "\n";
        }
        for (auto& obj : objects) {
            for (size_t i = 0; i < columns.size(); ++i) {
                if (i > 0) ss << delimiter;
                std::string val;
                if (obj.contains(columns[i])) {
                    if (obj[columns[i]].is_string()) val = obj[columns[i]].get<std::string>();
                    else val = obj[columns[i]].dump();
                }
                ss << escapeCsvField(val);
            }
            ss << "\n";
        }
        return ss.str();
    }

    static std::string escapeCsvField(const std::string& field) {
        if (field.find_first_of(",\"\n\r") != std::string::npos) {
            std::string escaped = "\"";
            for (char c : field) {
                if (c == '"') escaped += "\"\"";
                else escaped += c;
            }
            escaped += "\"";
            return escaped;
        }
        return field;
    }

    // Date helpers
    static std::string formatTimestamp(int64_t ts, const std::string& format = "%Y-%m-%dT%H:%M:%SZ") {
        if (ts <= 0) return "";
        auto tp = std::chrono::system_clock::from_time_t(ts);
        auto time = std::chrono::system_clock::to_time_t(tp);
        std::ostringstream ss;
        ss << std::put_time(std::gmtime(&time), format.c_str());
        return ss.str();
    }

    static int64_t parseTimestamp(const std::string& dateStr) {
        if (dateStr.empty()) return 0;
        std::tm tm = {};
        std::istringstream ss(dateStr);
        ss >> std::get_time(&tm, "%Y-%m-%dT%H:%M:%SZ");
        if (ss.fail()) {
            ss.clear();
            ss.str(dateStr);
            ss >> std::get_time(&tm, "%Y-%m-%d");
            if (ss.fail()) return 0;
        }
        return std::mktime(&tm);
    }
};

} // namespace org::projectforge::rest
