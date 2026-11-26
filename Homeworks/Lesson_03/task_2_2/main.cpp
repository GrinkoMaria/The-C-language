#include <iostream>
int main(){
int first{}, second{};
    std::cin >> first >> second;

    int* p{new int{first}};
    std::cout << *p << '\n';
    delete p;

    p = new int{second};
    std::cout << *p << '\n';
    delete p;

    return 0;
    }
