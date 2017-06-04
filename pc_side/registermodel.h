#ifndef REGISTERMODEL_H
#define REGISTERMODEL_H
#include<QString>
#include "windowmodel.h"

class RegisterModel : public WindowModel
{
    QString login, password, email, name;
public:

    RegisterModel(QString, QString, QString, QString);

    bool registerSuccessful();
};

#endif // REGISTERMODEL_H
