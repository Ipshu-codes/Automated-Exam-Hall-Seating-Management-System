#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
private:
    std::string rollNo;
    std::string department;

public:
    Student();
    Student(std::string roll);

    std::string getRollNo() const;
    std::string getDepartment() const;

    void display() const;
};

#endif