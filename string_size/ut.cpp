#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str("abcd");
    cout << "[string.size(): " << str.size() << "]" << endl;
    cout << "[sizeof(string abce): " << sizeof(str)  << "]" << endl;
    str = "abcdefg";
    cout << "[string.size(): " << str.size() << "]" << endl;
    cout << "[sizeof(string abcdefg): " << sizeof(str)  << "]" << endl;
    str = "abcdefgabcdefgabcdefgabcdefg";
    cout << "[string.size(): " << str.size() << "]" << endl;
    cout << "[sizeof(string abcdefgabcdefgabcdefgabcdefg): " << sizeof(str)  << "]" << endl;
    return 0;
}