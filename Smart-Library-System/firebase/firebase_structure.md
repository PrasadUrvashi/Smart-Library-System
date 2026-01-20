# 🔥 Firebase Realtime Database Structure

This document describes the Firebase database structure used in the Smart Library System.

---

## 📚 Books Node

Stores all book-related information including availability and borrower details.

Books/
└── bookId/
├── title: string
├── author: string
├── status: "available" | "issued"
├── borrower: string
├── borrowerEmail: string
├── borrowDate: string
└── dueDate: string


### 📌 Example
Books/
└── 90/
├── title: "Reference Book For Radio Engineering"
├── author: "Federal Telephone"
├── status: "available"
├── borrower: ""
├── borrowerEmail: ""
├── borrowDate: ""
└── dueDate: ""


---

## 🪑 Seats Node

Manages seat availability and reservation status inside the library.

Seats/
└── seatId/
├── Status: "available" | "occupied"
├── autoDetected: boolean
├── reservedByApp: boolean
└── user: string


### 📌 Example

Seats/
└── Seat1/
├── Status: "available"
├── autoDetected: false
├── reservedByApp: false
└── user: ""
