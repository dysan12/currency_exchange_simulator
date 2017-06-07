#ifndef USERMODEL_H
#define USERMODEL_H

#include<QString>

#include "model.h"


class UserModel : public Model
{
private:
    std::string login,
                email,
                name;
public:
    UserModel(std::string login = "", std::string email = "", std::string name = "");
    void setLogin(std::string login);
    void setEmail(std::string email);
    void setName(std::string name);
    std::string getLogin();
    std::string getEmail();
    std::string getName();
};

#endif // USERMODEL_H
