#include "Student.h"
#include <iostream>

Student::Student()
{
    rollNo = 0;
    name = "";
    department = "";
    semester = 0;
    section = 'A';
}

Student::Student(int roll, std::string n, std::string dept,
                 int sem, char sec)
{
    rollNo = roll;
    name = n;
    department = dept;
    semester = sem;
    section = sec;
}

int Student::getRollNo() const
{
    return rollNo;
}

std::string Student::getName() const
{
    return name;
}

std::string Student::getDepartment() const
{
    return department;
}

int Student::getSemester() const
{
    return semester;
}

char Student::getSection() const
{
    return section;
}

void Student::display() const
{
    std::cout << "Roll No: " << rollNo << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Department: " << department << std::endl;
    std::cout << "Semester: " << semester << std::endl;
    std::cout << "Section: " << section << std::endl;
}