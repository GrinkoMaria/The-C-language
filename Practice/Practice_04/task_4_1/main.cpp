#include <iostream>
#include <string>

namespace rental
{
    bool validOrder(int item, int hours);
    double orderCost(int item, int hours, bool member);
}

int main()
{
    int item, hours;
    bool member;
    if (std::cin >> item >> hours >> member) {
    
        std::cout  << std::boolalpha << rental::validOrder(item, hours) << "\n";
        if (rental::validOrder(item, hours)) {
            std::cout << rental::orderCost(item, hours, member) << "\n";
        }
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
        
        if (item == 1) {
            rate = rate1;
        } else if (item ==  2) {
            rate = rate2;
        } else if (item == 3) {
            rate = rate3;
        }
        
        double total = rate * hours;
        
        if (member) {
            total = total * discount;
        }
        return total;
    }
}
