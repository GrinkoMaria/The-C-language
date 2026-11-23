# Разбор практики: Работа с переменными и формирование отчётов

## Функция `lesson_one`

```cpp
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
```

Ожидаемый вывод (пример):

```
Name: Ivan
Group: IS-21
STUDENT PROFILE
Name: Ivan
Group: IS-21
Course: C++
Age: 16
Experience: 1.5 years
Ready: false
Lessons: 2
Completed before: 0
Completed after: 3
Saved completed: 0
```

Смысл функции:
Это учебная практика по созданию профиля студента. Смысл в том, чтобы показать разницу между объявлением переменных, их инициализацией и последующим изменением. Обрати внимание на переменную `save`: она сохраняет старое значение `counter` (ноль) до того, как `counter` изменится на 3. Это демонстрирует, что переменные хранят значения на момент присваивания. Также здесь показано, как работают константы (`lessons` нельзя изменить) и как `std::boolalpha` превращает 0/1 в `false`/`true` для удобного вывода. Функция полезна для закрепления понимания области видимости и жизненного цикла переменных.

Ошибка в коде: Дублируется директива `#include <iostream>` и `#include <string>` — они уже подключены в начале файла. Это не вызовет ошибки, но считается плохой практикой.

## Функция `lesson_two`

```cpp
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
```

Ожидаемый вывод (пример):

```
Customer: Anna
Dish: Pasta
CAFE ORDER
Customer: Anna
Dish: Pasta
Portion price: 145.5RUB
Portions: 3
Subtotal: 436.5RUB
Service fee: 20RUB
Total: 456.5RUB
Paid: false
```

Смысл функции:
Практика по вычислению стоимости заказа с фиксированным сервисным сбором. Здесь важно увидеть, как дробные числа (`double`) взаимодействуют с целыми (`int`) при умножении. Результат умножения 145.5 * 3 сохраняется в `double`, что позволяет избежать потери точности. Также показано, как константы (`Portion_price`, `fee`) защищают данные от случайного изменения. Функция учит аккуратно формировать отчет с итоговыми суммами и использовать `std::boolalpha` для статуса оплаты.

## Функция `lesson_three`

```cpp
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
```

Ожидаемый вывод (пример):

```
Participant: Oleg
Event: C++ Meetup
IT MEETUP TICKET
Organizer: IT Academy
Practicant: Oleg
Event: "C++ Meetup"
Ticket price: 200RUB
Tickets: 3
Service fee: 25RUB
Total: 625RUB
Issued before: 0
Confirmed before: false
Issued after: 3
Confirmed after: true
Saved issued: 0
```

Смысл функции:
Практика на закрепление работы с целочисленными вычислениями и изменением состояния переменных. Здесь показано, как сохранить старое значение (`saved_issued`) до изменения, чтобы потом вывести его для сравнения «до и после». Также демонстрируется, что `std::boolalpha` можно включать отдельной строкой, и он продолжает действовать на весь последующий вывод. Функция полезна для понимания того, как состояние программы меняется пошагово, и как важно фиксировать промежуточные значения для отчетности.

Ошибка в коде: Как и во второй функции, здесь нет ошибок, но лишние директивы `#include` в начале блока не нужны — они уже подключены в первой функции.