#ifndef LOGINMODEL_H
#define LOGINMODEL_H
#include<QString>


class LogInModel
{
    QString login, password;
public:
    LogInModel(QString, QString);
    bool loginSuccessful();
};

#endif // LOGINMODEL_H
