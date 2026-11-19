#include <iostream>
namespace audit
{
    int advance(int count);
    void showState(int count);
}
int main()
{
    int count{};
    if (!(std::cin >> count)) { std::cout << "Input error\n"; return 1; }
    if (count >= 0) { count = audit::advance(count); }
    audit::showState(count);
    std::cout << "Done\n";
    return 0;
}

namespace audit
{
    int advance(int count)
    {
       return count + 1;
    }
    void showState(int count)
    {
        if (count < 0)
        {
            std::cout << "Invalid\n";
            return;
        }
        std::cout << "Count: " << count << "\n";
    }
}
