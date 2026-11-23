#include <iostream>
enum class Result { Allowed, Denied };
namespace limits
{
    constexpr int minPercent{20};
    constexpr int maxPercent{100};
}
Result assess(int percent)
{
    if (percent < limits::minPercent || percent > limits::maxPercent)
        return Result::Denied;
    return Result::Allowed;
}
void showResult(Result result)
{
    if (result == Result::Allowed)
        std::cout << "Ready\n";
    else
        std::cout << "Wait\n";
}
int main()
{
    int percent{};
    if (!(std::cin >> percent)) return 1;
    showResult(assess(percent));
    return 0;
}
