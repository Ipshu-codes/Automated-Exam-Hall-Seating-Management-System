#ifndef SEATINGMANAGER_H
#define SEATINGMANAGER_H

#include <vector>
#include "Student.h"
#include "Room.h"

using namespace std;

class SeatingManager
{
private:
    vector<Student> students;
    vector<Room> rooms;

public:
    void loadStudents();
    void loadRooms();

    void generateSeating();

    void displaySeating();
};

