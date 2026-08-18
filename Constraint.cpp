#include "Constraint.h"
#include <cctype>
#include <string>

bool Constraint::isValidDepartment(const std::string& rollNo)
{
    if (rollNo.length() != 12)
    {
        return false;
    }

    std::string department = rollNo.substr(6, 3);

    return department == "BCT" || department == "BEI";
}

bool Constraint::isValidRollNumber(const std::string& rollNo)
{
    // Expected format:
    // THA082BCT027
    // THA082BEI027

    if (rollNo.length() != 12)
    {
        return false;
    }

    // Institute must be THA
    if (rollNo.substr(0, 3) != "THA")
    {
        return false;
    }

    // Batch must be 082
    if (rollNo.substr(3, 3) != "082")
    {
        return false;
    }

    // Department must be BCT or BEI
    if (!isValidDepartment(rollNo))
    {
        return false;
    }

    // Roll number must contain digits
    for (int i = 9; i < 12; i++)
    {
        if (!std::isdigit(rollNo[i]))
        {
            return false;
        }
    }

    // Convert last 3 digits to integer
    int rollNumber = std::stoi(rollNo.substr(9, 3));

    // Roll number must be between 001 and 048
    if (rollNumber < 1 || rollNumber > 48)
    {
        return false;
    }

    return true;
}