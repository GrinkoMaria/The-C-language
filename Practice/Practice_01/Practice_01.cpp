#include <iostream>
#include <string>

int lesson_one() {
	std::string name;
	std::string group;

	int age = 16;
	double experience = 1.5;
	bool ready = false;
	const int lessons = 2;
	int counter{};

	std::cout << "Name: ";
	std::getline(std::cin, name);
	std::cout << "Group: ";
	std::getline(std::cin, group);

	int save = counter;

	std::cout << "STUDENT PROFILE" << "\n";
	std::cout << "Name: " << name << "\n";
	std::cout << "Group: " << group << "\n";
	std::cout << "Course: C++" << "\n";
	std::cout << "Age: " << age << "\n";
	std::cout << "Experience: " << experience << " years\n";

	std::cout << "Ready: " << std::boolalpha << ready << "\n";

	std::cout << "Lessons: " << lessons << "\n";
	std::cout << "Completed before: " << counter << "\n";

	counter = 3;

	std::cout << "Completed after: " << counter << "\n";
	std::cout << "Saved completed: " << save << "\n";

	return 0;
}

#include <iostream>
#include <string>

int lesson_two() {
	std::string customer;
	std::string dish;
	int portions = 3;
	const double Portion_price = 145.5;
	const double fee = 20.0;
	bool paid = false;

	std::cout << "Customer: ";
	std::getline(std::cin, customer);
	std::cout << "Dish: ";
	std::getline(std::cin, dish);

	double subtotal = Portion_price * portions;
	double total = subtotal + fee;

	std::cout << "CAFE ORDER" << "\n";
	std::cout << "Customer: " << customer << "\n";
	std::cout << "Dish: " << dish << "\n";
	std::cout << "Portion price: " << Portion_price << "RUB" << "\n";
	std::cout << "Portions: " << portions << "\n";
	std::cout << "Subtotal: " << subtotal << "RUB" << "\n";
	std::cout << "Service fee: " << fee << "RUB" << "\n";
	std::cout << "Total: " << total << "RUB" << "\n";

	std::cout << "Paid: " << std::boolalpha << paid << "\n";

	return 0;
}

int lesson_three() {
		std::string practicant;
		std::string event;
		const int price = 200;
		int tickets = 3;
		const int fee = 25;
		int issued = 0;
		bool confirmed = false;

		std::cout << "Participant: ";
		std::getline(std::cin, practicant);
		std::cout << "Event: ";
		std::getline(std::cin, event);

		int total = (price * tickets) + fee;
		int saved_issued = issued;

		std::cout << "IT MEETUP TICKET" << "\n";
		std::cout << "Organizer: IT Academy\n";
		std::cout << "Practicant: " << practicant << "\n";
		std::cout << "Event: \"" << event << "\"\n";
		std::cout << "Ticket price: " << price << "RUB" << "\n";
		std::cout << "Tickets: " << tickets << "\n";
		std::cout << "Service fee: " << fee << "RUB" << "\n";
		std::cout << "Total: " << total << "RUB" << "\n";

		std::cout << "Issued before: " << issued << "\n";
		std::cout << std::boolalpha;
		std::cout << "Confirmed before: " << confirmed << "\n";

		issued = tickets;
		confirmed = true;

		std::cout << "Issued after: " << issued << "\n";
		std::cout << "Confirmed after: " << confirmed << "\n";
		std::cout << "Saved issued: " << saved_issued << "\n";

		return 0;
}