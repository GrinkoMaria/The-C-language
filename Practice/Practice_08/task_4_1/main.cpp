#include <iostream>
int readOr(const int* value, int fallback) {
    if (value == nullptr){
    return fallback;
    }
    return *value;
}
int main() { int x=42; std::cout << readOr(&x, -1) << "\n"; return 0;}
