#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) : QDialog(parent), ui(new Ui::LoginWindow)
{
    this->userModel = new UserModel();

    ui->setupUi(this);
    ui->loginField->setFocus();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    bool loggedIn = false;

    if (ui->loginField->text() == "" || ui->passwordField->text() == "") {
        QMessageBox::information(this, "Empty field", "Both fields must not be empty!");
        return;
    }

    loggedIn = this->userModel->verifyCredentials(ui->loginField->text(), ui->passwordField->text());

    if (loggedIn) {
        this->generateMenu();
        this->close();
    } else {
        QMessageBox::information(this, "Bad information provided", "Provided login credentials aren't true!");
    }
}

void LoginWindow::on_registerButton_clicked()
{
    RegisterWindow *reg = new RegisterWindow(this);
    reg->exec();
}

void LoginWindow::generateMenu()
{
    MenuWindow * menuView = new MenuWindow();
    menuView->show();
}
