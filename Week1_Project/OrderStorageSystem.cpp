#include <iostream>
#include <string>

enum class SIDE
{
    Buy,
    Sell
};

class Order
{
public:
    double price;
    int quantity;
    SIDE side;

    // adding a default constructor to make things easy
    Order() = default;
    // adding constructor
    Order(double price, int quantity, SIDE side) : price(price), quantity(quantity), side(side) {}

    /*Add copy constructor to veryify copies*/
    Order(const Order &other) // Note takes a const reference
        : price(other.price), quantity(other.quantity), side(other.side)
    {
        std::cout << "Copy constructor called \n\n";
    }
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
        // std::cout << (int)order[i].side << "\n"; // 0 for Buy and 1 for Sell

        if (order[i].side == SIDE::Buy)
        {
            std::cout << "Buy" << "\n";
        }
        else
        {
            std::cout << "Sell" << "\n";
        }
    }

    std::cout << "_________________\n";
}

// check if this calls the copy constructor as it is returning an Order class object
Order getOrder2()
{
    // this works because default constructor exisits.
    Order newOrder;
    std::string buySell;

    std::cout << "Enter price: ";
    std::cin >> newOrder.price;
    std::cout << "Enter Quantity; ";
    std::cin >> newOrder.quantity;
    std::cout << "Buy or Sell? ";
    std::cin >> buySell;

    SIDE side = (buySell == "Buy" || buySell == "buy" || buySell == "BUY") ? SIDE::Buy : SIDE::Sell;

    newOrder.side = side;
    return newOrder;
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
    std::cout << "++++++ Finished running vector using emplace_back ++++++\n";
    /*
    1. create a new vector of type Order
    2. Create a new function that would return Order class object
    3. Push back returned order class object into the vector
    4. How many times is the copy constructor called? */

    std::vector<Order> newOrder;
    newOrder.reserve(2);

    for (int i = 0; i < 2; i++)
    {
        newOrder.push_back(getOrder2());
    }

    printVector(newOrder);
}