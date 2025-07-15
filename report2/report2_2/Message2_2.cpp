#include <stdlib.h>
#include <string.h>
#include <string>
#include "Message2_2.h"

// デフォルトコンストラクタ
Message::Message() : message(nullptr)
{
}

// 引数持ちコンストラクタ
Message::Message(const char *_message)
{
    message = new char[strlen(_message) + 1];
    strcpy(message, _message);
}

// デストラクタ
Message::~Message()
{
    if (message != nullptr)
        delete[] message;
}

// コピーコンストラクタ
Message::Message(const Message &obj)
{
    message = new char[strlen(obj.getMessage()) + 1];
    strcpy(message, obj.getMessage());
}

// セッター
void Message::setMessage(const char *_message)
{
    if (message != nullptr)
        delete[] message;
    message = new char[strlen(_message) + 1];
    strcpy(message, _message);
}

// ゲッター
char *Message::getMessage(void) const
{
    return message;
}

// 抽出演算子 >>
std::istream &operator>>(std::istream &stream, Message &obj)
{
    std::string buffer;
    std::getline(stream, buffer);
    obj.setMessage(buffer.c_str());
    return stream;
}

// 挿入演算子 <<
std::ostream &operator<<(std::ostream &stream, Message &obj)
{
    stream << obj.getMessage();
    return stream;
}