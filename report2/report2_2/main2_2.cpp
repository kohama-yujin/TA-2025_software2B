#include <iostream>
#include "Message2_2.h"

int main(int argc, char *argv[])
{
    Message obj1("Hello World.");
    Message obj2 = obj1;

    printf("obj1: %p\n", obj1.getMessage());
    printf("obj2: %p\n", obj2.getMessage());

    std::cout << obj2 << std::endl;

    return 0;
}