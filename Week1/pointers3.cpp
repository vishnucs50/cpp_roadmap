#include <iostream>

int main()
{
    int a = 50;
    int *ptr = &a;
    int *ref = ptr;

    std::cout << "Address of a: " << &a << "\n";
    std::cout << "Print just ptr gives us: " << ptr << "\n";
    std::cout << "printing &ptr gives us: " << &ptr << "\n";
    std::cout << "printing ref gives us: " << ref << "\n";
    std::cout << "printing &ref gives us: " << &ref << "\n";
}