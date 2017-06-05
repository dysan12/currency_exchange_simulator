#ifndef LOGINMODEL_H
#define LOGINMODEL_H
#include<QString>
#include "model.h"


class LogInModel : public Model
{
    QString login, password;
public:
    LogInModel();
    bool verifyCredentials(QString login, QString password);
};

#endif // LOGINMODEL_H
