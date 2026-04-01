#include <iostream>

struct some_struct
{
    float a, b, c;
    some_struct() : a(1), b(2), c(3) {}
};

int main()
{
    int a = 5;            // this is stack
    int *ptr = new int(); // this is heap

    int arr[5] = {1, 2, 3, 4, 5}; // stack
    int *harr = new int(5);       // heap

    some_struct sarray;                      // stack
    some_struct *harray = new some_struct(); // heap
}