#ifndef RESPONSETOSTRING_H
#define RESPONSETOSTRING_H
#include <QString>


class ResponseToString
{
public:
    ResponseToString();
    static int writer(char *data, size_t size, size_t nmemb, QString *buffer);
};

#endif // RESPONSETOSTRING_H
