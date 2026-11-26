#include <iostream>

int* createNumber(int value) {
    return new int{value};
}

int main() {
    int n{};
    std::cin >> n;
    int* p{createNumber(n)};
    std::cout << *p << '\n';
    delete p;
    return 0;
}
