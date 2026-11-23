#include <iostream>
int finalPrice(int price, int discount) {
    if (price < 0 || discount < 0 || discount > 100){
        return -1;
    }
    return price * (100 - discount) / 100;
}
int main() { std::cout << finalPrice(800, 25) << "\n"; return 0;}
