#include <iostream>
bool tryMin(const int* data,int size,int& result){
    if (data == nullptr || size <= 0) return false;

result = data[0];

for (int i = 1; i < size; i++) {
    if (data[i] < result) {
        result = data[i];
    }
}

return true;
}
int main(){int data[]{5,8,2};int result{99};bool ok=tryMin(data,3,result);std::cout<<std::boolalpha<<ok<<' '<<result<<'\n';return 0;}
