#ifndef LOGINMODEL_H
#define LOGINMODEL_H
#include<QString>
#include "windowmodel.h"


class LogInModel : public WindowModel
{
    QString login, password;
public:

    LogInModel(QString, QString);

    bool loginSuccessful();
};

#endif // LOGINMODEL_H
