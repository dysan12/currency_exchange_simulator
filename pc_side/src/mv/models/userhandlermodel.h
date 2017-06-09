#ifndef USERHANDLERMODEL_H
#define USERHANDLERMODEL_H

#include<QString>

#include "modelConnection.h"
#include "usermodel.h"
#include "responsehandler.h"

#include "invalidcredentialsexception.h"
#include "datatoolongexception.h"



class UserHandlerModel : public ModelConnection
{
private:
    ResponseHandler *response;

    UserModel * getUserDetails(std::string login, std::string tokenID, std::string password);
    std::string createHash(QString login,QString password,QString realm,QString nonce,QString methodRequest,QString url);

public:
    UserHandlerModel();
    UserModel * verifyUser(QString login, QString password);
    bool registerUser(std::string login, std::string password, std::string email, std::string name = "");
    bool changeUserData(UserModel *user);
};

#endif // USERHANDLERMODEL_H
