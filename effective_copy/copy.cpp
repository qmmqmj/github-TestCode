#include <iostream>
#include <bits/stdc++.h>

// class Widget{
// private:
//     int a;

// public: 
//     Widget& Widget::operateor=(Widget rhs)
//     {
//         swap(rhs);
//         return *this;
//     }

//     void swap(Widget & rhs)
//     {
        
//     }
// };


class Base{
private:
    int m_a;
public:
    Base(int a) :m_a(a) {}
    Base(){}
    void swap(Base & base)
    {
        base.m_a = m_a;
    }
    void cout() {std::cout << m_a << std::endl;}
};



int main()
{
    Base b1(2);
    Base b2(3);
    b2.swap(b1);
    b1.cout();
    return 0;
}

