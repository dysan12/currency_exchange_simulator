#include "responsehandler.h"

ResponseHandler::ResponseHandler()
{

}

void ResponseHandler::handleRatesResponse(std::string rates, double convertedRates[10]){
    const char* json = rates.c_str();
    Document document;
    document.Parse(json);

    convertedRates[0]=atof(document["response"]["data"]["pln"].GetString())/
            atof(document["response"]["data"]["usd"].GetString());
    convertedRates[1]=atof(document["response"]["data"]["pln"].GetString())/
            atof(document["response"]["data"]["eur"].GetString());
    convertedRates[2]=atof(document["response"]["data"]["pln"].GetString())/
            atof(document["response"]["data"]["jpy"].GetString());
    convertedRates[3]=atof(document["response"]["data"]["pln"].GetString())/
            atof(document["response"]["data"]["gbp"].GetString());
    convertedRates[4]=atof(document["response"]["data"]["pln"].GetString())/
            atof(document["response"]["data"]["czk"].GetString());
    convertedRates[5]=atof(document["response"]["data"]["pln"].GetString())/
            atof(document["response"]["data"]["aud"].GetString());
    convertedRates[6]=atof(document["response"]["data"]["pln"].GetString())/
            atof(document["response"]["data"]["brl"].GetString());
    convertedRates[7]=atof(document["response"]["data"]["pln"].GetString())/
            atof(document["response"]["data"]["dkk"].GetString());
    convertedRates[8]=atof(document["response"]["data"]["pln"].GetString())/
            atof(document["response"]["data"]["nok"].GetString());
    convertedRates[9]=atof(document["response"]["data"]["pln"].GetString())/
            atof(document["response"]["data"]["rub"].GetString());
}
