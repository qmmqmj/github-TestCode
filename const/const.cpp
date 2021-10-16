#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
//#include <typeinfo>
class CTextBlock
{
public:
    std::size_t length() const;

private:
    char* pText;
    mutable std::size_t textLength;
    mutable bool lengthIsValid;
};

std::size_t CTextBlock::length() const
{
    if(!lengthIsValid)
    {
        textLength = strlen(pText);
        lengthIsValid = true;
    }
}

int main()
{
    return 0;
}