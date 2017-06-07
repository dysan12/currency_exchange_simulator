#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QMessageBox>

#include "registerwindow.h"
#include "menuwindow.h"

#include "usermodel.h"
#include "userhandlermodel.h"

#include "invalidcredentialsexception.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT
private:
    UserHandlerModel *userHandler;
    void generateMenu(UserModel *user);

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_loginButton_clicked();

    void on_registerButton_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
