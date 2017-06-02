#include "registermodel.h"

RegisterModel::RegisterModel(QString login, QString password, QString email, QString name)
{
    this->login=login;
    this->password=password;
    this->email=email;
    this->name=name;
}
bool RegisterModel::registerSuccessful(){
    return true;
}
