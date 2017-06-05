#include "usersettings.h"
#include "ui_usersettings.h"

UserSettings::UserSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserSettings)
{
    ui->setupUi(this);
}

UserSettings::~UserSettings()
{
    delete ui;
}

void UserSettings::on_backButton_clicked()
{
    this->close();
}

void UserSettings::on_changeButton_clicked()
{
    //NOWE DANE, ZMIANA (JESLI PUSTE POLA TO BRAK ZMIANY)
}
