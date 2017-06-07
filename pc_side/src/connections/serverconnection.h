#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H
#include "curl/curl.h"
#include <string>

class ServerConnection
{
public:
    int writer(char *data, size_t size, size_t nmemb, std::string *buffer);
    ServerConnection();

    std::string callGetRequest(std::string url);
};

#endif // SERVERCONNECTION_H
