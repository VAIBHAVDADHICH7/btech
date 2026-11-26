# Software Requirements Specification (SRS) — IEEE 830 Template
**Project**: Campus Library Management System (CLMS)

## 1. Introduction
- **1.1 Purpose**: Define functional and non-functional requirements for automating book cataloging, borrowing, returns, and fine calculation.
- **1.2 Scope**: Web and desktop portal used by Students, Faculty, and Librarians.
- **1.3 Definitions**: ISBN (International Standard Book Number), OPAC (Online Public Access Catalog).

## 2. Overall Description
- **2.1 Product Perspective**: Replaces manual ledger registers with a centralized relational database.
- **2.2 User Classes**: Librarian (full CRUD), Student/Faculty (search, reserve, view history).
- **2.3 Constraints**: Must support concurrent access for up to 500 users.

## 3. Specific Requirements
- **FR-01**: Users shall search books by Title, Author, or ISBN.
- **FR-02**: Librarians shall issue available books and record due dates (14-day default).
- **FR-03**: System shall compute overdue fines at Rs. 2/day automatically upon return.
- **NFR-01 (Performance)**: Search queries shall return within 1.5 seconds.
- **NFR-02 (Security)**: Passwords shall be stored using salted cryptographic hashes.
