#ifndef INVESTMENTSMODEL_H
#define INVESTMENTSMODEL_H
#include "model.h"
#include <QString>


class InvestmentsModel : public Model
{
    QString invName;
public:
    InvestmentsModel();
    InvestmentsModel(QString invName);

    int investmentsAmount();

    int deleteInvestment();

    bool addInvestment();
};

#endif // INVESTMENTSMODEL_H
