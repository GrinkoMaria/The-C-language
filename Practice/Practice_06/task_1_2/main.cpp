#include <iostream>
enum class Route : int { Local = 1, Express = 3, Pickup = 7 };
bool isKnownRoute(int code)
{
    if (code == 1 || code == 3 || code == 7){
        return true;
    }
    return false;
}
Route routeFromCode(int code)
{
    return static_cast<Route>(code);
}
int main()
{
    int code{};
    if (!(std::cin >> code))
    {
        std::cout << "Input error\n";
        return 1;
    }
    if (!isKnownRoute(code))
    {
        std::cout << "Unknown route\n";
        return 2;
    }
    const Route route{routeFromCode(code)};
    std::cout << "Accepted: " << static_cast<int>(route) << "\n";
    return 0;
}
