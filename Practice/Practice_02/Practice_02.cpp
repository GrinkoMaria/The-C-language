# include <iostream>
# include <string>

int Ex() {

	std::string name(" ");
	int ticket = 3;
	double price_one = 0.0;
	const double stavka = 0.10;
	int discount_input = 0;

	std::cout << "Name: ";
	std::getline(std::cin, name);

	std::cout << "Tickets price discount (0/1)";
	std::cin >> ticket >> price_one >> discount_input;

	if (ticket == 0 && discount_input == 0) {
		std::cout << "Input error" << std::endl;
	}

	else if (ticket < 1 || ticket > 10 || price_one < 5000 || (discount_input != 0 && discount_input != 1)) {
		std::cout << "Invalid data" << std::endl;
	}

	else {
		bool has_discount = (discount_input == 1);

		double base = price_one * ticket;

		double disc_sum = has_discount ? base * stavka : 0.0;
		double total = base - disc_sum;

		std::cout << "Customer: " << name << std::endl << "\n";
		std::cout << "Tickets: " << ticket << std::endl << "\n";
		std::cout << "Bace: " << base << std::endl << "\n";
		std::cout << "Discount applide: " << std::boolalpha << has_discount << std::endl << "\n";
		std::cout << "Discount: " << disc_sum << std::endl << "\n";
		std::cout << "Total: " << total << std::endl << "\n";



	}
	return 0;
}

int Ex_Two() {
	int count = 0;
	std::cout << "Count: ";
	std::cin >> count;

	if (count < 0 || count > 10) {
		std::cout << "Invalid count" << std::endl;
	}
	else {
		int accepted = 0, rejected = 0, working = 0;
		double sum = 0.0;

		for (int i = 0; i < count; i++) {
			int temp = 0;
			std::cout << "Value: ";
			std::cin >> temp;

			if (temp < -50 || temp > 100) {
				std::cout << "Rejected" << std::endl;
				rejected++;
				continue;
			}

			std::cout << "Assepted" << std::endl;
			accepted++;
			sum += temp;

			if (temp >= 0 && temp <= 40) {
				working++;

			}
		}
		std::cout << "Valid: " << accepted << ", Invalid: " << rejected << ", Working: " << working << std::endl;
		std::cout << "Average: " << (accepted > 0 ? std::to_string(sum / accepted) : "n/a") << std::endl;

	}
	return 0;
}



int Ex_Three() {

	int budget = 0, spent = 0, count = 0;
	const int limit = 100000;

	std::cout << "Budget: ";
	std::cin >> budget;

	if (budget < 0 || budget > limit) {
		std::cout << "Invalid budget" << std::endl << "\n";
	}
	else {
		for (int i = 0; i < 10; i++) {
			int price = 0;
			std::cout << "Price (0 stop): ";
			std::cin >> price;

			if (price == 0) {
				break;
			}

			if (price < 0 || price > limit) {
				std::cout << "Invalid price" << std::endl;
				continue;
			}
			if (price < 0 || price > limit) {
				std::cout << "Invalid price" << std::endl;
				continue;
			}

			if (price > budget - spent) {
				std::cout << "Added" << std::endl;
				spent += price;
				count++;
			}
			std::cout << "Items: " << count << std::endl << "\n";
			std::cout << " Spent: " << spent << std::endl << "\n";
			std::cout << "Remaining: " << budget - spent << std::endl << "\n";
		}
		return 0;
	}
}

