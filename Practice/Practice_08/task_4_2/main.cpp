#include <iostream>
bool addIfExists(int* value, int delta) {
    if (value == nullptr){
    return false;
    }
    *value = *value + delta;
    return true;
}
int main() { int x=10; bool ok=addIfExists(&x,5); std::cout << ok << " " << x << "\n"; return 0; }
