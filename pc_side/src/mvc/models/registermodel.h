#ifndef REGISTERMODEL_H
#define REGISTERMODEL_H

#include<QString>

#include "model.h"
#include "datatoolongexception.h"

class RegisterModel : public Model
{

public:
    RegisterModel();
    bool registerUser(QString login, QString password, QString email, QString name);
};

#endif // REGISTERMODEL_H
