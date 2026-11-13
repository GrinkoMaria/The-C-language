#include <iostream>
#include <string>

void Task1() {
    const int limit = 3;
    int registered = 0;
    for (int request = 0; request < 5; ++request) {
        if (registered >= limit) {
            std::cout << "No places" << "\n";
        }
        else {
            registered++;
            std::cout << "Accepted: " << registered << "\n";
        }
    }
    std::cout << "Total: " << registered << "\n";
}

// Программа имитирует регистрацию участников на мероприятие с лимитом мест. Она делает пять
// запросов, принимает людей до достижения лимита и выводит итог.

void Task2() {
    std::string customer;
    int zone;
    double weight;
    bool urgent;

    std::cout << "Customer: ";
    std::getline(std::cin, customer);
    std::cout << "Zone weight urgent (0/1): ";
    if (!(std::cin >> zone >> weight >> urgent)) {
        std::cout << "Input error" << "\n";
        return;
    }

    if (!((zone >= 1 && zone <= 3) && (weight > 0 && weight <= 20))) {
        std::cout << "Invalid data" << "\n";
    }
    else {
        double base = (zone == 1) ? 100 : (zone == 2) ? 150 : 200;
        double standard = base + weight * 20;
        double total = urgent ? standard * 1.5 : standard;

        std::cout << "Customer: " << customer << "\n";
        std::cout << "Standard: " << standard << "\n";
        std::cout << "Urgent: " << std::boolalpha << urgent << "\n";
        std::cout << "Total: " << total << "\n";
    }
    std::cout << "Session finished" << "\n";
}

void Task3() {
    int count;
    std::cout << "Count: ";
    if (!(std::cin >> count)) {
        std::cout << "Input error" << "\n";
        return;
    }
    if (count < 0 || count > 10) {
        std::cout << "Invalid count" << "\n";
        return;
    }

    int validCount = 0;
    int lowCount = 0;
    double sum = 0;

    for (int i = 0; i < count; ++i) {
        double level;
        std::cout << "Level: ";
        if (!(std::cin >> level)) {
            std::cout << "Input error" << "\n";
            return;
        }

        if (level < 0 || level > 100) {
            std::cout << "Rejected" << "\n";
            continue;
        }
        std::cout << "Accepted" << "\n";
        validCount++;
        sum += level;
        if (level < 20) {
            lowCount++;
        }
    }

    std::cout << "Valid: " << validCount << "\n";
    std::cout << "Low: " << lowCount << "\n";
    std::cout << "Average: ";
    if (validCount > 0) {
        std::cout << (sum / validCount) << "\n";
    }
    else {
        std::cout << "n/a\n";
    }
    std::cout << "Needs charge: " << std::boolalpha << (lowCount > 0) << "\n";
}

int main() {
    int choice;
    std::cout << "Task (1, 2 or 3): ";
    std::cin >> choice;
    std::cin.ignore(10000, '\n');

    if (choice == 1) Task1();
    else if (choice == 2) Task2();
    else if (choice == 3) Task3();

    return 0;
}





