#include <iostream>

int main()
{
    int arr[3] = {10, 20, 30};
    int *ptr = arr;

    std::cout << "(*ptr + 1):  " << *(ptr + 1) << "\n";
}