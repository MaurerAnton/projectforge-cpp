// ProjectForge C++ port — GPL v3
-- ProjectForge C++ — Database Schema (SQLite)
-- Equivalent to all Flyway migrations in original project

CREATE TABLE IF NOT EXISTS pf_user (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT NOT NULL UNIQUE,
    password_hash TEXT NOT NULL,
    salt TEXT NOT NULL,
    first_name TEXT,
    last_name TEXT,
    email TEXT,
    phone TEXT,
    mobile_phone TEXT,
    description TEXT,
    organization TEXT,
    position TEXT,
    locale TEXT DEFAULT 'en',
    local_user INTEGER DEFAULT 1,
    restricted_user INTEGER DEFAULT 0,
    hr_planning INTEGER DEFAULT 0,
    deactivated INTEGER DEFAULT 0,
    stay_logged_in INTEGER DEFAULT 0,
    failed_login_attempts INTEGER DEFAULT 0,
    last_login INTEGER,
    password_changed INTEGER,
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0,
    tenant INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_group (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT NOT NULL UNIQUE,
    description TEXT,
    local_group INTEGER DEFAULT 1,
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_user_group (
    user_id INTEGER NOT NULL,
    group_id INTEGER NOT NULL,
    PRIMARY KEY(user_id, group_id)
);

CREATE TABLE IF NOT EXISTS pf_task (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT NOT NULL,
    short_description TEXT,
    description TEXT,
    parent_task_id INTEGER,
    responsible_user_id INTEGER,
    reference TEXT,
    status TEXT DEFAULT 'NEW',
    priority INTEGER DEFAULT 3,
    progress INTEGER DEFAULT 0,
    start_date INTEGER,
    deadline INTEGER,
    duration INTEGER DEFAULT 0,
    duration_planned INTEGER DEFAULT 0,
    max_hours INTEGER DEFAULT 0,
    cost_budget REAL DEFAULT 0,
    favorite INTEGER DEFAULT 0,
    protection_of_privacy INTEGER DEFAULT 0,
    task_type TEXT,
    sort_order INTEGER DEFAULT 0,
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_timesheet (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER NOT NULL,
    task_id INTEGER NOT NULL,
    start_time INTEGER NOT NULL,
    stop_time INTEGER,
    duration INTEGER DEFAULT 0,
    description TEXT,
    location TEXT,
    kost2_id INTEGER,
    booking_status TEXT DEFAULT 'NOT_BOOKED',
    invoiced INTEGER DEFAULT 0,
    weekend INTEGER DEFAULT 0,
    tags TEXT,
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_address (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    first_name TEXT,
    last_name TEXT,
    form_of_address TEXT,
    title TEXT,
    organization TEXT,
    division TEXT,
    street TEXT,
    zip_code TEXT,
    city TEXT,
    country TEXT DEFAULT 'DE',
    state TEXT,
    email TEXT,
    website TEXT,
    phone TEXT,
    mobile_phone TEXT,
    fax TEXT,
    private_email TEXT,
    private_phone TEXT,
    private_mobile TEXT,
    private_street TEXT,
    private_zip_code TEXT,
    private_city TEXT,
    private_country TEXT,
    remarks TEXT,
    vat_id TEXT,
    commercial_register TEXT,
    iban TEXT,
    bic TEXT,
    bank_name TEXT,
    account_holder TEXT,
    payment_type TEXT DEFAULT 'BANK_TRANSFER',
    address_type TEXT DEFAULT 'BUSINESS',
    communication_language TEXT DEFAULT 'DE',
    discount REAL DEFAULT 0,
    payment_days INTEGER DEFAULT 30,
    favorite INTEGER DEFAULT 0,
    longitude REAL DEFAULT 0,
    latitude REAL DEFAULT 0,
    contact_status_id INTEGER,
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_rechnung (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    number INTEGER NOT NULL,
    subject TEXT,
    status TEXT DEFAULT 'NEW',
    type TEXT DEFAULT 'OUTGOING',
    customer_id INTEGER,
    contact_person_id INTEGER,
    project_id INTEGER,
    date INTEGER,
    due_date INTEGER,
    payment_date INTEGER,
    delivery_date INTEGER,
    payment_type TEXT DEFAULT 'BANK_TRANSFER',
    currency TEXT DEFAULT 'EUR',
    discount_percent REAL DEFAULT 0,
    discount_days INTEGER DEFAULT 0,
    net_sum REAL DEFAULT 0,
    vat_sum REAL DEFAULT 0,
    gross_sum REAL DEFAULT 0,
    comment TEXT,
    customer_ref1 TEXT,
    customer_ref2 TEXT,
    payment_info TEXT,
    konto_id INTEGER,
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_rechnung_position (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    rechnung_id INTEGER NOT NULL,
    number INTEGER NOT NULL,
    text TEXT,
    net_amount REAL DEFAULT 0,
    vat_type TEXT DEFAULT 'FULL',
    quantity REAL DEFAULT 1,
    unit_price REAL DEFAULT 0,
    kost2_id INTEGER
);

CREATE TABLE IF NOT EXISTS pf_konto (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    number INTEGER NOT NULL,
    name TEXT NOT NULL,
    description TEXT,
    type TEXT,
    category TEXT,
    parent_konto_id INTEGER,
    active INTEGER DEFAULT 1,
    balance REAL DEFAULT 0,
    budget REAL DEFAULT 0,
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_kost (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    number INTEGER NOT NULL,
    name TEXT NOT NULL,
    description TEXT,
    kost1_id INTEGER,
    type TEXT,
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_auftrag (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    number INTEGER NOT NULL,
    subject TEXT,
    status TEXT DEFAULT 'NEW',
    type TEXT DEFAULT 'ORDER',
    customer_id INTEGER,
    project_id INTEGER,
    order_date INTEGER,
    delivery_date INTEGER,
    reference TEXT,
    net_sum REAL DEFAULT 0,
    gross_sum REAL DEFAULT 0,
    comment TEXT,
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_calendar (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT NOT NULL,
    description TEXT,
    color TEXT DEFAULT '#3366CC',
    owner_id INTEGER,
    type TEXT DEFAULT 'PERSONAL',
    visible INTEGER DEFAULT 1,
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_calendar_event (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    subject TEXT,
    location TEXT,
    note TEXT,
    start_date INTEGER,
    end_date INTEGER,
    all_day INTEGER DEFAULT 0,
    recurrence_rule TEXT,
    organizer_id INTEGER,
    calendar_id INTEGER,
    uid TEXT,
    status TEXT DEFAULT 'CONFIRMED',
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_vacation (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER NOT NULL,
    start_date INTEGER,
    end_date INTEGER,
    status TEXT DEFAULT 'REQUESTED',
    comment TEXT,
    days INTEGER DEFAULT 0,
    approved_by INTEGER,
    substitute_id INTEGER,
    leave_type TEXT DEFAULT 'VACATION',
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_hr_planning (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    user_id INTEGER,
    planned_hours INTEGER DEFAULT 0,
    actual_hours INTEGER DEFAULT 0,
    start_date INTEGER,
    end_date INTEGER,
    description TEXT,
    project_id INTEGER,
    task_id INTEGER,
    status TEXT DEFAULT 'PLANNED',
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_book (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT,
    author TEXT,
    isbn TEXT,
    description TEXT,
    year INTEGER DEFAULT 2026,
    pages INTEGER DEFAULT 0,
    publisher TEXT,
    category TEXT,
    rating INTEGER DEFAULT 0,
    available INTEGER DEFAULT 1,
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_poll (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    question TEXT,
    description TEXT,
    owner_id INTEGER,
    start_date INTEGER,
    end_date INTEGER,
    multiple_choice INTEGER DEFAULT 0,
    is_active INTEGER DEFAULT 1,
    total_votes INTEGER DEFAULT 0,
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_poll_option (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    poll_id INTEGER NOT NULL,
    text TEXT,
    position INTEGER DEFAULT 0,
    vote_count INTEGER DEFAULT 0,
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_memo (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    title TEXT,
    content TEXT,
    owner_id INTEGER,
    created INTEGER NOT NULL,
    last_update INTEGER NOT NULL,
    deleted INTEGER DEFAULT 0
);

CREATE TABLE IF NOT EXISTS pf_system_log (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    level TEXT,
    message TEXT,
    category TEXT DEFAULT 'SYSTEM',
    timestamp INTEGER,
    user_id INTEGER
);

CREATE TABLE IF NOT EXISTS pf_configuration (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    key TEXT NOT NULL UNIQUE,
    value TEXT,
    description TEXT,
    type TEXT DEFAULT 'STRING',
    encrypted INTEGER DEFAULT 0
);

-- Indexes for performance
CREATE INDEX IF NOT EXISTS idx_timesheet_user ON pf_timesheet(user_id);
CREATE INDEX IF NOT EXISTS idx_timesheet_task ON pf_timesheet(task_id);
CREATE INDEX IF NOT EXISTS idx_timesheet_dates ON pf_timesheet(start_time, stop_time);
CREATE INDEX IF NOT EXISTS idx_task_parent ON pf_task(parent_task_id);
CREATE INDEX IF NOT EXISTS idx_task_responsible ON pf_task(responsible_user_id);
CREATE INDEX IF NOT EXISTS idx_task_status ON pf_task(status);
CREATE INDEX IF NOT EXISTS idx_address_name ON pf_address(name);
CREATE INDEX IF NOT EXISTS idx_address_email ON pf_address(email);
CREATE INDEX IF NOT EXISTS idx_rechnung_customer ON pf_rechnung(customer_id);
CREATE INDEX IF NOT EXISTS idx_rechnung_status ON pf_rechnung(status);
CREATE INDEX IF NOT EXISTS idx_rechnung_dates ON pf_rechnung(date, due_date);
CREATE INDEX IF NOT EXISTS idx_calendar_event_dates ON pf_calendar_event(start_date, end_date);
CREATE INDEX IF NOT EXISTS idx_calendar_event_cal ON pf_calendar_event(calendar_id);
CREATE INDEX IF NOT EXISTS idx_vacation_user ON pf_vacation(user_id);
CREATE INDEX IF NOT EXISTS idx_vacation_status ON pf_vacation(status);
CREATE INDEX IF NOT EXISTS idx_hr_planning_user ON pf_hr_planning(user_id);

-- Default data
INSERT OR IGNORE INTO pf_user (id, username, password_hash, salt, first_name, last_name, email, locale, created, last_update)
VALUES (1, 'admin', 'DEADBEEF', 'SALT0001', 'Admin', 'User', 'admin@projectforge.org', 'en',
    CAST(strftime('%s','now')*1000 AS INTEGER), CAST(strftime('%s','now')*1000 AS INTEGER));

INSERT OR IGNORE INTO pf_configuration (key, value, description, type)
VALUES ('app.name', 'ProjectForge C++', 'Application name', 'STRING');

INSERT OR IGNORE INTO pf_configuration (key, value, description, type)
VALUES ('app.version', '8.2.0', 'Application version', 'STRING');

INSERT OR IGNORE INTO pf_configuration (key, value, description, type)
VALUES ('app.locale', 'en', 'Default locale', 'STRING');

INSERT OR IGNORE INTO pf_configuration (key, value, description, type)
VALUES ('mail.enabled', 'false', 'Mail enabled', 'BOOLEAN');

INSERT OR IGNORE INTO pf_configuration (key, value, description, type)
VALUES ('mail.host', '', 'SMTP host', 'STRING');

INSERT OR IGNORE INTO pf_configuration (key, value, description, type)
VALUES ('timesheet.max_duration_hours', '24', 'Maximum timesheet duration in hours', 'INTEGER');

INSERT OR IGNORE INTO pf_configuration (key, value, description, type)
VALUES ('vacation.default_days', '30', 'Default vacation days per year', 'INTEGER');
