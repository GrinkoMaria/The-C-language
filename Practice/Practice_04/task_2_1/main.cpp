#include <iostream>
#include <string>

bool mayAttend(int age, bool permission);

int main()
{
    return 0;
}

bool mayAttend(int age, bool permission)
{
    if (age >= 16){
    return true;
    }
    else if (age >= 12) {
    return permission;
    } else {
    return false;
    }
}
