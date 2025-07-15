#include "Message1_3.h"

class RepeatMessage : public Message
{
private:
    int nloops;

public:
    RepeatMessage();
    RepeatMessage(const int num);
    ~RepeatMessage();

    void setNloops(const int num);
    int getNloops(void);

    friend std::ostream &operator<<(std::ostream &stream, RepeatMessage &obj);
};