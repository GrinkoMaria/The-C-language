#include <iostream>
bool charge(int* wallet, int cost) {
    if (wallet == nullptr)
        return false;

    if (cost <= 0 || *wallet < 0 || *wallet < cost)
        return false;

    *wallet = *wallet - cost;

    return true;
}
int main() {
    int money{}, cost{}, absent{};
    if (!(std::cin >> money >> cost >> absent)) return 1;
    const bool ok = charge(absent ? nullptr : &money, cost);
    std::cout << ok << " " << money << "\n";
}
