#include <string>

#ifndef EXCEPTION_H
#define EXCEPTION_H


class Exception
{
    char* message;
public:
    Exception(char* message);
    char* getMessage();
};

#endif // EXCEPTION_H
