#include <iostream>
#include "Message3.h"

int main(int argc, char *argv[])
{
    Message obj1;
    Message obj2("Hello World.");

    obj1.addMessage("I'm Yoyoyo!");
    obj1.showAllMessages();
    std::cout << std::endl;

    obj2.addMessage(obj1.getMessage(0));
    obj2.showAllMessages();
    std::cout << std::endl;

    Message obj3("I love Techi.");
    obj3 = obj2;
    obj3.showAllMessages();
    std::cout << std::endl;

    obj3.addMessage("I love Techi!!");
    std::cout << obj3.getNMessages() << std::endl;
    std::cout << obj3.getMessage(obj3.getNMessages() - 1) << std::endl;
    std::cout << std::endl;

    obj3.showAllMessages();

    return 0;
}