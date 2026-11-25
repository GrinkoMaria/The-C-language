#include <iostream>
int findFirst(const int* data,int size,int target){
    if (data == nullptr || size <= 0) return -1;

for (int i = 0; i < size; i++) {
    if (data[i] == target) {
        return i;
    }
}
return -1;
}
int main(){int data[]{7,4,7,9};std::cout<<findFirst(data,4,7)<<'\n';return 0;}
