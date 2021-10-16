#include <iostream>

using namespace std;

class Base{
public:
    Base(){ fun(); };
    virtual void fun(){ cout << "Base" << endl; } 
};

class Derive1 :public Base {
public:
    Derive1() { fun(); }
    virtual void fun() { cout << "Derive1" << endl; }
};


class Derive2 :public Derive1 {
public:
    Derive2() { fun(); }
    virtual void fun() { cout << "Derive2" << endl; }
};



int main()
{
    Derive2 de2;
    return 0;
}

