#include "SeatingManager.h"
#include <iostream>

SeatingManager::SeatingManager()
{
}

void SeatingManager::inputStudents()
{
    int numberOfStudents;

    std::cout << "Enter number of students: ";
    std::cin >> numberOfStudents;

    for (int i = 0; i < numberOfStudents; i++)
    {
        std::string rollNo;

        std::cout << "\nStudent " << i + 1 << std::endl;

        std::cout << "Enter roll number: ";
        std::cin >> rollNo;

        students.push_back(Student(rollNo));
    }
}
void SeatingManager::inputRoom()
{
    std::string roomNo;
    int numberOfBenches;

    std::cout << "\nEnter room number: ";
    std::cin >> roomNo;

    std::cout << "Enter number of benches: ";
    std::cin >> numberOfBenches;

    room = Room(roomNo, numberOfBenches);
}

bool SeatingManager::checkCapacity() const
{
    return students.size() <= room.getCapacity();
}

void SeatingManager::generateSeating()
{
    seats.clear();

    // Create all seats
   for (int i = 0; i < room.getNumberOfBenches(); i++)
    {
        for (int j = 0; j < STUDENTS_PER_BENCH; j++)
        {
            seats.push_back(Seat(i + 1, j + 1));
        }
    }

    // Separate students according to department
    std::vector<Student*> bctStudents;
    std::vector<Student*> beiStudents;

    for (Student& student : students)
    {
        if (student.getDepartment() == "BCT")
        {
            bctStudents.push_back(&student);
        }
        else if (student.getDepartment() == "BEI")
        {
            beiStudents.push_back(&student);
        }
    }

    // Create an alternating seating order
    std::vector<Student*> arrangedStudents;

    int bctIndex = 0;
    int beiIndex = 0;

    while (bctIndex < bctStudents.size() ||
           beiIndex < beiStudents.size())
    {
        // Add BCT student
        if (bctIndex < bctStudents.size())
        {
            arrangedStudents.push_back(bctStudents[bctIndex]);
            bctIndex++;
        }

        // Add BEI student
        if (beiIndex < beiStudents.size())
        {
            arrangedStudents.push_back(beiStudents[beiIndex]);
            beiIndex++;
        }
    }

    // Assign students to seats
    for (int i = 0; i < arrangedStudents.size(); i++)
    {
        seats[i].assignStudent(arrangedStudents[i]);
    }
}

void SeatingManager::displaySeating() const
{
    std::cout << "\n========================================\n";
    std::cout << "         EXAMINATION SEATING PLAN\n";
    std::cout << "========================================\n";
    for (int i = 0; i < room.getNumberOfBenches(); i++)
    {
        std::cout << "\nBench " << i + 1 << ": ";

        for (int j = 0; j < STUDENTS_PER_BENCH; j++)
        {
            int index = i * STUDENTS_PER_BENCH + j;

            std::cout << "[ ";

            seats[index].display();

            std::cout << " ] ";
        }
    }

    std::cout << "\n";
}