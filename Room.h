#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room
{
private:
    std::string roomNo;
    int rows;
    int cols;
    int capacity;

public:
    Room();
    Room(std::string no, int r, int c);

    std::string getRoomNo() const;
    int getRows() const;
    int getCols() const;
    int getCapacity() const;

    void display() const;
};

#endif