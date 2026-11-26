#include <iostream>
int* createCounter(int start){
    if (start < 0 || start > 100) {
        return nullptr;
    }
    return new int{start};
}
bool increase(int* counter,int amount){
    if (counter == nullptr || amount < 1 || amount > 100) {
        return false;
    }
    if (*counter < 0 || *counter > 100 || *counter + amount > 100) {
        return false;
    }

    *counter += amount;
    return true;
}
int main(){
    int start{}, amount{};

    if (!(std::cin >> start >> amount)) {
        std::cout << "Input error\n";
        return 1;
    }

    int* counter{createCounter(start)};

    if (counter == nullptr) {
        std::cout << "Invalid start\n";
        return 0;
    }

    bool success{increase(counter, amount)};

    std::cout << "Success: " << (success ? "true" : "false") << '\n';
    std::cout << "Value: " << *counter << '\n';

    delete counter;

    return 0;
}
