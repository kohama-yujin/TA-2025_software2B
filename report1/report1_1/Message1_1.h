#include <iostream>

class Message
{
private:
   char *message;

public:
   Message();
   Message(const char *message);
   ~Message();

   void setMessage(const char *message);
   char *getMessage(void);
};