#include "responsehandler.h"

ResponseHandler::ResponseHandler()
{

}

void ResponseHandler::handleRatesResponse(std::string rates, double convertedRates[10]){
    const char* json = rates.c_str();
    Document document;
    document.Parse(json);

    double pln = atof(document["response"]["data"]["pln"].GetString());
    convertedRates[0]=1/pln;
    /*double currency = atof(document["response"]["data"]["usd"].GetString());
     * NIE, bo USD=1 wedlug rates ktore otrzymujemy
     * USD konwertujemy dzielac przez kurs pln, a reszte walut liczymy nizej
     */
    double currency = atof(document["response"]["data"]["eur"].GetString());
    convertedRates[1]=pln/currency;
    currency = atof(document["response"]["data"]["jpy"].GetString());
    convertedRates[2]=pln/currency;
    currency = atof(document["response"]["data"]["gbp"].GetString());
    convertedRates[3]=pln/currency;
    currency = atof(document["response"]["data"]["czk"].GetString());
    convertedRates[4]=pln/currency;
    currency = atof(document["response"]["data"]["aud"].GetString());
    convertedRates[5]=pln/currency;
    currency = atof(document["response"]["data"]["brl"].GetString());
    convertedRates[6]=pln/currency;
    currency = atof(document["response"]["data"]["dkk"].GetString());
    convertedRates[7]=pln/currency;
    currency = atof(document["response"]["data"]["nok"].GetString());
    convertedRates[8]=pln/currency;
    currency = atof(document["response"]["data"]["rub"].GetString());
    convertedRates[9]=pln/currency;
}
