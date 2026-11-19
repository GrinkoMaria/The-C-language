#include <iostream>
#include <string>

int fullBoxes(int items, int capacity);

int main()
{
    int items, capacity;
    
    if (std::cin >> items >> capacity) {
    std::cout << fullBoxes(items, capacity) << "\n";
    }
    
    
    return 0;
}

int fullBoxes(int items, int capacity)
{
    return items / capacity;
}
