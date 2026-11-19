#include <iostream>
#include <string>

int main()
{
    int count;
    if (!(std::cin >> count)) {
        std::cout << "Input error" << "\n";
        return 1;
    }
    
    if (count < 0 || count > 8) {
        std::cout << "Invalid count" << "\n";
        return 0;
    }
    
    int accepted = 0;
    double total = 0.0;
    
    for (int i = 0; i < count; ++i) {
        double amount;
        if (!(std::cin >> amount)) {
            std::cout << "Input error" << "\n";
            return 1;
    }
    
    if (amount <= 0 || amount > 5000) {
        continue;
    }
    
    accepted++;
    total+=amount;
    }
    
    std::cout << "Accepted: " << accepted << "\n";
    std::cout << "Total: " << total << "\n";
    return 0;
}
