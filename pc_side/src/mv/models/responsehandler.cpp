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

std::vector <Investment*> ResponseHandler::processUserInvestments(std::string jsonResponse)
{
    Document document;
    document.Parse(jsonResponse.c_str());

    std::vector <Investment*> investments;

    for (SizeType i = 0; i < document["response"]["data"].Size(); i++) {
        std::string user_login = document["response"]["data"][i]["user_login"].GetString();
        std::string found_date = document["response"]["data"][i]["found_date"].GetString();
        std::string name = document["response"]["data"][i]["name"].GetString();
        double pln = atof(document["response"]["data"][i]["pln"].GetString());
        double usd = atof(document["response"]["data"][i]["usd"].GetString());
        double eur = atof(document["response"]["data"][i]["eur"].GetString());
        double jpy = atof(document["response"]["data"][i]["jpy"].GetString());
        double gbp = atof(document["response"]["data"][i]["gbp"].GetString());
        double czk = atof(document["response"]["data"][i]["czk"].GetString());
        double aud = atof(document["response"]["data"][i]["aud"].GetString());
        double brl = atof(document["response"]["data"][i]["brl"].GetString());
        double dkk = atof(document["response"]["data"][i]["dkk"].GetString());
        double nok = atof(document["response"]["data"][i]["nok"].GetString());
        double rub = atof(document["response"]["data"][i]["rub"].GetString());
        investments.push_back(new Investment(user_login,found_date,name,pln,usd,
                                             eur,jpy,gbp,czk,aud,brl,dkk,nok,rub));
    }

    return investments;
}

double ResponseHandler::currencyStringToDouble(Document document, std::string currency){
    ;
}
