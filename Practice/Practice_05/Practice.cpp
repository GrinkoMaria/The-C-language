#include <iostream>
#include <string>

struct Car {
    int id;
    std::string nomer;
    std::string marka;
    std::string model;
    int probeg;
    std::string dvigatel;
};

int main() {
    Car cars[10] = {};
    int count = 0;

    cars[0] = { 1, "A123BC", "Toyota", "Camry", 50000, "Bensin" };
    cars[1] = { 2, "B456DE", "Tesla", "Model 3", 15000, "Electro" };
    cars[2] = { 3, "C789FG", "Ford", "Focus", 80000, "Dizel" };
    cars[3] = { 4, "D012HI", "Kia", "Rio", 30000, "Bensin" };
    cars[4] = { 5, "E345JK", "BMW", "X5", 10000, "Bensin" };
    count = 5;

    int choice;

    while (true) {
        std::cout << "\n1. All the cars\n2. Find by ID\n3. Add\n0. Exit\nChoice: ";
        std::cin >> choice;

        if (choice == 0) {
            break;
        }

        if (choice == 1) {
            std::cout << "\n    Список    \n";
            for (int i = 0; i < count; i++) {
                std::cout << "ID: " << cars[i].id << "\n";
                std::cout << "Marka: " << cars[i].marka << "\n";
                std::cout << "Model: " << cars[i].model << "\n";
                std::cout << "Nomer: " << cars[i].nomer << "\n";
                std::cout << "Probeg: " << cars[i].probeg << "\n";
                std::cout << "Dvigatel: " << cars[i].dvigatel << "\n";
            }
        }
        else if (choice == 2) {
            int searchId;
            std::cout << "Enter ID: ";
            std::cin >> searchId;

            bool found = false;
            for (int i = 0; i < count; i++) {
                if (cars[i].id == searchId) {
                    std::cout << "Found: " << cars[i].marka << " " << cars[i].model << "\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "The car has not been found!\n";
            }
        }
        else if (choice == 3) {
            if (count >= 10) {
                std::cout << "There’s no room in the fleet.!\n";
            }
            else {
                std::cout << "Enter the nomer: ";
                std::cin >> cars[count].nomer;
                std::cout << "Enter the marka: ";
                std::cin >> cars[count].marka;
                std::cout << "Enter the model: ";
                std::cin >> cars[count].model;
                std::cout << "Enter the probeg: ";
                std::cin >> cars[count].probeg;
                std::cout << "Enter the dvigatel: ";
                std::cin >> cars[count].dvigatel;

                cars[count].id = count + 1;
                count = count + 1;
                std::cout << "The car has been added.\n";
            }
        }
    }

    return 0;
}