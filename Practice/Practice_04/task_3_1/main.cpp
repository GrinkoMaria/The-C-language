#include <iostream>
namespace hall
{
    bool isPossible(int inside, int capacity);
    int advance(int inside);
}
int main()
{
    int inside{};
    const int capacity{2};
    for (int attempt{}; attempt < 4; ++attempt)
    {
        if (!hall::isPossible(inside, capacity))
        {
            std::cout << "Rejected\n";
            continue;
        }
        inside = hall::advance(inside);
        std::cout << "Accepted\n";
    }
    std::cout << "Inside: " << inside << "\n";
    return 0;
}
namespace hall
{
    bool isPossible(int inside, int capacity) { return inside < capacity; }
    int advance(int inside) { return inside + 1; }
}
