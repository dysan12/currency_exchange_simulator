#ifndef INVESTMENTSMODEL_H
#define INVESTMENTSMODEL_H
#include "windowmodel.h"
#include <QString>


class InvestmentsModel : public WindowModel
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
