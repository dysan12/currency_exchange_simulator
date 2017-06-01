#include "loginmodel.h"

LogInModel::LogInModel(QString login, QString password)
{
    this->login=login;
    this->password=password;
}

bool LogInModel::loginSuccessful(){
    return true;
}
