#include "usersettingswindow.h"
#include "ui_usersettingswindow.h"

UserSettingsWindow::UserSettingsWindow(QWidget *parent) : QDialog(parent), ui(new Ui::UserSettingsWindow)
{
    ui->setupUi(this);
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
    //NOWE DANE, ZMIANA (JESLI PUSTE POLA TO BRAK ZMIANY)
}
