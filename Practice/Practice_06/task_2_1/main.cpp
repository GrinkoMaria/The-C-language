#include <iostream>
enum class BookingStatus { Free, Reserved };
enum class BookingError { None, AlreadyReserved, OutsideHours };
namespace config
{
    constexpr int openHour{9};
    constexpr int closeHour{18};
}
BookingError validateBooking(BookingStatus status, int hour)
{
    if (status == BookingStatus::Reserved) 
        return BookingError::AlreadyReserved;
    
    if (hour < config::openHour || hour > config::closeHour) 
        return BookingError::OutsideHours;
        
    return BookingError::None;
}
int main()
{
    std::cout << std::boolalpha
        << (validateBooking(BookingStatus::Free, 12) == BookingError::None)
        << "\n";
    return 0;
}
