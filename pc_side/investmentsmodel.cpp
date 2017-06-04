#include "investmentsmodel.h"
#include "windowmodel.h"

InvestmentsModel::InvestmentsModel()
{

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
