#include "Constraint.h"
#include <cctype>

bool Constraint::isValidDepartment(const std::string& rollNo)
{
    if (rollNo.length() < 9)
    {
        return false;
    }

    std::string department = rollNo.substr(6, 3);

    return department == "BCT" || department == "BEI";
}

bool Constraint::isValidRollNumber(const std::string& rollNo)
{
    // Expected format: THA082BCT027
    // Total length = 12

    if (rollNo.length() != 12)
    {
        return false;
    }

    // Institute
    if (rollNo.substr(0, 3) != "THA")
    {
        return false;
    }

    // Batch must be three digits
    for (int i = 3; i < 6; i++)
    {
        if (!std::isdigit(rollNo[i]))
        {
            return false;
        }
    }

    // Department
    if (!isValidDepartment(rollNo))
    {
        return false;
    }

    // Roll number must be three digits
    for (int i = 9; i < 12; i++)
    {
        if (!std::isdigit(rollNo[i]))
        {
            return false;
        }
    }

    return true;
}