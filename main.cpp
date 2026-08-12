#include "SeatingManager.h"
#include <iostream>

int main()
{
    SeatingManager manager;

    std::cout << "========================================\n";
    std::cout << "     SMART EXAM SEATING SYSTEM\n";
    std::cout << "========================================\n";

    manager.inputStudents();

    manager.inputRoom();

    if (!manager.checkCapacity())
    {
        std::cout << "\nERROR: Not enough seats!\n";
        return 0;
    }

    manager.generateSeating();

    manager.displaySeating();

    return 0;
}