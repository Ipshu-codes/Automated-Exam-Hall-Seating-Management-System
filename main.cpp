#include <iostream>
#include "Student.h"

int main()
{
    Student s1("THA082BCT027", "Ipshu");
    Student s2("THA082BEI014", "Anisha");

    s1.display();

    std::cout << "------------------" << std::endl;

    s2.display();

    return 0;
}