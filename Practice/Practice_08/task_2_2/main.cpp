#include <iostream>
constexpr int kCapacity = 8;
int remainingTickets(int reserved) {
    if (reserved < 0 || reserved > kCapacity){
        return -1;
        }
        return kCapacity - reserved;
}
int main() { std::cout << remainingTickets(3) << "\n"; return 0;}
