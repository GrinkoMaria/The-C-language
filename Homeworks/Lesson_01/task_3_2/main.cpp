#include <iostream>
int balanceOr(const int* wallet) {
    if (wallet == nullptr) return -1;
    return *wallet;
}
int main() {
    int money{}, absent{};
    if (!(std::cin >> money >> absent)) return 1;
    std::cout << balanceOr(absent ? nullptr : &money) << "\n";
}
