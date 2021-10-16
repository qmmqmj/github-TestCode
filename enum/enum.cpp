#include <stdio.h>
#include <iostream>
#include <array>


class Play{
    static const int a = 100;
public:
    std::array<int, a> array_in;
};
const int a = 100;
using array = std::array<int,a>;

int main()
{
    // array b;
    // b[10] = 10;
    Play play;
    play.array_in[10] = 10;
    std::cout << "b[10]: " << play.array_in[10] << std::endl;
    return 0;
}

//Template
// template <typename T>
// inline void CallWithMax(const T& a, const T& b)
// {
//     f(a >b ? a : b);
// }