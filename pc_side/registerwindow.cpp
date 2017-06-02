#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "registermodel.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_registerButton_clicked()
{
    if(ui->loginField->text()=="" || ui->passwordField->text()=="" || ui->emailField->text()=="")
        QMessageBox::information(this, "Empty field", "Login, password and email fields must not be empty!");
    else
    {
        RegisterModel *mod=new RegisterModel(ui->loginField->text(), ui->passwordField->text(), ui->emailField->text(), ui->nameField->text());
        if(mod->registerSuccessful())
            this->close();
        else
            QMessageBox::information(this, "Bad information combination", "Provided register credentials aren't avaible!");
    }
}

void RegisterWindow::on_backButton_clicked()
{
    this->close();
}
