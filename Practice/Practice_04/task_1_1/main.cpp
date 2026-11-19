#include <iostream>
#include <string>

int main()
{
    std::string customer{};
    int count{};
    double price{};
    
    std::getline(std::cin, customer);
    
    if (std::cin >> count >> price)
 {
 if (count < 0 || count > 100 || price <= 0 || price > 5000) {
 std::cout << "Invalid data" << "\n";
 return 0;
 }
 double total = count * price;
 std::cout << "Customer: " << customer << "\n";
 std::cout << "Total: " << total << "\n";
 } else {
 std::cout << "Input error" << "\n";
 return 1;
 }
    return 0;
}
