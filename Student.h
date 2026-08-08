#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
private:
    int rollNo;
    std::string name;
    std::string department;
    int semester;
    char section;

public:
    Student();

    Student(int roll, std::string n, std::string dept,
            int sem, char sec);

    int getRollNo() const;
    std::string getName() const;
    std::string getDepartment() const;
    int getSemester() const;
    char getSection() const;

    void display() const;
};

#endif