#include <iostream>

int main()
{
    int a = 50;
    int *p = &a;

    std::cout << "Value of a here: " << a << "\n";
    std::cout << "Value of p here: " << *p << "\n";

    *p = 23;
    std::cout << "Value of a here: " << a << "\n";
    std::cout << "Value of p here: " << *p << "\n";
}