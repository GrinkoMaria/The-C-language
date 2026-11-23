# Разбор кода: Условные конструкции, циклы и обработка ошибок

## Функция `Ex`

```cpp
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
```

Ожидаемый вывод (пример с корректными данными):

```
Name: Ivan
Tickets price discount (0/1)2 6000 1
Customer: Ivan

Tickets: 2

Bace: 12000

Discount applide: true

Discount: 1200

Total: 10800
```

Смысл функции:
Практика на построение сложных логических условий. Сначала мы проверяем на «вводную ошибку» (когда оба значения нулевые), затем проверяем диапазоны (количество билетов от 1 до 10, цена от 5000, флаг скидки строго 0 или 1). Если все проверки пройдены, вычисляется базовая сумма, размер скидки (с использованием тернарного оператора) и итоговая стоимость. Это учит защитному программированию: программа не падает и не считает мусор, а вежливо сообщает пользователю о неверных данных.

Ошибка в коде: Оператор `std::getline` прочитает пустую строку, если перед ним в потоке остался символ новой строки от предыдущих вводов. Но так как это первый ввод в функции, проблемы нет. Обрати внимание на переменную `ticket` — она инициализирована значением 3, но сразу перезаписывается при вводе. В строке `std::cout << "Tickets price discount (0/1)";` нет переноса строки, поэтому ввод пользователя начнется сразу после текста. Кроме того, в выводе опечатки: "Bace" вместо "Base", "applide" вместо "applied".

## Функция `Ex_Two`

```cpp
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
```

Ожидаемый вывод (пример):

```
Count: 4
Value: 20
Assepted
Value: 50
Assepted
Value: -100
Rejected
Value: 30
Assepted
Valid: 3, Invalid: 1, Working: 2
Average: 33.333333
```

Смысл функции:
Практика работы с циклом `for` и подсчетом статистики. Мы считываем количество замеров (не больше 10), а затем в цикле вводим значения. Если значение выходит за пределы от -50 до 100, оно отбрасывается с помощью `continue` (переход к следующей итерации). Если значение допустимо, мы добавляем его к сумме и увеличиваем счетчик принятых. Дополнительно мы считаем, сколько значений попали в "рабочий" диапазон от 0 до 40. В конце выводится статистика и среднее арифметическое. Тернарный оператор в конце проверяет, были ли вообще принятые значения, чтобы избежать деления на ноль.

Ошибка в коде: Слово `"Assepted"` написано с ошибкой, правильно — `"Accepted"`. Также в конце функции не хватает закрывающей фигурной скобки для блока `else` (или она есть, но в предоставленном тексте не видна — проверь внимательно парность скобок).

## Функция `Ex_Three`

```cpp
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
```

Ожидаемый вывод (пример):

```
Budget: 50000
Price (0 stop): 20000
Added
Items: 1

 Spent: 20000

Remaining: 30000

Price (0 stop): 40000
Items: 1

 Spent: 20000

Remaining: 30000

Price (0 stop): 0
```

Смысл функции:
Практика на прерывание цикла (`break`) и пропуск итераций (`continue`). Программа позволяет ввести до 10 цен (или остановиться раньше, введя 0). Внутри цикла мы проверяем, не превышает ли цена допустимый лимит, и если да, то пропускаем её с помощью `continue`. Затем проверяется, влезает ли покупка в оставшийся бюджет. Если да — мы добавляем траты и увеличиваем счетчик покупок. Если нет — просто выводим информацию о текущем состоянии. Это полезный пример для понимания того, как работают ограничения и контроль бюджета.

Ошибка в коде: Внутри цикла дважды повторяется проверка `if (price < 0 || price > limit)`. Второй блок лишний, его можно удалить. Также на каждом шаге цикла выводится итоговая статистика, даже если покупка не была добавлена — это может сбивать с толку. Кроме того, проверка `price > budget - spent` работает не так, как задумано: она пропускает покупки, которые больше оставшегося бюджета (вместо того, чтобы добавлять только те, которые меньше или равны). Более того, если цена больше остатка, программа ничего не добавляет, но и не сообщает об ошибке. И, наконец, на графике `else` пропущена закрывающая фигурная скобка для функции — это ошибка компиляции.