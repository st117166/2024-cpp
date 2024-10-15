#include "string.h"
#include <iostream>

int main()
{
    String str("Hello world");
    String substring = str[0][5];
    std::cout << substring << std::endl;
    String substring1 = str[7][7];
    std::cout << substring1 << std::endl;
}