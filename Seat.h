#ifndef SEAT_H
#define SEAT_H

#include "Student.h"

class Seat
{
private:
    int benchNo;
    int position;
    Student* student;

public:
    Seat();
    Seat(int bench, int pos);

    void assignStudent(Student* s);

    bool isOccupied() const;

    int getBenchNo() const;
    int getPosition() const;

    Student* getStudent() const;

    void display() const;
};

#endif