#include "Student.h"
#include <iostream>

Student::Student()
{
    rollNo = "";
    department = "";
}

Student::Student(std::string roll)
{
    rollNo = roll;

    if (roll.length() >= 9)
    {
        department = roll.substr(6, 3);
    }
    else
    {
        department = "UNKNOWN";
    }
}

std::string Student::getRollNo() const
{
    return rollNo;
}

std::string Student::getDepartment() const
{
    return department;
}

void Student::display() const
{
    std::cout << "Roll No: " << rollNo << std::endl;
    std::cout << "Department: " << department << std::endl;
}