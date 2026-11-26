#include <iostream>
int total{0};
int* create(int value){
    int local{value};
    static int calls{0};
    ++calls;
    int* p{new int{local+calls}};
    return p;
}
int main(){
    int* result{create(4)};
    {int temp{2};total+=temp;}
    std::cout<<*result<<' '<<total<<'\n';
    delete result;
    result=nullptr;
    return 0;
}
