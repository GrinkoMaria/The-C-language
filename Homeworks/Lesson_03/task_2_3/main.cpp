#include <iostream>

int main() {
    int n{};
    std::cin >> n;

    int* first{new int{n}};
    int* second{first};

    std::cout << *second << '\n';

    delete first;
    first = nullptr;
    second = nullptr;

    return 0;
}
