# Разбор практики: Комплексные задачи с управляющими конструкциями

## Функция `Task1`

```cpp
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
```

Ожидаемый вывод:

```
Accepted: 1
Accepted: 2
Accepted: 3
No places
No places
Total: 3
```

Смысл функции:
Демонстрация работы цикла с условием и счетчиком. Программа имитирует регистрацию на мероприятие: есть лимит в 3 места, и есть 5 запросов. Цикл проходит 5 раз. На первых трех итерациях счетчик `registered` меньше лимита, поэтому заявка принимается, и счетчик увеличивается. На четвертой и пятой итерациях условие `registered >= limit` становится истинным, и программа выводит отказ. Это классический пример использования `if-else` внутри цикла для управления состоянием.

Ошибка в коде: Ошибок нет.

## Функция `Task2`

```cpp
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
```

Ожидаемый вывод (пример):

```
Customer: Ivan
Zone weight urgent (0/1): 2 5.5 1
Customer: Ivan
Standard: 260
Urgent: true
Total: 390
Session finished
```

Смысл функции:
Практика на комплексную проверку данных и вычисление стоимости с учетом нескольких факторов. Сначала программа пытается считать три значения. Если ввод не удался (например, пользователь ввел букву вместо числа), она выводит ошибку и завершает функцию. Затем проверяется корректность зоны (от 1 до 3) и веса (больше 0 и не больше 20). Если данные валидны, вычисляется базовая ставка (с помощью вложенного тернарного оператора), стандартная стоимость (база + вес * 20) и итоговая стоимость с наценкой за срочность. Функция учит нас обрабатывать ошибки ввода и избегать неверных расчетов.

Ошибка в коде: Ошибок нет. Проверка `if (!(std::cin >> zone >> weight >> urgent))` — это правильный способ поймать сбой ввода.

## Функция `Task3`

```cpp
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
```

Ожидаемый вывод (пример):

```
Count: 4
Level: 15
Accepted
Level: -5
Rejected
Level: 50
Accepted
Level: 10
Accepted
Valid: 3
Low: 2
Average: 25
Needs charge: true
```

Смысл функции:
Практика на обработку последовательности данных с фильтрацией. Сначала мы запрашиваем количество замеров. Если введено число от 0 до 10, запускается цикл. Внутри цикла мы считываем уровень. Если он меньше 0 или больше 100, он отбрасывается с помощью `continue` (счетчик `validCount` не увеличивается). Если уровень валиден, он добавляется к сумме, а счетчик валидных значений увеличивается. Дополнительно проверяется, сколько значений оказались ниже 20 (для флага необходимости подзарядки). В конце программа аккуратно выводит статистику: сколько было валидных, сколько низких, среднее значение (с защитой от деления на ноль) и флаг true/false. Это учит правильно агрегировать данные и выводить осмысленные результаты.

Ошибка в коде: Ошибок нет. Это очень хороший пример аккуратной обработки ввода и вычислений.

## Функция `main`

```cpp
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
```

Ожидаемый вывод (при выборе 1):

```
Task (1, 2 or 3): 1
Accepted: 1
Accepted: 2
Accepted: 3
No places
No places
Total: 3
```

Смысл функции:
Точка входа в программу. Она организует меню для выбора одной из трех задач. После считывания номера задачи вызывается соответствующая функция. Обрати внимание на `std::cin.ignore(10000, '\n');`. Эта строка очищает буфер ввода, удаляя оставшийся символ новой строки (Enter), который пользователь нажал после ввода числа. Без этой очистки, при переходе в `Task2`, функция `std::getline` могла бы сразу прочитать пустую строку и пропустить ввод имени. Это важный прием при комбинировании `std::cin` и `std::getline` в одном приложении.

Ошибка в коде: Ошибок нет. Использование `std::cin.ignore` здесь оправдано и корректно.