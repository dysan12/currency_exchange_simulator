#include "investmentsmodel.h"

InvestmentsModel::InvestmentsModel()
{
    this->initializeRates();
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

void InvestmentsModel::initializeRates(){
    std::string url = "http://slawbit.pl/api-currencyexchange/rates/current";
    response=new ResponseHandler();
    servcon=new ServerConnection();
    response->handleRatesResponse(servcon->callGetRequest(url),this->convertedRates);
}

double InvestmentsModel::getConvertedRate(int index){
    return convertedRates[index];
}
