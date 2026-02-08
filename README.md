## 🏦 Bank System Project (Version 2)

A console-based Banking Management System developed in C++ as a learning project.
This project was built to practice and improve Object-Oriented Programming (OOP), file handling, and basic system design concepts while simulating real-world banking operations.

Note: This project is for educational purposes and continuous improvement. It is not intended for production use.
--------
## 🚀 Features
👥 Client Management

View all registered clients with full details

Add new clients to the system

Update or delete existing client records (CRUD operations)

Search for clients using an Account Number
----------------
## 💰 Transaction Management

Deposit and withdraw funds

Display total balances across all accounts

Transfer money between two accounts with real-time balance updates

Maintain a Transfer Log for tracking all transactions
------------------------
## 🔐 User & Security Management

Multi-user system with login functionality

Permission-based access control (Admin vs Standard User)

Restricted actions based on user role (e.g., deleting clients, viewing logs)

Login Registry to track and audit login activity
-----------------
##  🛠️ Technical Highlights

Object-Oriented Design: Modular, class-based architecture

Encapsulation: Proper use of private/public members for data protection

File Handling: Persistent storage using text files for clients, users, and logs

Input Validation: Prevents invalid input and runtime crashes

Scalable Design: Structured to allow future extensions
---------------------------
## 📁 Project Structure

Core Logic

     Classes for managing Clients, Users, and Banking Operations:

Library Layer

      Utility classes for input handling, string processing, and date/time formatting:

Data Layer

        Text-based files used as a lightweight database for:

   Clients

   Users

  Transfer logs

  Login records
--------------------
## ⚙️ Technologies Used

Language: C++

Paradigm: Object-Oriented Programming (OOP)

Storage: File-based persistence (text files)

Compiler: Any C++ compiler supporting C++11
