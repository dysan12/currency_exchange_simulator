#ifndef REGISTERMODEL_H
#define REGISTERMODEL_H
#include<QString>

class RegisterModel
{
    QString login, password, email, name;
public:
    RegisterModel(QString, QString, QString, QString);
    bool registerSuccessful();
};

#endif // REGISTERMODEL_H
