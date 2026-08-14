#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room
{
private:
    std::string roomNo;
    int numberOfBenches;
    int studentsPerBench;
    int capacity;

public:
    Room();
    Room(std::string no, int benches);

    void calculateCapacity();

    std::string getRoomNo() const;
    int getNumberOfBenches() const;
    int getStudentsPerBench() const;
    int getCapacity() const;

    void display() const;
};

#endif