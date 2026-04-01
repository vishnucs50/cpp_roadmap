#include <iostream>
#include <string>

enum class SIDE
{
    Buy,
    Sell
};

// struct Orders
// {
//     double price;
//     int quantity;
//     SIDE side; // user can only buy or sell
// };

class Order
{
public:
    double price;
    int quantity;
    SIDE side;

    Order(double price, int quantity, SIDE side) : price(price), quantity(quantity), side(side) {}
};

void getOrder(std::vector<Order> &vec)
{
    std::string BuySell;
    double price;
    int quantity;
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cout << "Enter Quantity; ";
    std::cin >> quantity;
    std::cout << "Buy or Sell : ";
    std::cin >> BuySell;

    /*
    Defaulting everything to sell if input is not "buy"
    */
    SIDE side = (BuySell == "Buy" || BuySell == "buy" || BuySell == "BUY") ? SIDE::Buy : SIDE::Sell;

    vec.emplace_back(price, quantity, side);
}

void printVector(const std::vector<Order> &order)
{
    std::cout << "Vector location on the stack: " << &order << "\n";
    std::cout << "Heap location stored in the vector: " << order.data() << "\n";
    std::cout << "Size of the order array is : " << order.size() << "\n";
    std::cout << "Capactiy of the order array is: " << order.capacity() << "\n";
    std::cout << "_________________\n";

    for (int i = 0; i < order.size(); i++)
    {

        std::cout << "Heap address stored in vector : " << &order[i] << "\n";
        std::cout << "Value stored in order[" << i << "] are: \n";
        std::cout << order[i].price << "\n";
        std::cout << order[i].quantity << "\n";
        std::cout << (int)order[i].side << "\n"; // 0 for Buy and 1 for Sell
    }

    std::cout << "_________________\n";
}

int main()
{
    std::vector<Order> order;
    order.reserve(2);

    for (int i = 0; i < 2; i++)
    {
        getOrder(order);
    }
    std::cout << "Size of the class Order is: " << sizeof(Order) << "\n";
    printVector(order);
}