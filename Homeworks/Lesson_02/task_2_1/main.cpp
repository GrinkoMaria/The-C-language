#include <iostream>
int countInRange(const int* data,int size){
    if (size < 0 || (data == nullptr && size > 0)) return -1;
if (size == 0) return 0;

int count = 0;
for (int i = 0; i < size; i++) {
    if (data[i] >= -10 && data[i] <= 10) {
        count++;
    }
}
return count;
}
int main(){int data[]{-11,-10,0,10,11};std::cout<<countInRange(data,5)<<'\n';return 0;}
