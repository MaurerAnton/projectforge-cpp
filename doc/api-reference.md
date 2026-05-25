// ProjectForge C++ port — GPL v3

# ProjectForge C++ API Reference

## Namespaces

### org::projectforge::common
Foundation utilities: StringHelper, DateHelper, NumberHelper, CryptoHelper, XmlHelper, I18nHelper, FileHelper, ConfigHelper, BeanHelper, Logging

### org::projectforge::model::rest  
Data objects: AbstractBaseObject, UserObject, TaskObject, TimesheetObject, AddressObject, CalendarObject, Cost2Object, RestPaths

### org::projectforge::jcr
Content Repository: JcrNode, JcrRepository, FileSystemJcrBackend, SqliteJcrBackend, ContentRepositoryManager

### org::projectforge::framework::persistence
Base DAO with QueryFilter, SortProperty, HistoryService, ExtendedBaseDO, AdvancedBaseDao

### org::projectforge::framework::access
AccessControl: AccessChecker, GroupTaskAccessEntry, AccessType, OperationType

### org::projectforge::framework::jobs
Background Jobs: JobHandler, AbstractJob, JobStatus, JobResult

### org::projectforge::business::fibu
Financial Accounting: KontoEntity/KontoDao, RechnungEntity/RechnungDao, AuftragEntity/AuftragDao, KostEntity/KostDao, DatevExportService, SepaXmlBuilder, FibuService, AccountingService, BudgetService, DepreciationService

### org::projectforge::business::timesheet
Timesheet Tracking: TimesheetDO/TimesheetDao, TimesheetFilter, TimesheetBookingStatus, TimesheetReportService

### org::projectforge::business::task
Task Management: TaskEntity/TaskDao, TaskNode, GanttEntryEntity

### org::projectforge::business::user
User Management: UserEntity/UserDao, GroupEntity/GroupDao

### org::projectforge::business::address
Address Book: AddressEntity/AddressDao, ContactStatusEntity, VCardService

### org::projectforge::business::calendar
Calendar: CalendarEntity, CalendarEventEntity/CalendarEventDao, TeamCalendarEntity/TeamCalendarDao

### org::projectforge::business::hr
HR Planning: HRPlanningEntity/HRPlanningDao, LeaveAccountEntity/LeaveAccountDao, VacationEntryEntity/VacationDao

### org::projectforge::business::poll
Polls: PollEntity, PollOptionEntity

### org::projectforge::business::book
Books: BookEntity

### org::projectforge::business::admin
Administration: AdminDashboardEntity, SystemLogEntry, ConfigurationEntry

### org::projectforge::business::dvelop
DVelop Integration: DvelopConfig, DvelopEntry

### org::projectforge::business::ldap
LDAP Integration: LdapConfig, LdapEntry

### org::projectforge::business::login
Login Service: LoginConfig, LoginEntry

### org::projectforge::business::orga
Organization: OrgaConfig, OrgaEntry

### org::projectforge::business::privacyprotection
GDPR/Privacy: PrivacyConfig, PrivacyEntry

### org::projectforge::business::sipgate
SIPgate Telephony: SipgateConfig, SipgateEntry

### org::projectforge::business::scripting
Scripting Engine: ScriptConfig, ScriptEntry

### org::projectforge::business::gantt
Gantt Charts: GanttConfig, GanttEntry

### org::projectforge::business::image
Image Processing: ImageConfig, ImageEntry

### org::projectforge::business::jobs
Job Management: JobsConfig, JobsEntry

### org::projectforge::business::common
Common Utilities: CommonConfig, CommonEntry

### org::projectforge::business::configuration
System Configuration: SysConfig, ConfigEntry

### org::projectforge::business::system
System Services: SystemConfig, SystemEntry

### org::projectforge::rest
REST API Controllers: ResponseBuilder, RestAuthMiddleware, UserPagesRest, TaskPagesRest, TimesheetPagesRest, AddressPagesRest, CalendarPagesRest, FibuPagesRest, RechnungPagesRest, KontoPagesRest, AuftragPagesRest, HRPlanningPagesRest, VacationPagesRest, AuthRest, MyMenuPageRest, IndexRest, + 22 more domain controllers

### org::projectforge::wicket
Server-side UI: Component, Label, TextField, DropDownChoice, CheckBox, Button, DataTable, PagingNavigator, FeedbackPanel, Form, BasePage, BaseListPage, BaseEditPage, + 34 page implementations

### org::projectforge::carddav
CardDAV Server: VCardParser, CardDavServer

### org::projectforge::idp
Identity Provider: OAuth2Handler, TokenEndpoint, UserInfoEndpoint, OpenIdConfiguration

### org::projectforge::mail
Mail Service: SendMail, MailMessage, MailAttachment

### org::projectforge::messaging
SMS/Messaging: SmsSender

### org::projectforge::menu
Menu System: MenuItem, MenuCreator, MenuItemDefId

### org::projectforge::security
Security: TimeBasedOTP, TwoFAService, SessionCsrfService

### org::projectforge::web
Web Utilities: WebUtils (escape, encode, parse, build URLs)

### org::projectforge::test
Test Framework: TestSuite with assertions

## REST API Endpoints

| Method | Path | Controller |
|--------|------|------------|
| POST | /api/v1/auth/login | AuthRest |
| POST | /api/v1/auth/logout | AuthRest |
| POST | /api/v1/auth/changePassword | AuthRest |
| GET/POST | /api/v1/users | UserPagesRest |
| GET/PUT/DELETE | /api/v1/users/{id} | UserPagesRest |
| GET | /api/v1/users/search | UserPagesRest |
| GET/POST | /api/v1/tasks | TaskPagesRest |
| GET/PUT/DELETE | /api/v1/tasks/{id} | TaskPagesRest |
| PUT | /api/v1/tasks/{id}/progress | TaskPagesRest |
| GET/POST | /api/v1/timesheets | TimesheetPagesRest |
| GET/PUT/DELETE | /api/v1/timesheets/{id} | TimesheetPagesRest |
| POST | /api/v1/timesheets/start | TimesheetPagesRest |
| POST | /api/v1/timesheets/stop/{id} | TimesheetPagesRest |
| GET | /api/v1/timesheets/active | TimesheetPagesRest |
| GET/POST | /api/v1/addresses | AddressPagesRest |
| GET/PUT/DELETE | /api/v1/addresses/{id} | AddressPagesRest |
| GET | /api/v1/calendars | CalendarPagesRest |
| GET | /api/v1/calendars/events | CalendarPagesRest |
| GET | /api/v1/fibu/kontos | FibuPagesRest |
| GET | /api/v1/fibu/kost | FibuPagesRest |
| GET | /api/v1/fibu/overview | FibuPagesRest |
| GET | /api/v1/fibu/export/datev | FibuPagesRest |
| GET/POST | /api/v1/rechnung | RechnungPagesRest |
| GET | /api/v1/rechnung/{id} | RechnungPagesRest |
| POST | /api/v1/rechnung/{id}/pay | RechnungPagesRest |
| POST | /api/v1/rechnung/{id}/cancel | RechnungPagesRest |
| GET | /api/v1/rechnung/export/sepa | RechnungPagesRest |
| GET/POST | /api/v1/auftrag | AuftragPagesRest |
| GET | /api/v1/hrplanning | HRPlanningPagesRest |
| GET | /api/v1/hrplanning/user/{uid} | HRPlanningPagesRest |
| GET/POST | /api/v1/vacation | VacationPagesRest |
| POST | /api/v1/vacation/approve/{id} | VacationPagesRest |
| POST | /api/v1/vacation/reject/{id} | VacationPagesRest |
| GET | /api/v1/vacation/remaining/{uid} | VacationPagesRest |
| GET/POST | /api/v1/polls | PollPagesRest |
| POST | /api/v1/polls/{id}/vote | PollPagesRest |
| GET | /api/v1/books | BookPagesRest |
| GET | /api/v1/menu | MyMenuPageRest |
| GET | /api/v1/index | IndexRest |
| GET | /api/v1/health | IndexRest |
| GET | /api/v1/admin/system | AdminPagesRest |
| GET | /api/v1/admin/jobs | AdminPagesRest |
| GET/POST | /api/v1/export | ExportPagesRest |
| POST | /api/v1/import | ImportPagesRest |
| GET/POST/DELETE | /api/v1/files | FilePagesRest |
| GET | /api/v1/search | SearchPagesRest |
| GET | /api/v1/notifications | NotificationPagesRest |
| GET | /api/v1/statistics | StatisticsPagesRest |
| GET | /api/v1/dashboard | DashboardPagesRest |
| GET/POST/DELETE | /api/v1/webhooks | WebhookPagesRest |
| GET/POST/DELETE | /api/v1/apikeys | ApiKeyPagesRest |
| GET/POST | /api/v1/tenants | TenantPagesRest |
| GET | /api/v1/plugins | PluginPagesRest |
| GET/PUT | /api/v1/config | ConfigurationPagesRest |
| GET | /api/v1/admin/logs | SystemLogPagesRest |
| POST/GET | /api/v1/admin/backup | BackupPagesRest |
