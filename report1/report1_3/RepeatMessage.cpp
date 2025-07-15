#include <iostream>
#include <cstring>
#include "RepeatMessage.h"

RepeatMessage::RepeatMessage() : nloops(0)
{
}

RepeatMessage::RepeatMessage(const int num)
{
    nloops = num;
}

RepeatMessage::~RepeatMessage()
{
}

void RepeatMessage::setNloops(const int num)
{
    nloops = num;
}

int RepeatMessage::getNloops(void)
{
    return nloops;
}

std::ostream &operator<<(std::ostream &stream, RepeatMessage &obj)
{
    for (int i = 0; i < obj.getNloops(); i++)
        stream << obj.getMessage();

    return stream;
}