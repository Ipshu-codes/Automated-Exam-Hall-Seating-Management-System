#ifndef ROOM_H
#define ROOM_H

#include <string>

using namespace std;

class Room
{
private:
    string roomNo;
    int rows;
    int cols;
    int capacity;

public:
    Room();
    Room(string no, int r, int c);

    void display();
};
#endif

