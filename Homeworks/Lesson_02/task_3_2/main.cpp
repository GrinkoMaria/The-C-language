#include <iostream>
bool replaceAt(int* data,int size,int index,int value){
    if (data == nullptr || size <= 0 || index < 0 || index >= size)
        return false;

    if (value < -100 || value > 100)
        return false;

    data[index] = value;
    return true;
}
int main(){int data[]{3,8,9};bool ok=replaceAt(data,3,1,12);std::cout<<std::boolalpha<<ok<<' '<<data[1]<<'\n';return 0;}
