#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent) : QDialog(parent), ui(new Ui::RegisterWindow)
{
    this->userModel = new UserModel();
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
        this->userModel->registerUser(
                     ui->loginField->text(),
                     ui->passwordField->text(),
                     ui->emailField->text(),
                     ui->nameField->text()
                     );
        QMessageBox::information(this, "Registering successful", "You can now use your new account");
        this->close();
    } catch (DataTooLongException exception) {
        QMessageBox::information(this, "Too long data", "Provided register credentials ought to be of size :....!");
    }
}

void RegisterWindow::on_backButton_clicked()
{
    this->close();
}
