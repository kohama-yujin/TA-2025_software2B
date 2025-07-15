#include <iostream>
#include <cstring>
#include "Message1_1.h"

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