#include "Room.h"
#include <iostream>

Room::Room()
{
    roomNo = "";
    rows = 0;
    cols = 0;
    capacity = 0;
}

Room::Room(std::string no, int r, int c)
{
    roomNo = no;
    rows = r;
    cols = c;
    capacity = r * c;
}

std::string Room::getRoomNo() const
{
    return roomNo;
}

int Room::getRows() const
{
    return rows;
}

int Room::getCols() const
{
    return cols;
}

int Room::getCapacity() const
{
    return capacity;
}

void Room::display() const
{
    std::cout << "Room No: " << roomNo << std::endl;
    std::cout << "Rows: " << rows << std::endl;
    std::cout << "Columns: " << cols << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
}