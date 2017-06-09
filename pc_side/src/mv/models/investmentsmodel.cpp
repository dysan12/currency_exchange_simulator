#include "investmentsmodel.h"

InvestmentsModel::InvestmentsModel(UserModel *user)
{
    response = new ResponseHandler();
    this->user = user;
}

int InvestmentsModel::investmentsAmount(){
   return 4;
}

void InvestmentsModel::deleteInvestment(std::string name){
    Token *token = user->getToken();
    std::string resource = ("investments/" + user->getLogin() + "&" + name);
    std::vector <std::string> keys = {"tokenID"},
            values = {token->getId()};

    servcon->callRequest(resource, "DELETE", keys, values);
}

void InvestmentsModel::addInvestment(std::string name){
    Token *token = user->getToken();
    std::vector <std::string> keys = {"user", "tokenID", "name"},
            values={user->getLogin(), token->getId(), name};

    servcon->callRequest("investments", "POST", keys, values);
}

std::vector <Investment*> InvestmentsModel::getInvestments()
{
    Token *token = user->getToken();
    std::vector <std::string> keys = {"tokenID", "user"},
            values = {token->getId(), user->getLogin()};

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
    Token *token = user->getToken();
    std::vector <std::string> keys = {"user", "tokenID", "name", "AUD", "BGN", "BRL",
        "CAD", "CHF", "CNY", "CZK", "DKK", "GBP", "HKD", "HRK", "HUF", "IDR", "ILS",
        "INR", "JPY", "KRW", "MXN", "MYR", "NOK", "NZD", "PHP", "RON", "RUB", "SEK",
        "SGD", "THB", "TRY", "USD", "ZAR", "PLN", "EUR"},
            values = {inv->getUserLogin(), token->getId(), inv->getName(), std::to_string(inv->getAud()),
                      "0",std::to_string(inv->getBrl()), "0", "0", "0",
                      std::to_string(inv->getCzk()), std::to_string(inv->getDkk()),
                      std::to_string(inv->getGbp()), "0", "0", "0", "0", "0", "0",
                      std::to_string(inv->getJpy()), "0", "0", "0", std::to_string(inv->getNok()),
                      "0", "0", "0", "0", "0", "0", "0", "0", std::to_string(inv->getUsd()),
                      "0", std::to_string(inv->getPln()), std::to_string(inv->getEur())};

    servcon->callRequest("investments/" + inv->getUserLogin() + "&" + inv->getName(),
                      "PUT", keys, values);
}
