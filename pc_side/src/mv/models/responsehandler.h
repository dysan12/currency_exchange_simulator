#ifndef RESPONSEHANDLER_H
#define RESPONSEHANDLER_H
#include "model.h"
#include "libs/rapidjson/include/rapidjson/document.h"

using namespace rapidjson;

class ResponseHandler : public Model
{
public:
    ResponseHandler();

    void handleRatesResponse(std::string rates, double convertedRates[10]);
};

#endif // RESPONSEHANDLER_H
