#include <iostream>

int razbor_endl() {
    int n{ 21 };
    if (n > 22) {
        std::cout << "n > 22" << std::endl;
    }
    else {
        std::cout << "n <= 22" << std::endl;
    }
}

int examples()
{
    char reply{};
    int count{};
    double number{};
    double total{};
    do
    {
        std::cout << "Enter a number: ";
        std::cin >> number;
        total += number;
        ++count;
        std::cout << "Finish? (y/n): ";
        std::cin >> reply;
    } while (reply != 'y' && reply != 'Y');

    std::cout << "The average value is " << total / count << std::endl;
    return 0;
}

int cycle() {

    switch (x)
    {
    case 1:
        std::cout << "x = 1" << "\n";
        break;
    case 2:
        std::cout << "x = 2" << "\n";
        break;
    case 3:
        std::cout << "x = 3" << "\n";
        break;
    }
}

int portion() {
    const double serviceFee{ 20.0 };
    double portionPrice{};
    int portionCount{};

    std::cout << "Price and portions: ";
    std::cin >> portionPrice >> portionCount;
    double total{ portionPrice * portionCount + serviceFee };
    std::cout << "Total: " << total << " RUB\n";

    return 0;
}

int algebra() {
    bool ready{};

    std::cout << "Ready (0 or 1): ";
    std::cin >> ready;
    std::cout << "Ready: " << std::boolalpha << ready << "\n";

    return 0;
}

int message() {

    std::string name;
    std::string message{ "Hello NETANIT.COM" };
    // Или так
    std::string mssage2 = "Hello NETANIT.COM";
    std::string message3("Hello NETANIT.COM");

    std::cin >> name;
    std::cout << "Name: " << name << "\n";
}

int fullName() {

    std::string Full name;

    std::cout << "Full name: ";
    getline(std::cin >> std::ws, fullName);
    std::cout << "Name received: " << fullName << "\n";

    return 0;
}


