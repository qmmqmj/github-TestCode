#include <iostream>
#include "yourstring.h"

int main()
{
    String a("abcd");
    String b("qwer");
    String c(b);
    String d(c);
    std::cout << b[1] << std::endl;
}