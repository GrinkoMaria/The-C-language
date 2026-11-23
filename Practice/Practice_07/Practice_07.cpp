#include <iostream>

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