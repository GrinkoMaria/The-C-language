#include <iostream>
void orderPair(int& first, int& second) {
    if (first > second) {
        int temp = first;
        first = second;
        second = temp;
    }    
}
int main() { int a=9, b=4; orderPair(a,b); std::cout << a << " " << b << "\n"; return 0;}
