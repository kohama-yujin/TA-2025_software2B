#include <iostream>
#include "Message1_2.h"

int main(int argc, char *argv[])
{
    Message obj;
    std::cout << "Input message: ";
    std::cin >> obj;
    std::cout << "Output message: ";
    std::cout << obj << std::endl;

    return 0;
}