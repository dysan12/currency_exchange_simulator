#include "serverconnection.h"

ServerConnection::ServerConnection()
{

}

int ServerConnection::writer(char *data, size_t size, size_t nmemb, std::string *buffer) {
    int result = 0;

    if (buffer != NULL) {
    buffer->append(data, size * nmemb);
    result = size * nmemb;
    }
    return result;
}

std::string ServerConnection::callGetRequest(std::string url){
    CURL *curl;
    CURLcode response;
    std::string responseString;

    curl = curl_easy_init();
   // if(curl) { <---jeśli nie będzie połączenia
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HEADER, 0);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, this->writer);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseString);

    response = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    return responseString;
}
