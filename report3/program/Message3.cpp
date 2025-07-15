#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include "Message3.h"

// デフォルトコンストラクタ
Message::Message() : message({})
{
}

// 引数持ちコンストラクタ
Message::Message(const std::string &message_string)
{
    message.push_back(message_string);
}

// コピーコンストラクタ
Message::Message(const std::vector<std::string> &message_vector)
{
    for (auto elem : message_vector)
        message.push_back(elem);
}

// デストラクタ
Message::~Message()
{
}

void Message::addMessage(const std::string &message_string)
{
    message.push_back(message_string);
}

std::string Message::getMessage(int message_id)
{
    return message[message_id];
}

void Message::showAllMessages(void)
{
    for (auto elem : message)
        std::cout << elem << std::endl;
}

int Message::getNMessages(void)
{
    return message.size();
}