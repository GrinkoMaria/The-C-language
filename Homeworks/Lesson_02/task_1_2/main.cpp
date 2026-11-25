#include <iostream>
bool isLevelValid(int level){
    return level >= 10 && level <= 90;
}
int alarmCode(int level){if (isLevelValid(level)) return 0;return 1;}
int displayLevel(int level){if (isLevelValid(level)) return level;return -1;}
int main(){std::cout<<alarmCode(50)<<' '<<displayLevel(50)<<'\n';return 0;}
