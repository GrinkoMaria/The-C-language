#include <iostream>

int main() {
    int n{};
    std::cin >> n;

    int* data{new int[n]{}};
    int sum{};

    for (int i = 0; i < n; i++) {
        data[i] += i + 1;
        sum += data[i];
    }

    std::cout << sum << '\n';

    delete[] data;

    return 0;
}