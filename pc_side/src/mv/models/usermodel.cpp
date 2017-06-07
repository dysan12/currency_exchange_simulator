#include "usermodel.h"

UserModel::UserModel(std::string login, std::string email, std::string name)
    : login(login), email(email), name(name)
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
