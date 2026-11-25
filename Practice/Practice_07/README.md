# Разбор практики: Моделирование системы полива

## Структура `State` и пространство имен `config`

```cpp
using Percent = int;
using Liters = int;
using Operations = int;

namespace config {
    constexpr Percent minMoisture{ 0 };
    constexpr Percent maxMoisture{ 100 };
    constexpr Percent openLimit{ 60 };
    constexpr Percent pulseLimit{ 85 };
    constexpr Percent pulseIncrease{ 20 };
    constexpr Liters pulseWaterCost{ 5 };
    constexpr Operations maxOperations{ 8 };
}

struct State {
    Percent moisture{ 0 };
    bool valveOpen{ false };
    Operations operations{ 0 };
    Liters waterUsed{ 0 };
};
```

Теория:
В этом коде используется уже знакомый нам подход с псевдонимами типов и пространством имен. Мы даем понятные имена типам `int`, чтобы в коде было видно, где проценты, где литры, а где количество операций. Все бизнес-правила собраны в `namespace config`: минимальная и максимальная влажность, пороги для открытия клапана и подачи воды, стоимость одной порции воды и лимит операций.
Структура `State` — это снимок текущего состояния системы. Она хранит влажность, статус клапана (открыт/закрыт), количество выполненных операций и общий расход воды. Все поля инициализированы значениями по умолчанию, так что при создании `State s;` мы получаем чистую систему, готовая к работе.

## Вспомогательные функции

```cpp
bool canOpenValve(const State& s) {
    return !s.valveOpen && s.moisture < config::openLimit;
}

bool canPulseWater(const State& s) {
    return !s.valveOpen && s.moisture < config::pulseLimit;
}

void printTelemetry(const State& s) {
    std::cout << "Valve open: " << std::boolalpha << s.valveOpen << "\n";
    std::cout << "Moisture: " << s.moisture << "%\n";
    std::cout << "Water used: " << s.waterUsed << " L\n";
}
```

Теория:
Эти функции вынесены отдельно, чтобы не дублировать логику проверок и вывода. `canOpenValve` проверяет два условия: клапан должен быть закрыт, и влажность должна быть ниже порога `openLimit`. `canPulseWater` проверяет, что клапан закрыт и влажность ниже `pulseLimit` (более высокого порога, чтобы можно было быстро добрать влагу).
Функция `printTelemetry` принимает состояние по константной ссылке (`const State& s`), что означает: мы не копируем всю структуру, а просто смотрим на неё и не можем изменить. Это эффективно и безопасно.

## Функция `main`

```cpp
int main()
{
    State s;

    std::cout << "Moisture: ";
    if (!(std::cin >> s.moisture)) {
        std::cout << "Input error\n";
        return 1;
    }
    if (s.moisture < config::minMoisture || s.moisture > config::maxMoisture) {
        std::cout << "Invalid moisture\n";
        return 2;
    }

    while (s.operations < config::maxOperations) {
        int code = 0;
        std::cout << "Action 0/1/2/3/4: ";
        if (!(std::cin >> code)) {
            std::cout << "Input error\n";
            return 1;
        }

        if (code == 0) {
            break;
        }
        else if (code == 1) {
            std::cout << "Status\n";
            printTelemetry(s);
        }
        else if (code == 2) {
            if (canOpenValve(s)) {
                s.valveOpen = true;
                s.operations++;
                std::cout << "Valve opened\n";
                printTelemetry(s);
            }
            else {
                std::cout << "Open denied\n";
            }
        }
        else if (code == 3) {
            s.valveOpen = false;
            s.operations++;
            std::cout << "Valve closed\n";
            printTelemetry(s);
        }
        else if (code == 4) {
            if (canPulseWater(s)) {
                s.moisture += config::pulseIncrease;
                if (s.moisture > config::maxMoisture) {
                    s.moisture = config::maxMoisture;
                }
                s.waterUsed += config::pulseWaterCost;
                s.operations++;
                std::cout << "Pulse completed\n";
                printTelemetry(s);
            }
            else {
                std::cout << "Pulse denied\n";
            }
        }
        else {
            std::cout << "Unknown action\n";
        }
    }

    std::cout << "Operations: " << s.operations << "\n";
    std::cout << "Total water: " << s.waterUsed << " L\n";
    return 0;
}
```

Ожидаемый вывод (пример сессии):

```
Moisture: 40
Action 0/1/2/3/4: 2
Valve opened
Valve open: true
Moisture: 40%
Water used: 0 L
Action 0/1/2/3/4: 4
Pulse denied
Action 0/1/2/3/4: 3
Valve closed
Valve open: false
Moisture: 40%
Water used: 0 L
Action 0/1/2/3/4: 4
Pulse completed
Valve open: false
Moisture: 60%
Water used: 5 L
Action 0/1/2/3/4: 0
Operations: 3
Total water: 5 L
```

Смысл функции:
Это основная логика программы, реализованная через конечный автомат (state machine). Сначала мы запрашиваем начальную влажность и проверяем её на корректность (от 0 до 100). Если ввод неверный, программа завершается с кодом ошибки.

Затем запускается цикл `while`, который работает до тех пор, пока количество операций меньше `maxOperations` (8). На каждом шаге пользователь вводит код действия:

- 0 — досрочный выход.
- 1 — показать текущий статус.
- 2 — открыть клапан, если это разрешено (клапан закрыт и влажность ниже 60).
- 3 — закрыть клапан (это действие всегда разрешено, даже если клапан уже закрыт, поэтому операция засчитывается).
- 4 — подать воду импульсом, если это разрешено (клапан закрыт и влажность ниже 85). При этом влажность увеличивается на 20% (но не выше 100%), расходуется 5 литров воды, и операция засчитывается.

Если действие не разрешено, программа выводит отказ и не увеличивает счетчик операций. В конце цикла выводится общее количество операций и суммарный расход воды.

Ошибка в коде: С точки зрения синтаксиса и логики код написан чисто. Единственный нюанс — операция `3` (закрытие клапана) всегда засчитывается как выполненная, даже если клапан уже был закрыт. В реальной системе это может быть нежелательно, но в рамках учебной задачи такое поведение допустимо.