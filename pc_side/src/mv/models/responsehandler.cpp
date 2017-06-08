#include "responsehandler.h"

ResponseHandler::ResponseHandler()
{

}

void ResponseHandler::handleRatesResponse(std::string rates, double convertedRates[10]){
    const char* json = rates.c_str();
    Document document;
    document.Parse(json);

    double pln = this->currencyStringToDouble(document, "pln");
    convertedRates[0]=1/pln;
    /*double currency = atof(document["response"]["data"]["usd"].GetString());
     * NIE, bo USD=1 wedlug rates ktore otrzymujemy
     * USD konwertujemy dzielac przez kurs pln, a reszte walut liczymy nizej
     */
    double currency = athis->currencyStringToDouble(document, "eur");
    convertedRates[1]=pln/currency;
    currency = this->currencyStringToDouble(document, "jpy");
    convertedRates[2]=pln/currency;
    currency = this->currencyStringToDouble(document, "gbp");
    convertedRates[3]=pln/currency;
    currency = this->currencyStringToDouble(document, "czk");
    convertedRates[4]=pln/currency;
    currency = this->currencyStringToDouble(document, "aud");
    convertedRates[5]=pln/currency;
    currency = this->currencyStringToDouble(document, "brl");
    convertedRates[6]=pln/currency;
    currency = this->currencyStringToDouble(document, "dkk");
    convertedRates[7]=pln/currency;
    currency = this->currencyStringToDouble(document, "nok");
    convertedRates[8]=pln/currency;
    currency = this->currencyStringToDouble(document, "rub");
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
        double pln = this->currencyStringToDouble(document, "pln");
        double usd = this->currencyStringToDouble(document, "usd");
        double eur = this->currencyStringToDouble(document, "eur");
        double jpy = this->currencyStringToDouble(document, "jpy");
        double gbp = this->currencyStringToDouble(document, "gbp");
        double czk = this->currencyStringToDouble(document, "czk");
        double aud = this->currencyStringToDouble(document, "aud");
        double brl = this->currencyStringToDouble(document, "brl");
        double dkk = this->currencyStringToDouble(document, "dkk");
        double nok = this->currencyStringToDouble(document, "nok");
        double rub = this->currencyStringToDouble(document, "rub");
        investments.push_back(new Investment(user_login,found_date,name,pln,usd,
                                             eur,jpy,gbp,czk,aud,brl,dkk,nok,rub));
    }

    return investments;
}

double ResponseHandler::currencyStringToDouble(Document document, std::string currency){
    return atof(document["response"]["data"][i][currency.c_str()].GetString());
}
