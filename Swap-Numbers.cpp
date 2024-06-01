#include <iostream>

int main()
{
    int a = 10;
    int b = 20;
    int temp = b;

    b = a;
    a = temp;
    std::cout << a;
    std::cout << b;
    return 0;
}