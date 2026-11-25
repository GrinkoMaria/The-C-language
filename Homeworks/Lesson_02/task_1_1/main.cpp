#include <iostream>
enum class Mode : int { Slow=1, Normal=2, Fast=3 };
int interval(Mode mode) {
    switch (mode) {
        case Mode::Slow: return 60;
        case Mode::Normal: return 15;
        case Mode::Fast: return 5;
        default: return -1;
    }
}
int main(){std::cout<<interval(Mode::Normal)<<'\n';return 0;}
