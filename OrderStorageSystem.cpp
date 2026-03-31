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

    Order getUserInput()
    {
        Order order;
        std::string userInput;
        std::cout << "Enter price: ";
        std::cin >> order.price;
        std::cout << "Enter quantity: ";
        std::cin >> order.quantity;
        std::cout << "Buy or Sell: ";
        std::cin >> userInput;

        if (userInput == "Buy" || userInput == "BUY" || userInput == "buy")
        {
            order.side = SIDE ::Buy;
        }
        else if (userInput == "SELL" || userInput == "sell" || userInput == "Sell")
        {
            /* code */
            order.side = SIDE::Sell;
        }
        else
        {
            std::cout << "Unexpected input. Defaulting side to SELL\n";
            order.side = SIDE::Sell;
        }

        return order;
    }

    void printVector(const std::vector<Order> &order)
    {
        for (int i = 0; i < order.size(); i++)
        {
            std::cout << "________Data Stored in the order vector___________" << "\n";
            std::cout << order[i].price << "\n";
            std::cout << order[i].quantity << "\n";

            if (order[i].side == SIDE::Buy)
            {
                std::cout << "Buy\n";
            }
            else
            {
                std::cout << "Sell\n";
            }
        }
    }
};

// void printVector(const std::vector<Order> &order)
// {
//     for (int i = 0; i < order.size(); i++)
//     {
//         std::cout << "Data stored in orders[" << i << "]\n";
//         std::cout << order[i].price << "\n"
//                   << order[i].quantity << "\n"
//                   << order[i].side << "\n";
//         std::cout << "________________________\n";
//     }
// }

// Order getUserInput()
// {
//     Order order;
//     std::cout << "Enter Price: ";
//     std::cin >> order.price;
//     std::cout << "Enter quantity: ";
//     std::cin >> order.quantity;
//     std::cout << "Buy or Sell: ";
//     std::cin >> order.side;

//     return order;
// }

int main()
{
    std::vector<Order> orders;
    orders.reserve(3);

    Order newOrder;

    /* I will create a Order variable on stack and
    then push_back it to the vector orders
    */

    for (int i = 0; i < 3; i++)
    {
        orders.emplace_back(newOrder.getUserInput());
    }

    // printing the memory addresses of the vector
    std::cout << "___________________________________________" << "\n";
    std::cout << "Address of orders is : " << &orders << "\n";
    std::cout << "Address stored in orders vector on the heap: " << orders.data() << "\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Address of orders[" << i << "]: " << &orders[i] << "\n";
        std::cout << "___________________________________________" << "\n";
    }

    newOrder.printVector(orders);
}