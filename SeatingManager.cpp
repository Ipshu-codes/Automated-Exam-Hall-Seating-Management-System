#include "SeatingManager.h"
#include <iostream>

SeatingManager::SeatingManager()
{
    numberOfBenches = 0;
}

void SeatingManager::inputStudents()
{
    int numberOfStudents;

    std::cout << "Enter number of students: ";
    std::cin >> numberOfStudents;

    for (int i = 0; i < numberOfStudents; i++)
    {
        std::cin.ignore();
        std::string name;
        std::string rollNo;

        std::cout << "\nStudent " << i + 1 << std::endl;
         std::cout << "Enter name: ";
         std::getline(std::cin, name);

        std::cout << "Enter roll number: ";
        std::cin >> rollNo;

        students.push_back(Student(rollNo, name));
    }
}

void SeatingManager::inputRoom()
{
    std::cout << "\nEnter number of benches: ";
    std::cin >> numberOfBenches;
}

bool SeatingManager::checkCapacity() const
{
    int capacity = numberOfBenches * STUDENTS_PER_BENCH;

    if (students.size() > capacity)
    {
        return false;
    }

    return true;
}

void SeatingManager::generateSeating()
{
    seats.clear();

    // Create all seats
    for (int i = 0; i < numberOfBenches; i++)
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

    for (int i = 0; i < numberOfBenches; i++)
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