#include <iostream>
int priceFor(int sessions, bool discounted) {
    constexpr int price = 150;
    constexpr int discount = 20;

    if (sessions < 1 || sessions > 12) return -1;

    if (discounted)
        return sessions * price * (100 - discount) / 100;

    return sessions * price;
}
bool finishSale(int sessions, bool discounted, int* wallet, int& receipt) {
    if (wallet == nullptr) return false;

    int price = priceFor(sessions, discounted);

    if (price < 0 || *wallet < 0 || *wallet < price)
        return false;

    *wallet -= price;
    receipt = price;

    return true;
}
int main() {
    int sessions{}, student{}, money{}, absent{};
    if (!(std::cin >> sessions >> student >> money >> absent)) return 1;
    int receipt = -99;
    bool ok = finishSale(sessions,student!=0,absent ? nullptr : &money,receipt);
    std::cout << ok << " " << money << " " << receipt << " "
              << priceFor(sessions,student!=0) << "\n";
}
