#ifndef INVESTMENTSMODEL_H
#define INVESTMENTSMODEL_H
#include "model.h"
#include "src/connections/serverconnection.h"
#include "responsehandler.h"
#include "ui_investmentswindow.h"
#include <QString>


class InvestmentsModel : public Model
{
    ServerConnection *servcon;
    ResponseHandler *response;
    QString invName;
    double convertedRates[10];
    double usersWealth[11];
public:
    InvestmentsModel();
    InvestmentsModel(QString invName);

    int investmentsAmount();
    int deleteInvestment();
    bool addInvestment();
    void initializeRates();
    double getConvertedRate(int index);

    friend class ResponseHandler;
};

#endif // INVESTMENTSMODEL_H
