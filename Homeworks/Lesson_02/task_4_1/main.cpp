#include <iostream>
bool isAccepted(int value){
    constexpr int minVal = 0;
    constexpr int maxVal = 50;
    return value >= minVal && value <= maxVal;
}
bool summarize(const int* data,int size,int& count,int* sum){
    constexpr int maxSize = 20;
    
     if (size < 0 || size > maxSize) {
        return false;
    }

    if (size > 0 && data == nullptr) {
        return false;
    }

    int acceptedCount = 0;
    int acceptedSum = 0;

    for (int i = 0; i < size; i++) {
        if (isAccepted(data[i])) {
            acceptedCount++;
            acceptedSum += data[i];
        }
    }

    count = acceptedCount;

    if (sum != nullptr) {
        *sum = acceptedSum;
    }

    return true;
}    

int main(){int data[]{-1,0,20,51,50};int count{-1},sum{-1};bool ok=summarize(data,5,count,&sum);std::cout<<std::boolalpha<<ok<<' '<<count<<' '<<sum<<'\n';return 0;}
