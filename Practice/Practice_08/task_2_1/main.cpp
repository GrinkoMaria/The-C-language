#include <iostream>
enum class Light { Red = 1, Yellow = 2, Green = 3 };
int waitSeconds(Light light) {
    switch (light){
        case Light::Red:
            return 60;
        case Light::Yellow:
            return 5;
        case Light::Green:
            return 0;
        default:
            return -1; 
    }
}
int main() { std::cout << waitSeconds(Light::Yellow) << "\n"; return 0;}
