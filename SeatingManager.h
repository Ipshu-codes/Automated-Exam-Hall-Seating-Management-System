#ifndef SEATINGMANAGER_H
#define SEATINGMANAGER_H
#include "Constraint.h"

#include <vector>
#include "Student.h"
#include "Seat.h"
#include "Room.h"

class SeatingManager
{
private:
    std::vector<Student> students;
    std::vector<Seat> seats;

    Room room;

    static const int STUDENTS_PER_BENCH = 3;

public:
    SeatingManager();

    void inputStudents();
    void inputRoom();

    bool checkCapacity() const;

    void generateSeating();

    void displaySeating() const;
};

#endif