#include <iostream>
int sumEven(int n) {
    int sum = 0;
    
    for (int i = 2; i <= n; i += 2){
        sum = sum + i;
    }
    
    return sum;
}
int main() { std::cout << sumEven(8) << "\n"; return 0;}
