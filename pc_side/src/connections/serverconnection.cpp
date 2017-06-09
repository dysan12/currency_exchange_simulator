#include "serverconnection.h"
#include <cstring>

ServerConnection::ServerConnection()
{

}

static int writer(char *data, size_t size, size_t nmemb, std::string *buffer)
{
    int result = 0;

    if (buffer != NULL) {
        buffer->append(data, size * nmemb);
        result = size * nmemb;
    }
    return result;
}
/*
std::string ServerConnection::callRequest(std::string url, std::string method)
{
    std::string keys[1] = {0},
            values[1] = {0};
    this->callRequest(url, method, keys, values);
}*/

/**
 * @brief ServerConnection::callRequest - initializes and sends request to server
 * @param url - request's url
 * @param method - request's method
 * @param keys - keys of request's params
 * @param values - values of request's params
 * @return - server's response
 */
std::string ServerConnection::callRequest(std::string url,
                                          std::string method,
                                          std::vector <std::string> keys,
                                          std::vector <std::string> values)
{
    CURL *curl;
    CURLcode response;
    std::string responseString,
            composedData = this->composeData(keys, values);
    int statusCode = 0;

    url = std::string(SERVER_URL) + url;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {

        if (method == "GET")
            this->callGetPart(curl, url, composedData);
        else if (method == "POST")
            this->callPostPart(curl, url, composedData);
        else if (method == "PUT")
            this->callPutPart(curl, url, composedData);
        else if (method == "DELETE")
            this->callDeletePart(curl, url, composedData);
        else
            throw new NotHandledMethodException();

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseString);

        response = curl_easy_perform(curl);
        curl_easy_getinfo (curl, CURLINFO_RESPONSE_CODE, &statusCode);

        curl_easy_cleanup(curl);

        curl_global_cleanup();
    } else
        throw new ServerConnectionBrokenException();

    this->handleStatusCode(statusCode);

    return responseString;
}

/**
 * @brief ServerConnection::callPutPart - calls proper headers for GET request
 * @param curl - connection
 * @param url
 * @param composedData - string data eg. "key=value&key2=value2";
 */
void ServerConnection::callGetPart(CURL *curl, std::string url, std::string composedData)
{
    url = url + (composedData.length() ? ("?" + composedData) : "");
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
}

/**
 * @brief ServerConnection::callPutPart - calls proper headers for POST request
 * @param curl - connection
 * @param url
 * @param composedData - string data eg. "key=value&key2=value2";
 */
void ServerConnection::callPostPart(CURL *curl, std::string url, std::string composedData)
{
    char *params = new char[composedData.length() + 1];
    std::strcpy(params, composedData.c_str());
    //params[composedData.size()] = '\0';

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params);
}

/**
 * @brief ServerConnection::callPutPart - calls proper headers for DELETE request
 * @param curl - connection
 * @param url
 * @param composedData - string data eg. "key=value&key2=value2";
 */
void ServerConnection::callDeletePart(CURL *curl, std::string url, std::string composedData)
{
    char *params = new char[composedData.length() + 1];
    std::strcpy(params, composedData.c_str());

    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params);
}

/**
 * @brief ServerConnection::callPutPart - calls proper headers for PUT request
 * @param curl - connection
 * @param url
 * @param composedData - string data eg. "key=value&key2=value2";
 */
void ServerConnection::callPutPart(CURL *curl, std::string url, std::string composedData)
{
    char *params = new char[composedData.length() + 1];
    std::strcpy(params, composedData.c_str());

    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params);
}

/**
 * @brief ServerConnection::composeData - prepare data for request, joins two arrays by marks "=" and "&"
 * @param keys - array with keys
 * @param values - array with values
 * @return string data eg. "key=value&key2=value2";
 */
std::string ServerConnection::composeData(std::vector <std::string> keys, std::vector <std::string> values)
{
    int sizeKeys = keys.size(),
        sizeValues = values.size();
    std::string composedData = "";

    if (sizeKeys != sizeValues)
        throw new ArraysSizeIncompatibleException();

    for (int i = 0; i < sizeKeys; i++) {
        composedData += keys[i] + "=" + values[i] + (sizeKeys - 1 != i ? "&" : "");
    }

    return composedData;
}

/**
 * @brief ServerConnection::handleStatusCode
 * @param statusCode
 * @throws BadRequestException - if status code is 400, 404
 * @throws AccessDeniedException - if status code is 401, 403
 * @throws InternalServerErrorException - if status code is 500
 */
void ServerConnection::handleStatusCode(int statusCode)
{
    switch(statusCode) {
        case 200:
        case 201:
        case 204:
            break;
        case 400:
        case 404:
            throw new BadRequestException();
            break;
        case 401:
        case 403:
            throw new AccessDeniedException();
            break;
        case 500:
            throw new InternalServerErrorException();
            break;
    }
}
