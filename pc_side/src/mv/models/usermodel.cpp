#include "usermodel.h"

UserModel::UserModel(std::string login, std::string email, std::string name, std::string password)
    : login(login), email(email), name(name), password(password)
{
}

void UserModel::setLogin(std::string login)
{
    this->login = login;
}

void UserModel::setEmail(std::string email)
{
    this->email = email;
}

void UserModel::setName(std::string name)
{
    this->name = name;
}

void UserModel::setPassword(std::string password)
{
    this->password = password;
}

std::string UserModel::getLogin()
{
    return this->login;
}

std::string UserModel::getEmail()
{
    return this->email;
}

std::string UserModel::getName()
{
    return this->name;
}

std::string UserModel::getPassword()
{
    return this->password;
}
