#include <stdio.h>
#include <assert.h>
#include <string>
#include <iostream>
#include <stdint.h>

using namespace std;


int main()
{
    FILE* file = fopen("1.txt", "w+");
    assert(file);
    int a = 10;

    for(int i = 0; i < 10 ; i++)
    {
        fprintf(file, "%d\n", a);
    }
    
    std::string  str;
    uint16_t value ;
    char v[1024];
    fseek(file, 0, SEEK_SET);
    while(fgets(v, 1024, file) )
    {
        str = v;
        sscanf(str.c_str(), "%u", &value);
        cout << value << endl;

    }
    return 0;
}

