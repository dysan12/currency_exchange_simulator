#include "userhandlermodel.h"
#include <QCryptographicHash>
#include "ValuesOccupiedException.h"
#include "token.h"

UserHandlerModel::UserHandlerModel()
{
    this->response = new ResponseHandler();
}

UserModel * UserHandlerModel::verifyUser(QString login, QString password)
{
    QString url = "/api-currencyexchange/login",
            realm = "some_realm",
            nonce = "some_nonce",
            methodRequest = "POST";

    try{
        std::string hash = this->createHash(login,password, realm, nonce, methodRequest, url);

        std::vector <std::string> keys = {"response", "realm", "nonce"},
                values = {hash, realm.toStdString(), nonce.toStdString()};

        std::string serverResponse = servcon->callRequest("login", "POST", keys, values);

        std::string tokenID = response->processTokenId(serverResponse);
        Token *token = new Token(tokenID);

        UserModel *user = this->getUserDetails(login.toStdString(), tokenID, password.toStdString());
        user->setToken(token);

        return user;
    } catch (AccessDeniedException *exception) {
        throw new InvalidCredentialsException();
    }
}


UserModel * UserHandlerModel::getUserDetails(std::string login, std::string tokenID, std::string password)
{
    std::vector <std::string> keys = {"tokenID"},
            values = {tokenID};
    std::string url = "users/" + login;
    std::string serverResponse = servcon->callRequest(url, "GET", keys, values);

    return response->processUserData(serverResponse, password);
}

std::string UserHandlerModel::createHash(QString login,QString password,QString realm,QString nonce,QString methodRequest,QString url)
{
    QString a1 = QCryptographicHash::hash((login + ":" + realm + ":" + password).toUtf8(), QCryptographicHash::Sha256).toHex();
    QString a2 = QCryptographicHash::hash((methodRequest + ":" + url).toUtf8(), QCryptographicHash::Sha256).toHex();
    QString hash = QCryptographicHash::hash((a1 + ":" + nonce + ":" + a2).toUtf8(), QCryptographicHash::Sha256).toHex();

    return hash.toStdString();
}

bool UserHandlerModel::registerUser(std::string login, std::string password, std::string email, std::string name){

    std::vector <std::string> keys = {"login", "password","email", "name"},
            values = {login, password, email, name};

    try{
        std::string serverResponse = servcon->callRequest("users", "POST", keys, values);
        return true;
    } catch (BadRequestException * exception) {
        throw new ValuesOccupiedException();
    }
}
