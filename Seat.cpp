#include "Seat.h"
#include <iostream>

Seat::Seat()
{
    benchNo = 0;
    position = 0;
    student = nullptr;
}

Seat::Seat(int bench, int pos)
{
    benchNo = bench;
    position = pos;
    student = nullptr;
}

void Seat::assignStudent(Student* s)
{
    student = s;
}

bool Seat::isOccupied() const
{
    return student != nullptr;
}

int Seat::getBenchNo() const
{
    return benchNo;
}

int Seat::getPosition() const
{
    return position;
}

Student* Seat::getStudent() const
{
    return student;
}

void Seat::display() const
{
    if (student != nullptr)
    {
        std::cout << student->getRollNo();
    }
    else
    {
        std::cout << "EMPTY";
    }
}