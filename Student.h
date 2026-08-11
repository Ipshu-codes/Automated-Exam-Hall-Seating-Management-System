#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
private:
    std::string rollNo;
    std::string name;
    std::string department;

public:
    Student();
    Student(std::string roll, std::string n);

    std::string getRollNo() const;
    std::string getName() const;
    std::string getDepartment() const;

    void display() const;
};

#endif