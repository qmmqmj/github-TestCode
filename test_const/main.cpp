#include <iostream>

int main()
{
    int * a = new int(1);
    const int* b = a;
    std::cout << "b: " << *b << std::endl;
    *a = 2;
    std::cout << "b: " << *b << std::endl;
    return 0;
}