#include <iostream>

int main()
{
    int a = 50;
    int &ref = a;

    std::cout << "value of a: " << a << "\n";
    std::cout << "value stored in val: " << ref << "\n";

    ref = 32;

    std::cout << "value of a: " << a << "\n";
    std::cout << "value stored in val: " << ref << "\n";
}