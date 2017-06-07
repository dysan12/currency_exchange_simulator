#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) : QDialog(parent), ui(new Ui::LoginWindow)
{
    this->userHandler = new UserHandlerModel();

    ui->setupUi(this);
    ui->loginField->setFocus();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    QString login = ui->loginField->text(),
            password = ui->passwordField->text();

    if (login == "" || password == "") {
        QMessageBox::information(this, "Empty field", "Both fields must not be empty!");
        return;
    }

    try {
        UserModel *user = this->userHandler->verifyUser(login, password);
        this->generateMenu(user);
        this->close();
    } catch (InvalidCredentialsException *exception) {
        QMessageBox::information(this, "Bad information provided", "Provided login credentials aren't true!");
    }
}

void LoginWindow::on_registerButton_clicked()
{
    RegisterWindow *reg = new RegisterWindow(this);
    reg->exec();
}

void LoginWindow::generateMenu(UserModel *user)
{
    MenuWindow * menuView = new MenuWindow(0, user);
    menuView->show();
}
