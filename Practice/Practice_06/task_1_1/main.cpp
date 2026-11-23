#include <iostream>
enum class ParcelState : int
{
    Created = 10, InTransit = 20, Delivered = 30
};
int progressPercent(ParcelState state)
{
    if (state == ParcelState::Created) {
        return 0;
    }
    else if (state == ParcelState::InTransit){
        return 50;
    } 
    else if (state == ParcelState::Delivered){
        return 100;
    }
    return 0;
}
int main()
{
    std::cout << static_cast<int>(ParcelState::Created)
              << " " << progressPercent(ParcelState::Created) << "\n";
    return 0;
}
