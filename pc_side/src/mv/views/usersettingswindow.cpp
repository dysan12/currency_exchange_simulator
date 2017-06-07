#include "usersettingswindow.h"
#include "ui_usersettingswindow.h"

UserSettingsWindow::UserSettingsWindow(QWidget *parent, UserModel *user) : QDialog(parent),
    ui(new Ui::UserSettingsWindow),
    user(user)
{
    ui->setupUi(this);
    ui->login->setText(QString::fromStdString(user->getLogin()));
    ui->email->setText(QString::fromStdString(user->getEmail()));
    ui->name->setText(QString::fromStdString(user->getName()));
}

UserSettingsWindow::~UserSettingsWindow()
{
    delete ui;
}

void UserSettingsWindow::on_backButton_clicked()
{
    this->close();
}

void UserSettingsWindow::on_changeButton_clicked()
{
    QString oldPwd = ui->passwordOld->text(),
            newPwd = ui->password->text(),
            newPwdConfirmed = ui->passwordConfirmed->text(),
            login = ui->login->text(),
            email = ui->email->text(),
            name = ui->name->text();

    if (login == "" || email == "" || oldPwd == "") {
        QMessageBox::information(this, "Empty field", "Fields Login, Email and Old Password must not be empty!");
        return;
    } else if (newPwd != newPwdConfirmed) {
        QMessageBox::information(this, "Not coherent passwords", "Fields New password and Confirm password must be the same.");
        return;
    } else if (oldPwd != QString::fromStdString(this->user->getPassword())) {
        QMessageBox::information(this, "Old password invalid", "Provided Old password is invalid.");
        return;
    }

    //UserModel clonedUser = this->user;

    //CHANGE USER DATA
}
