#include <iostream>
void normalizeScore(int& score) {
    if (score < 0) {
        score = 0;
    }
    if (score > 100){
        score = 100;
    }
}
int main() { int score = 125; normalizeScore(score); std::cout << score << "\n"; return 0;}
