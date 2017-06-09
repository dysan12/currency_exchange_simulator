#include "registerwindow.h"
#include "ui_registerwindow.h"

#include "ValuesOccupiedException.h"

RegisterWindow::RegisterWindow(QWidget *parent) : QDialog(parent), ui(new Ui::RegisterWindow)
{
    this->userHandler = new UserHandlerModel();
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_registerButton_clicked()
{
    if (ui->loginField->text() == "" ||
        ui->passwordField->text() == "" ||
        ui->emailField->text() == "") {

        QMessageBox::information(this, "Empty field", "Login, password and email fields must not be empty!");
        return ;
    }

    try {
        this->userHandler->registerUser(
                     ui->loginField->text().toStdString(),
                     ui->passwordField->text().toStdString(),
                     ui->emailField->text().toStdString(),
                     ui->nameField->text().toStdString()
                     );
        QMessageBox::information(this, "Registering successful", "You can now use your new account");
        this->close();
    } catch (DataTooLongException * exception) {
        QMessageBox::information(this, "Too long data", "Provided register credentials ought to be of size :....!");
    } catch(ValuesOccupiedException * exception) {
        QMessageBox::information(this, "Login/email taken", "Provided username or email had been taken.");
    }
}

void RegisterWindow::on_backButton_clicked()
{
    this->close();
}
