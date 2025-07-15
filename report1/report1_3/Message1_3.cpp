#include <iostream>
#include <cstring>
#include "Message1_3.h"

// デフォルトコンストラクタ
Message::Message() : message(nullptr)
{
}

// 引数持ちコンストラクタ
Message::Message(const char *msg)
{
    message = new char[strlen(msg) + 1];
    std::strcpy(message, msg);
}

// デストラクタ
Message::~Message()
{
    delete[] message;
}

// セッター
void Message::setMessage(const char *msg)
{
    delete[] message; // 古いメモリを解放
    message = new char[strlen(msg) + 1];
    std::strcpy(message, msg);
}

// ゲッター
char *Message::getMessage(void)
{
    return message;
}

// 抽出演算子 >>
std::istream &operator>>(std::istream &stream, Message &obj)
{
    char buffer[1024];            // 一時バッファ
    stream.getline(buffer, 1024); // 空白含めて1行読み取る
    obj.setMessage(buffer);
    return stream;
}

// 挿入演算子 <<
std::ostream &operator<<(std::ostream &stream, Message &obj)
{
    if (obj.getMessage())
    {
        stream << obj.getMessage();
    }
    return stream;
}