#include <iostream>
#include <string>

int sumMultiples(int limit, int step);

int main()
{
    int limit, step;
    if (std::cin >> limit >> step){
        std::cout << sumMultiples(limit, step) << "\n";
    }
    return 0;
}

int sumMultiples(int limit, int step)
{
    int sum = 0;
    
    for (int i = step; i <= limit; i += step) {
        sum += i;
    }
    
    return sum;
}
