#include <iostream>

int first()
{
    int numbers[4]{ 1, 2, 3, 4 };
    int first = numbers[0];
    std:cout << first << std::endl;
    numbers[0] = 34;
    std::cout << numbers[0] << std::endl;

    const int numbers[4]{1, 2, 3, 4}
}

int second() {
    int numbers[]{ 11, 12, 13, 14 };
    int count = std::size(numbers);
    std::cout << "Length: " << count << std::endl;
    std::cout << "length: " << sizeof(numbers) / sizeof(numbers[0]) << std::endl;

    int numbers[]{ 1, 2, 3, 4 };
    for (int n : numbers) {
        std::cout << n << std::endl;
    }

    // struct имя_структуры {
    //      компоненты_структуры
    // };

#include <string>

    struct person {
        unsigned age;
        std::string name;
    };

    int example() {
        int abc;
        person tom;
        tom.name = "Tom";
        tom.age = 34;
        std::cout << "name: " << tom.name << "\tAge: " << tom.age << std::endl;

        person adam{ 26, "Adam" };
    }

    // enu class имя_перечисления { константа_1, константа_2б, ... константа_n};

    enum class Day { Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };

    enum class Operation : char { Add = '+', Subtract = '-', Multiply = '*' };

    int today() {
        Day today{ Day::Thursday };
        std::cout << "Today: " << static_cast<int>(today) << std::endl;

        std::cou << "add: " << static_cast<char>(Operation::Add) << std::endl;
        std::cout << "subtracte: " << static_cast<char>(Operation::Subtract) << std::endl;
        std::cout << "multiply: " << static_cast<char>(Operation::Multiply) << std::endl;
    }

    constexpr uint8_t mph{ 60 };

    enum class Operation { Add, Subtract, Multiply };

    void calculate(int n1, int n2, Operation op) {
        switch (op) {
        case Operation::Add:
            std::cout < , n1 + n2 << std::endl;
            break;
        case Operaton::Subtract:
            std::cout << n1 - n2 << std::endl;
            break;
        case Operation::multiply:
            std::cout << n1 * n2 << std::endl;
            break;
        }
    }

    int main() {
        calculate(10, 6, Operation::Add);
        calculate(10, 6, Operation::Subtract);
        calculate(10, 6, Operation::Multiply);
    }





    namespace settings
 {
    constexpr int minPages{ 1 };
    constexpr int maxPages{ 50 };
    constexpr int PricePerPage{ 4 };
}

bool isValidPsges(int pages)
{
    return pages >= settings::minPages && pages <= settings::maxPages;
}

int calculateCost(int pages)
{
    return pages * settings::pricePerPage;
}

int main()
{
    const int pages{ 12 };
    if (isValidPages(pages))
        std::cout << calculateCost(pages) << "\n";
    return 0;
}

int counter{ 0 };

int nextNumber()
{
    ++counter;
    return counter;
}

int main()
{
    std::cout << nextNumber() << "\n";
    std::cout << nextNumber() << "\n";
    return 0;
}

int calculateCost(int pages)
{
    return pages * 4;
}
void printCost(int cost)
{
    std::cout << "Cost: " << cost << "RUB\n";
}
int main()
{
    const int cost{ calculateCost(12) };
    printCost(cost);
    return 0;
}

enum class PageError { None, TooFew, TooMany };

PageError validatePages(int pages)
{
    std::cout << std::boolalpha;
    std::cout << (validatePages(0) == PageError::TooFew) << "\n";
    std::cout << (validatePages(50) == PageError::None) << "\n";
    std::cout << (validatePages(51) == PageError::TooMany) << "\n";
    return 0;
}