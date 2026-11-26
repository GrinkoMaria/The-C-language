#include <iostream>
#include <iomanip>

void printStats(const int* data, int n) {
    int minValue = data[0];
    int maxValue = data[0];
    int sum = 0;
    int positive = 0;

    for (int i = 0; i < n; i++) {
        if (data[i] < minValue) {
            minValue = data[i];
        }

        if (data[i] > maxValue) {
            maxValue = data[i];
        }

        sum += data[i];

        if (data[i] > 0) {
            positive++;
        }
    }

    double average = static_cast<double>(sum) / n;

    std::cout << "Min: " << minValue << '\n';
    std::cout << "Max: " << maxValue << '\n';
    std::cout << "Average: " << std::fixed << std::setprecision(2) << average << '\n';
    std::cout << "Positive: " << positive << '\n';
}

int main() {
    int n{};

    if (!(std::cin >> n)) {
        std::cout << "Input error\n";
        return 1;
    }

    if (n < 1 || n > 100) {
        std::cout << "Invalid size\n";
        return 0;
    }

    int* data{new int[n]};

    for (int i = 0; i < n; i++) {
        if (!(std::cin >> data[i])) {
            std::cout << "Input error\n";
            delete[] data;
            return 1;
        }

        if (data[i] < -1000 || data[i] > 1000) {
            std::cout << "Invalid value\n";
            delete[] data;
            return 0;
        }
    }

    printStats(data, n);

    delete[] data;

    return 0;
}