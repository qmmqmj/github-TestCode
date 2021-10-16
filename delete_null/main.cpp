#include <iostream>

int main()
{
    int* a = nullptr;
    delete a;
    delete a;
    std::cout << "abcd" << std::endl;
    return 0;
}