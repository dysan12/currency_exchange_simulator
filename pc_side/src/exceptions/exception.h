#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>


class Exception
{
    std::string message;
public:
    Exception(const std::string message = "No message");
    std::string getMessage();
};

#endif // EXCEPTION_H
