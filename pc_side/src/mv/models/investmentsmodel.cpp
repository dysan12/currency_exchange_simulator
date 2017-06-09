#include "investmentsmodel.h"

InvestmentsModel::InvestmentsModel()
{
    response = new ResponseHandler();
}

InvestmentsModel::InvestmentsModel(QString invName)
{
    this->invName=invName;//do modyfikacji kontretnej inwestycji
}

int InvestmentsModel::investmentsAmount(){
   return 4;
}

int InvestmentsModel::deleteInvestment(){
    return 1;//USUWANIE W DB
}

void InvestmentsModel::addInvestment(UserModel *user, std::string name){
    std::vector <std::string> keys = {"user", "tokenID", "name"},
            values={user->getName(), "123", name};

    servcon->callRequest("investments", "POST", keys, values);
}

std::vector <Investment*> InvestmentsModel::getInvestments(std::string userLogin)
{
    std::vector <std::string> keys = {"tokenID", "user"},
            values = {"123" /*token->getID()*/,userLogin};

    std::string serverResponse = servcon->callRequest("investments", "GET", keys, values);

    return response->processUserInvestments(serverResponse);
}

void InvestmentsModel::getRates(){
    std::vector <std::string> keys = {},
            values = {};
    response->handleRatesResponse(servcon->callRequest("rates/current", "GET", keys, values),this->convertedRates);
}

double InvestmentsModel::getConvertedRate(int index){
    return convertedRates[index];
}

void InvestmentsModel::modifyInvestment(Investment *inv){
    std::vector <std::string> keys = {"user", "tokenID", "name", "AUD", "BGN", "BRL",
        "CAD", "CHF", "CNY", "CZK", "DKK", "GBP", "HKD", "HRK", "HUF", "IDR", "ILS",
        "INR", "JPY", "KRW", "MXN", "MYR", "NOK", "NZD", "PHP", "RON", "RUB", "SEK",
        "SGD", "THB", "TRY", "USD", "ZAR", "PLN", "EUR"},
            values = {inv->getUserLogin(), "123", inv->getName(), std::to_string(inv->getAud()),
                      "0",std::to_string(inv->getBrl()), "0", "0", "0",
                      std::to_string(inv->getCzk()), std::to_string(inv->getDkk()),
                      std::to_string(inv->getGbp()), "0", "0", "0", "0", "0", "0",
                      std::to_string(inv->getJpy()), "0", "0", "0", std::to_string(inv->getNok()),
                      "0", "0", "0", "0", "0", "0", "0", "0", std::to_string(inv->getUsd()),
                      "0", std::to_string(inv->getPln()), std::to_string(inv->getEur())};

    servcon->callRequest("investments/" + inv->getUserLogin() + "&" + inv->getName(),
                      "PUT", keys, values);
}
