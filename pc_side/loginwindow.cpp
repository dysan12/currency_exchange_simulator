#include "loginwindow.h"
#include "loginmodel.h"
#include "ui_loginwindow.h"
#include "registerwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_loginButton_clicked()
{
    if(ui->loginField->text()=="" || ui->passwordField->text()=="")
        QMessageBox::information(this, "Empty field", "Both fields must not be empty!");
    else
    {
        LogInModel *mod=new LogInModel(ui->loginField->text(), ui->passwordField->text());
        if(mod->loginSuccessful())
            this->close();
        else
            QMessageBox::information(this, "Bad login/password", "Provided login credentials aren't true!");
    }
}

void LoginWindow::on_registerButton_clicked()
{
    RegisterWindow *reg=new RegisterWindow(this);
    reg->exec();
}
