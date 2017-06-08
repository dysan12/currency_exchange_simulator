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

bool InvestmentsModel::addInvestment(){
    return true;
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
