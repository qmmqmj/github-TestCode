#include <iostream>
#include <vector>

using namespace std;

int main()
{
    auto v = new vector<int>(10);
    cout << "[vector::size()" << v->size() << "]" << endl;
    delete v;
    return 0;
}