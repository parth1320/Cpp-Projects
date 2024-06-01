#include <iostream>

int main()
{
    int x = 10;
    int y = x++; // y = 10; x = 11;
    int z = ++x; // z = 11; x = 11;

    std::cout << x;
    return 0;
}