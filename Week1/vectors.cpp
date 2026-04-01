#include <iostream>

int main()
{
    std::vector<int> n;
    for (int i = 0; i < 10; i++)
    {
        n.push_back(i + 1);

        std::cout << "Size of vector: " << n.size() << "\n";
        std::cout << "Capaticy of vector: " << n.capacity() << "\n";
        std::cout << "Address of vector: " << n.data() << "\n";
    }
}