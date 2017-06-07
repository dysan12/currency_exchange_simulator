#include "userhandlermodel.h"

UserHandlerModel::UserHandlerModel()
{
}

UserModel * UserHandlerModel::verifyUser(QString login, QString password){

    return new UserModel(login.toStdString(), "mi@on.pl", "Michal", password.toStdString());
    //throw new InvalidCredentialsException();
}

bool UserHandlerModel::registerUser(QString login, QString password, QString email, QString name){
    return true;
}
