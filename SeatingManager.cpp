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

        while (true)
        {
            std::cout << "Enter roll number: ";
            std::cin >> rollNo;

            if (Constraint::isValidRollNumber(rollNo))
            {
                break;
            }

            std::cout << "Invalid roll number!\n";
            std::cout << "Please enter a valid BCT or BEI roll number.\n";
        }

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

    // Create seats for every bench
    for (int i = 0; i < room.getNumberOfBenches(); i++)
    {
        for (int j = 0; j < STUDENTS_PER_BENCH; j++)
        {
            seats.push_back(Seat(i + 1, j + 1));
        }
    }

    // Separate students by department
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

    int bctIndex = 0;
    int beiIndex = 0;

    // Arrange students bench by bench
    for (int bench = 0; bench < room.getNumberOfBenches(); bench++)
    {
        int baseIndex = bench * STUDENTS_PER_BENCH;

        // Even benches: BCT | BEI | BCT
        if (bench % 2 == 0)
        {
            if (bctIndex < bctStudents.size())
            {
                seats[baseIndex].assignStudent(bctStudents[bctIndex]);
                bctIndex++;
            }

            if (beiIndex < beiStudents.size())
            {
                seats[baseIndex + 1].assignStudent(beiStudents[beiIndex]);
                beiIndex++;
            }

            if (bctIndex < bctStudents.size())
            {
                seats[baseIndex + 2].assignStudent(bctStudents[bctIndex]);
                bctIndex++;
            }
        }

        // Odd benches: BEI | BCT | BEI
        else
        {
            if (beiIndex < beiStudents.size())
            {
                seats[baseIndex].assignStudent(beiStudents[beiIndex]);
                beiIndex++;
            }

            if (bctIndex < bctStudents.size())
            {
                seats[baseIndex + 1].assignStudent(bctStudents[bctIndex]);
                bctIndex++;
            }

            if (beiIndex < beiStudents.size())
            {
                seats[baseIndex + 2].assignStudent(beiStudents[beiIndex]);
                beiIndex++;
            }
        }
    }
}

void SeatingManager::displaySeating() const
{
    room.display();

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