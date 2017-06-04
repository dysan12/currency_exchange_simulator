#include <string>

#include "exception.h"

Exception::Exception(char* message):message(message){}

char* Exception::getMessage()
{
    return this->message;
}


