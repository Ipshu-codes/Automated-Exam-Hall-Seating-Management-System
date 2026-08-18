#include "SeatingManager.h"
#include <iostream>
#include <algorithm>

SeatingManager::SeatingManager()
{
}

void SeatingManager::inputStudents()
{
    int numberOfStudents;

    std::cout << "Enter number of students: ";
    std::cin >> numberOfStudents;

    if (numberOfStudents < 1 || numberOfStudents > 48)
    {
        std::cout << "\nInvalid number of students!\n";
        std::cout << "You can enter between 1 and 48 students.\n";
        return;
    }

    for (int i = 0; i < numberOfStudents; i++)
    {
        std::string rollNo;

        std::cout << "\nStudent " << i + 1 << std::endl;

        while (true)
        {
            std::cout << "Enter roll number: ";
            std::cin >> rollNo;

            // STEP 1: Validate roll number
            if (!Constraint::isValidRollNumber(rollNo))
            {
                std::cout << "\nInvalid roll number!\n";
                std::cout << "Valid format:\n";
                std::cout << "THA082BCT001 - THA082BCT048\n";
                std::cout << "THA082BEI001 - THA082BEI048\n";
                continue;
            }

            // STEP 2: Check for duplicate
            bool duplicate = false;

            for (const Student& student : students)
            {
                std::cout << "Checking: " << student.getRollNo()
                          << " against " << rollNo << std::endl;

                if (student.getRollNo() == rollNo)
                {
                    duplicate = true;
                    break;
                }
            }

            // STEP 3: Reject duplicate
            if (duplicate)
            {
                std::cout << "\nERROR: Duplicate roll number!\n";
                std::cout << "This roll number has already been entered.\n";
                continue;
            }

            // STEP 4: Only add after all checks pass
            students.push_back(Student(rollNo));

            std::cout << "Roll number accepted!\n";

            break;
        }
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
    std::cout << "\n\n";
    std::cout << "========================================================\n";
    std::cout << "              EXAMINATION SEATING PLAN\n";
    std::cout << "                    ROOM "
              << room.getRoomNo() << "\n";
    std::cout << "========================================================\n";

    std::cout << "\n                    FRONT / BOARD\n";
    std::cout << "                         ^\n\n";

    // Top border
    std::cout << "          +--------------+--------------+--------------+\n";

    for (int i = 0; i < room.getNumberOfBenches(); i++)
    {
        std::cout << "Bench " << i + 1 << "   |";

        for (int j = 0; j < STUDENTS_PER_BENCH; j++)
        {
            int index = i * STUDENTS_PER_BENCH + j;

            std::cout << " ";

            if (seats[index].isOccupied())
            {
                Student* student = seats[index].getStudent();

                std::cout << student->getRollNo();

                // Padding so every cell has equal width
                int padding = 12 - student->getRollNo().length();

                for (int k = 0; k < padding; k++)
                {
                    std::cout << " ";
                }
            }
            else
            {
                std::cout << "EMPTY       ";
            }

            std::cout << " |";
        }

        std::cout << "\n";

        if (i < room.getNumberOfBenches() - 1)
        {
            std::cout << "          +--------------+--------------+--------------+\n";
        }
    }

    std::cout << "          +--------------+--------------+--------------+\n";

    std::cout << "\n              Seat 1        Seat 2        Seat 3\n";

    std::cout << "\n========================================================\n";
    std::cout << "Students per bench: "
              << room.getStudentsPerBench() << "\n";
    std::cout << "Total capacity    : "
              << room.getCapacity() << "\n";
    std::cout << "========================================================\n";
}