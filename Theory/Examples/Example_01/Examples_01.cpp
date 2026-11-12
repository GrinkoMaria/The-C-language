
#include <iostream>

int age(){
	int age{};
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "Age received: " << age << "\n";
    return 0;
}


int tasc() {
	const double serviceFee{ 20.0 };
	double portionPrice{};
	int portionCount{};

	std::cout << "Prise and portions: ";
	std::cin >> portionPrice >> portionCount;
	double total{ portionPrice * portionCount * serviceFee };
	std::cout << "Total: " << total << " RUB\n";

	return 0;
}


int discret() {
	bool ready{};

	std::cout << "Ready (0 or 1): ";
	std::cin >> ready;
	std::cout << "Ready: " << std::boolalpha << ready << "\n";

	return 0;
}

int thory_one() {
	std::string name;
	std::string message{ "Hello METANIT.COM!" };
	std::string message2 = "Hello METANIT.COM!";
	std::string message3("Hello METANIT.COM");

	std::cin >> name;
	std::cout << "Name: " << name << "\n";

	return 0;
}

#include <iostream>
#include <string>

int practic() {
	std::string name;
	std::string course;
	int First_block = 0;
	int Second_block = 0;
	int Break = 0;
	bool ready{};

	std::cout << "name: " << "\n";
	std::getline(std::cin >> std::ws, name);
	std::cout << "course: " << "\n";
	std::getline(std::cin >> std::ws, course);
	std::cout << "Firt_block: " << "\n";
	std::cin >> First_block;
	std::cout << "Second_block: " << "\n";
	std::cin >> Second_block;
	std::cout << "Break: " << "\n";
	std::cin >> Break;
	std::cout << "Ready (0 or 1): " << "\n";
	std::cin >> ready;


	int Total = (First_block + Second_block + Break);

	std::cout << "STUDI DAY";
	std::cout << "Name" << name << "\n";
	std::cout << "Course" << course << "\n";
	std::cout << "First block" << First_block << "min" << "\n";
	std::cout << "Second block" << Second_block << "min" << "\n";
	std::cout << "Break" << Break << "min" << "\n";
	std::cout << "Ready: " << std::boolalpha << ready << "\n";

	return 0;
}

int dicriment() {
	int a{ 8 };
	int b{ a-- };
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	return 0;
}

int calculator() {
	int num1;
	int num2;
	char operation;

	std::cout << "Первое число: ";
	std::cin >> num1;
	std::cout << "Второе число: ";
	std::cin >> num2;
	std::cout << "Операция: ";
	std::cin >> operation;

	if (operation == '+') {
		std::cout << "Результат: " << num1 + num2 << "\n";
	}
	else if (operation == '-') {
		std::cout << "Результат: " << num1 - num2 << "\n";
	}
	else if (operation == '*') {
		std::cout << "Результат: " << num1 * num2 << "\n";
	}
	else if (operation == '/') {
		if (num2 == 0) {
			std::cout << "Ошибка, потому что нельзя делить на 0" << "\n";
		}
		else {
			std::cout << "Результат: " << num1 / num2 << "\n";
		}
	else {
		std::cout << "Неизвестная операция" << "\n";
	}
	}