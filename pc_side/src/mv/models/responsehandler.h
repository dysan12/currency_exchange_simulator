#ifndef RESPONSEHANDLER_H
#define RESPONSEHANDLER_H

#include <vector>

#include "model.h"
#include "libs/rapidjson/include/rapidjson/document.h"
#include "investment.h"

using namespace rapidjson;

class ResponseHandler : public Model
{
public:
    ResponseHandler();

    void handleRatesResponse(std::string rates, double convertedRates[10]);
    std::vector <Investment*> processUserInvestments(std::string jsonResponse);

};

#endif // RESPONSEHANDLER_H
