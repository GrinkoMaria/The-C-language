#include <iostream>

int calculateStandardFee(int weightKg)
{
    if (weightKg < 1 || weightKg > 20)
        return -1;
    return 200 + weightKg * 30;
}

int calculateExpressFee(int weightKg)
{
    // Правило лимита скопировано вручную и позже изменилось только здесь
    if (weightKg < 1 || weightKg > 15)
        return -1;
    return 400 + weightKg * 50;
}

int main()
{
    const int weight{ 18 };
    std::cout << "Standard: " << calculateStandardFee(weight) << "\n";
    std::cout << "Express: " << calculateExpressFee(weight) << "\n";
    return 0;
}


#include <iostream>

using Kilograms = int;
using Rubles = int;

namespace parcelLimits
{
    constexpr Kilograms minWeight{ 1 };
    constexpr Kilograms maxWeight{ 20 };
    constexpr Rubles invalidFee{ -1 };
}

bool isValidWeight(Kilograms weight)
{
    return weight >= parcelLimits::minWeight
        && weight <= parcelLimits::maxWeight;
}

Rubles calculateStandardFee(Kilograms weight)
{
    if (!isValidWeight(weight))
        return parcelLimits::invalidFee;
    return 200 + weight * 30;
}

Rubles calculateExpressFee(Kilograms weight)
{
    if (!isValidWeight(weight))
        return parcelLimits::invalidFee;
    return 400 + weight * 50;
}

int main()
{
    const Kilograms weight{ 18 };
    std::cout << "Standard: " << calculateStandardFee(weight) << "\n";
    std::cout << "Express: " << calculateExpressFee(weight) << "\n";
    return 0;
}

#include <iostream>

int g_bonusPoints{ 100 };

int applyDiscount(int price)
{
    if (g_bonusPoints >= 100)
    {
        g_bonusPoints -= 50;
        return price - 100;
    }
    return price;
}

int main()
{
    std::cout << applyDiscount(1000) << "\n";
    std::cout << applyDiscount(1000) << "\n";
    return 0;
}

#include <iostream>

using Rubles = int;
using BonusPoints = int;

namespace loyalty
{
    constexpr BonusPoints minPointsForDiscount{ 100 };
    constexpr BonusPoints pointsSpent{ 50 };
    constexpr Rubles discountAmount{ 100 };
}

bool canApplyDiscount(BonusPoints points)
{
    return points >= loyalty::minPointsForDiscount;
}

Rubles applyDiscount(Rubles price, BonusPoints points)
{
    if (canApplyDiscount(points))
        return price - loyalty::discountAmount;
    return price;
}

BonusPoints remainingPoints(BonusPoints points)
{
    if (canApplyDiscount(points))
        return points - loyalty::pointsSpent;
    return points;
}

int main()
{
    BonusPoints points{ 100 };
    std::cout << applyDiscount(1000, points) << "\n";
    points = remainingPoints(points);
    std::cout << applyDiscount(1000, points) << "\n";
    return 0;
}

#include <iostream>

enum class Command : int { Exit = 0, ShowStatus = 1, Start = 2, Stop = 3 };
enum class Status { Stopped, Running };

Status executeCommand(Command command, Status status)
{
    if (command == Command::Start)
        return Status::Running;
    return status;
}

int main()
{
    const Command cmd{ Command::Start };
    const Status st{ Status::Stopped };
    // Намеренная ошибка компиляции: аргументы перепутаны местами
    const Status next{ executeCommand(st, cmd) };
    std::cout << (next == Status::Running) << "\n";
    return 0;
}

#include <iostream>

int storageFee(int hours)
{
    if (hours <= 0 || hours > 24)
        return -1;
    if (hours <= 2)
        return 100;
    return 100 + (hours - 2) * 40;
}

int checkFee(int hours, int expected)
{
    const int actual{ storageFee(hours) };
    if (actual != expected)
    {
        std::cout << "FAIL hours=" << hours
                  << " expected=" << expected
                  << " actual=" << actual << "\n";
        return 1;
    }
    return 0;
}

int main()
{
    int failed{ 0 };
    failed += checkFee(0, -1);
    failed += checkFee(1, 100);
    failed += checkFee(2, 100);
    failed += checkFee(3, 140);
    failed += checkFee(24, 980);
    failed += checkFee(25, -1);

    if (failed == 0)
        std::cout << "ALL TESTS PASSED\n";
    return failed;
}

#include <iostream>

int storageFee(int hours)
{
    if (hours <= 0 || hours > 24)
        return -1;
    if (hours <= 2)
        return 100;
    return 100 + (hours - 2) * 40;
}

int checkFee(int hours, int expected)
{
    const int actual{ storageFee(hours) };
    if (actual != expected)
    {
        std::cout << "FAIL hours=" << hours
                  << " expected=" << expected
                  << " actual=" << actual << "\n";
        return 1;
    }
    return 0;
}

int main()
{
    int failed{ 0 };
    failed += checkFee(0, -1);
    failed += checkFee(1, 100);
    failed += checkFee(2, 100);
    failed += checkFee(3, 140);
    failed += checkFee(24, 980);
    failed += checkFee(25, -1);

    if (failed == 0)
        std::cout << "ALL TESTS PASSED\n";
    return failed;
}
