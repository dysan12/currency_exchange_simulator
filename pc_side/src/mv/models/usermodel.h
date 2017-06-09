#ifndef USERMODEL_H
#define USERMODEL_H

#include<QString>

#include "token.h"
#include "model.h"


class UserModel : public Model
{
private:
    std::string login,
                email,
                name,
                password;
    Token * token;

public:
    UserModel(std::string login = "", std::string email = "", std::string name = "", std::string password = "");
    void setLogin(std::string login);
    void setEmail(std::string email);
    void setName(std::string name);
    void setPassword(std::string password);
    void setToken(Token *token);
    Token * getToken();
    std::string getLogin();
    std::string getEmail();
    std::string getName();
    std::string getPassword();
};

#endif // USERMODEL_H
