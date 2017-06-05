#include <string>

#include "exception.h"

Exception::Exception(const std::string message):message(message){}

std::string Exception::getMessage()
{
    return this->message;
}


