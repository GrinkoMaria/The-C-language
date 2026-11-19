#include <iostream>
#include <string>

namespace rental
{
    bool validOrder(int item, int hours);
    double orderCost(int item, int hours, bool member);
    void printReceipt(int item, int hours, bool member);
}

namespace report
{
    void printValue(int value);
    void printValue(double value);
    void printValue(bool value);
}

int main()
{
    std::string customer;
    std::getline(std::cin, customer);
    std::cout << "Customer: " << customer << "\n";

    int orders = 0;
    double revenue = 0.0;
    int command;

    while (std::cin >> command) {
        if (command == 1) {
            int item, hours;
            bool member;
            if (!(std::cin >> item >> hours >> member)) {
                std::cout << "Input error\n";
                return 1;
            }

            if (rental::validOrder(item, hours)) {
                rental::printReceipt(item, hours, member);
                orders++;
                revenue += rental::orderCost(item, hours, member);
            } else {
                std::cout << "Invalid order\n";
            }

        } else if (command == 0) {
            std::cout << "Orders: ";
            report::printValue(orders);
            std::cout << "Revenue: ";
            report::printValue(revenue);
            break; 
        } else {
            std::cout << "Unknown command\n";
        }
    }

    if (std::cin.fail() && !std::cin.eof()) {
        std::cout << "Input error\n";
        return 1;
    }

    return 0;
}

namespace rental
{
    bool validOrder(int item, int hours)
    {
        return (item >= 1 && item <= 3) && (hours >= 1 && hours <= 12);
    }

    double orderCost(int item, int hours, bool member)
    {
        const double rate1 = 100.0;
        const double rate2 = 150.0;
        const double rate3 = 250.0;
        const double discount = 0.9;

        double rate = 0.0;
        if (item == 1) rate = rate1;
        else if (item == 2) rate = rate2;
        else if (item == 3) rate = rate3;

        double total = rate * hours;
        if (member) {
            total = total * discount;
        }
        return total;
    }

    void printReceipt(int item, int hours, bool member)
    {
        if (!validOrder(item, hours)) {
            std::cout << "Invalid order\n";
            return;
        }

        double cost = orderCost(item, hours, member);
        
        std::cout << "Cost: ";
        report::printValue(cost);
        
        std::cout << "Member: ";
        report::printValue(member);
    }
}

namespace report
{
    void printValue(int value) {
        std::cout << value << "\n";
    }
    
    void printValue(double value) {
        std::cout << value << "\n";
    }
    
    void printValue(bool value) {
        std::cout << std::boolalpha << value << "\n";
    }
}