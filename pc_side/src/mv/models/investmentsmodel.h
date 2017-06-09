#ifndef INVESTMENTSMODEL_H
#define INVESTMENTSMODEL_H

#include "modelConnection.h"
#include "serverconnection.h"
#include "responsehandler.h"
#include "investment.h"
#include "usermodel.h"
#include <QString>


class InvestmentsModel : public ModelConnection
{
    ServerConnection *servcon;
    ResponseHandler *response;
    QString invName;
    double convertedRates[10];
    double usersWealth[11];
public:
    InvestmentsModel();
    InvestmentsModel(QString invName);
    std::vector <Investment*> getInvestments(std::string userLogin);

    int investmentsAmount();
    int deleteInvestment();
    void addInvestment(UserModel *user, std::string name);
    void getRates();
    double getConvertedRate(int index);
    void modifyInvestment(Investment *inv);

    friend class ResponseHandler;
};

#endif // INVESTMENTSMODEL_H
