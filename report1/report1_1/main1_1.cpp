#include <iostream>
#include "Message1_1.h"

int main(int argc, char *argv[])
{
    Message obj("hello.");
    // Message obj;
    // obj.setMessage("Hello World.");
    std::cout << obj.getMessage() << std::endl;

    return 0;
}