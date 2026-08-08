#ifndef SEAT_H
#define SEAT_H

#include "Student.h"

class Seat
{
private:
    int row;
    int col;
    bool occupied;
    Student* student;

public:
    Seat();

    void assignStudent(Student* s);

    bool isOccupied();

    void display();
};

#endif