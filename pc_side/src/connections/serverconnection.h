#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H
#include "curl/curl.h"
#include <string>

static int writer(char *data, size_t size, size_t nmemb, std::string *buffer);

class ServerConnection
{
public:
    int writera(char *data, size_t size, size_t nmemb, std::string *buffer);
    ServerConnection();

    std::string callGetRequest(std::string url);
};

#endif // SERVERCONNECTION_H
