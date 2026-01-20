# 📚 Smart Library System

IoT-based Smart Library System using Firebase, QR Codes, and MIT App Inventor
## 📌 Project Overview

The **Smart Library System** is an IoT-based application designed to automate and simplify library management. The system enables QR-code-based book issuing, real-time book and seat availability tracking using Firebase, and automated return reminders using Google Apps Script. The application is developed using **MIT App Inventor** with optional **Arduino-based hardware integration**.

---

## 🎯 Objectives

* Digitize book issuing and return process
* Reduce manual record keeping
* Track book availability in real time
* Manage library seat availability
* Send automatic reminders for book returns

---

## 🚀 Key Features

* 📖 QR-code-based book issue system
* 🔥 Firebase Realtime Database integration
* 🪑 Seat availability and reservation tracking
* ⏰ Automated email reminders using Google Apps Script
* 📱 Simple and user-friendly Android application
* 🤖 Optional Arduino-based hardware support

---

## 🛠️ Technologies Used

* **MIT App Inventor** – Mobile application development
* **Google Firebase** – Realtime database
* **Google Apps Script** – Email reminder automation
* **Arduino IDE** – Hardware integration (optional)
* **QR Code Technology** – Book identification

---

## 📂 Project Folder Structure

```
Smart-Library-System/
│
├── app/
│   └── SmartLibrary.aia
│
├── arduino/
│   └── smart_library_arduino.ino
│
├── google-script/
│   └── reminder_script.js
│
├── firebase/
│   └── firebase_structure.md
│
├── screenshots/
│   ├── home_screen.png
│   ├── qr_scan.png
│   ├── firebase_books.png
│   └── firebase_seats.png
│
└── README.md
```

---

## 🔥 Firebase Database Structure

The database consists of two main nodes:

### 📚 Books

Stores book details and issue status.

* Title
* Author
* Borrower details
* Issue and due dates
* Availability status

### 🪑 Seats

Tracks library seat availability.

* Seat status (available / occupied)
* Auto-detection flag
* App reservation status
* User information

(Detailed structure is documented in `firebase/firebase_structure.md`)

---

## 📱 How to Run the Project

1. Open **MIT App Inventor**: [https://ai2.appinventor.mit.edu](https://ai2.appinventor.mit.edu)
2. Import the `.aia` file from the `app/` folder
3. Connect the project to your Firebase Realtime Database
4. Deploy Google Apps Script for reminder automation
5. Build and install the APK on an Android device

---

## 📷 Output Screenshots




### 📌 Home Screen UI


![home_screen](https://github.com/user-attachments/assets/fdeb5251-ea64-462d-97c7-49930faa92a3)


### 📌 QR code to scan to book to borrow or return book
<img width="1100" height="570" alt="qr_scan_book_borrow" src="https://github.com/user-attachments/assets/098bab9d-5675-4268-9ce2-669e2422195f" />



### 📌 Firebase Database Structure for books

<img width="1100" height="570" alt="firebase_books" src="https://github.com/user-attachments/assets/e64bf5ab-7a5a-4251-abae-40a37366e1d6" />

### 📌 Firebase Database Structure for seats

<img width="1100" height="570" alt="firebase_seats" src="https://github.com/user-attachments/assets/ea696556-c7e0-4ddd-8011-216e38772d95" />



---

## 🔐 Security Note

Sensitive information such as Firebase API keys, authentication tokens, and email credentials are **not included** in this repository for security reasons.

---

## 👩‍💻 Developed By

**Urvashi Prasad**
Diploma Student – Information and Communication Technology (ICT)
Aspiring Semiconductor / VLSI Engineer

---

## 📌 Future Enhancements

* User authentication system
* Admin dashboard
* Advanced analytics for book usage
* Full hardware-based seat detection system

---

⭐ *If you like this project, feel free to star the repository!*
