#include "Room.h"
#include <iostream>

Room::Room()
{
    roomNo = "";
    numberOfBenches = 0;
    studentsPerBench = 3;
    capacity = 0;
}

Room::Room(std::string no, int benches)
{
    roomNo = no;
    numberOfBenches = benches;
    studentsPerBench = 3;

    calculateCapacity();
}

void Room::calculateCapacity()
{
    capacity = numberOfBenches * studentsPerBench;
}

std::string Room::getRoomNo() const
{
    return roomNo;
}

int Room::getNumberOfBenches() const
{
    return numberOfBenches;
}

int Room::getStudentsPerBench() const
{
    return studentsPerBench;
}

int Room::getCapacity() const
{
    return capacity;
}

void Room::display() const
{
    std::cout << "\nRoom Number      : " << roomNo << std::endl;
    std::cout << "Number of Benches: " << numberOfBenches << std::endl;
    std::cout << "Students/Bench   : " << studentsPerBench << std::endl;
    std::cout << "Total Capacity   : " << capacity << std::endl;
}