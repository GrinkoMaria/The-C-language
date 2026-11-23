#include <iostream>
using Minutes = int;
using Cost = int;
namespace config
{
    constexpr int minMinutes = 15;
    constexpr int maxMinutes = 120;
    constexpr int pricePerMinute = 3;
}
bool validDuration(Minutes duration)
{
    return duration >= config::minMinutes && duration <= config::maxMinutes;
}
Cost computeCost(Minutes duration)
{
    return duration * config::pricePerMinute;
}
int main()
{
    Minutes duration{};
    if (!(std::cin >> duration)) return 1;
    if (!validDuration(duration))
    {
        std::cout << "Invalid duration\n";
        return 0;
    }
    std::cout << "Cost: " << computeCost(duration) << "\n";
    return 0;
}
