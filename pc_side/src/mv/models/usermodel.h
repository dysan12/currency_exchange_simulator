#ifndef USERMODEL_H
#define USERMODEL_H

#include<QString>

#include "model.h"
#include "datatoolongexception.h"


class UserModel : public Model
{

public:
    UserModel();
    bool verifyCredentials(QString login, QString password);
    bool registerUser(QString login, QString password, QString email, QString name);
};

#endif // USERMODEL_H
