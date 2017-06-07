#ifndef USERHANDLERMODEL_H
#define USERHANDLERMODEL_H

#include<QString>

#include "model.h"
#include "usermodel.h"

#include "invalidcredentialsexception.h"
#include "datatoolongexception.h"


class UserHandlerModel : public Model
{

public:
    UserHandlerModel();
    UserModel * verifyUser(QString login, QString password);
    bool registerUser(QString login, QString password, QString email, QString name);
    bool changeUserData(UserModel *user);
};

#endif // USERHANDLERMODEL_H
