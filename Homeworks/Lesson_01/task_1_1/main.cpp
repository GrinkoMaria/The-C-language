#include <iostream>
int rentalPrice(int hours, bool student) {
    constexpr int pricePerHour = 120;
    constexpr int maxHours = 24;
    constexpr int discount = 25;

    if (hours < 1 || hours > maxHours)
        return -1;

    if (student)
        return hours * pricePerHour * (100 - discount) / 100;

    return hours * pricePerHour;
}
int main() {
    int hours{}, student{};
    if (!(std::cin >> hours >> student)) return 1;
    std::cout << rentalPrice(hours, student != 0) << "\n";
    return 0;
}
