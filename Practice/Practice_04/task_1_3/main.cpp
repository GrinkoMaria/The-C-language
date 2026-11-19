#include <iostream>
#include <string>

double waterCost(double liters, double rate);

int main()
{
    double l, r;
    if (std::cin >> l >> r) {
    std::cout << waterCost(l, r) << "\n";
    }
    return 0;
}

double waterCost(double liters, double rate)
{
    return (liters / 1000.0) * rate;
}
