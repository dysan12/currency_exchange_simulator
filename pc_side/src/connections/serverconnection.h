#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H

#include <string>
#include <vector>
#include "curl/curl.h"

#include "config.h"

#include "arrayssizeincompatibleexception.h"
#include "nothandledmethodexception.h"
#include "serverconnectionbrokenexception.h"
#include "badrequestexception.h"
#include "accessdeniedexception.h"
#include "internalservererrorexception.h"

static int writer(char *data, size_t size, size_t nmemb, std::string *buffer);

class ServerConnection
{
private:
    std::string composeData(std::vector <std::string> keys, std::vector <std::string> values);
    void callGetPart(CURL *curl, std::string url, std::string composedData);
    void callPostPart(CURL *curl, std::string url, std::string composedData);
    void callDeletePart(CURL *curl, std::string url, std::string composedData);
    void callPutPart(CURL *curl, std::string url, std::string composedData);
    void handleStatusCode(int statusCode);
public:
    ServerConnection();
    std::string callRequest(std::string url,
                            std::string method,
                            std::vector <std::string> keys,
                            std::vector <std::string> values);

};

#endif // SERVERCONNECTION_H
