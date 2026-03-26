#include <iostream>
#include <string>

class Order
{
public:
    double price;
    int quantity;
    std::string side;
};

void printVector(const std::vector<Order> &order)
{
    for (int i = 0; i < order.size(); i++)
    {
        std::cout << "Data stored in orders[" << i << "]\n";
        std::cout << order[i].price << "\n"
                  << order[i].quantity << "\n"
                  << order[i].side << "\n";
        std::cout << "________________________\n";
    }
}

Order getUserInput()
{
    Order order;
    std::cout << "Enter Price: ";
    std::cin >> order.price;
    std::cout << "Enter quantity: ";
    std::cin >> order.quantity;
    std::cout << "Buy or Sell: ";
    std::cin >> order.side;

    return order;
}

int main()
{
    std::vector<Order> orders;
    orders.reserve(3);

    /* I will create a Order variable on stack and
    then push_back it to the vector orders
    */

    for (int i = 0; i < 3; i++)
    {
        orders.push_back(getUserInput());
    }

    // printing the memory addresses of the vector
    std::cout << "___________________________________________" << "\n";
    std::cout << "Address of orders is : " << &orders << "\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Address stored in orders vector: " << orders.data() << "\n";
        std::cout << "Address of orders[" << i << "]: " << &orders[i] << "\n";
        std::cout << "Capacity of the vector orders: " << orders.capacity() << "\n";
        std::cout << "Size of vector orders: " << orders.size() << "\n";
        std::cout << "___________________________________________" << "\n";
    }

    printVector(orders);
}