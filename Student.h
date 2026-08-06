#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    string department;
    int semester;
    char section;

public:
    Student();
    Student(int roll, string n, string dept, int sem, char sec);

    int getRollNo();
    string getName();
    string getDepartment();
    int getSemester();
    char getSection();

    void display();
};

