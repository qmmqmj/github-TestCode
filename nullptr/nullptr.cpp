#include <iostream>

class NullPtr{
public:
    int a;
    void func()
    {
        std::cout << "aaa" << std::endl;
    }
};


int main()
{
    NullPtr* null = nullptr;
    null->func();
    return 0;
}