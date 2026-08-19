# Smart Exam Hall Seating System

A C++ Object-Oriented Programming project that automatically generates an examination hall seating arrangement for students from the Electronics and Computer department.

The system is designed specifically for BCT (Computer Engineering) and BEI (Electronics and Communication Engineering) students of batch 082.

---

## Objective

The objective of this project is to automate examination hall seating while following predefined classroom constraints.

The system validates student roll numbers, prevents duplicate entries, checks room capacity, and generates a balanced seating arrangement between BCT and BEI students.

---

## Features

- Accepts the number of students as input
- Accepts student roll numbers
- Supports BCT and BEI departments
- Validates roll number format
- Allows only batch 082
- Allows roll numbers from 001 to 048
- Prevents duplicate roll numbers
- Supports up to 48 students
- Allows 3 students per bench
- Accepts room number and number of benches
- Automatically checks room capacity
- Separates BCT and BEI students
- Alternates departments across benches
- Displays the seating arrangement in a matrix-style format

---

## Roll Number Format

The system uses the roll number format:

    THA082BCT027

Where:

- `THA` = Institute
- `082` = Batch
- `BCT` / `BEI` = Engineering department
- `027` = Student roll number

### Valid Roll Numbers

BCT:

    THA082BCT001 - THA082BCT048

BEI:

    THA082BEI001 - THA082BEI048

The system rejects:

- Incorrect institute code
- Incorrect batch number
- Invalid department
- Roll numbers outside 001–048
- Incorrect roll number format
- Duplicate roll numbers

---

## Seating Constraints

Each bench can accommodate **3 students**.

For a classroom with 16 benches:

    16 × 3 = 48 students

Therefore, the maximum capacity is 48 students.

The program checks whether the selected room has enough seats before generating the seating arrangement.

---

## Seating Arrangement

The system separates students according to their departments and alternates their positions between benches.

### Example

Even-numbered benches:

    BCT | BEI | BCT

Odd-numbered benches:

    BEI | BCT | BEI

This helps distribute students from the two departments throughout the examination hall.

---

## Project Structure

The project follows a modular Object-Oriented Programming structure.

```text
Automated-Exam-Hall-Seating-Management-System/
│
├── main.cpp
│
├── Student.h
├── Student.cpp
│
├── Room.h
├── Room.cpp
│
├── Seat.h
├── Seat.cpp
│
├── Constraint.h
├── constraint.cpp
│
├── SeatingManager.h
├── SeatingManager.cpp
│
└── README.md