#include <iostream>

class Message
{
private:
    char *message;

public:
    Message();
    Message(const char *_message);
    ~Message();

    void setMessage(const char *_message);
    char *getMessage(void);

    friend std::istream &operator>>(std::istream &stream, Message &obj);
    friend std::ostream &operator<<(std::ostream &stream, Message &obj);
};