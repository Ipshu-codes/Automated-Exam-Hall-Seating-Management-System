#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include <string>

class Constraint
{
public:
    static bool isValidRollNumber(const std::string& rollNo);
    static bool isValidDepartment(const std::string& rollNo);
};

#endif