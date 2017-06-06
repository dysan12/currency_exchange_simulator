#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "loginwindow.h"
#include "investmentswindow.h"
#include "usersettingswindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_stockStatusButton_clicked()
{


}

void MenuWindow::on_investmentsButton_clicked()
{
    InvestmentsWindow *investmentsView = new InvestmentsWindow();
    this->hide();
    investmentsView->exec();
    this->show();
}

void MenuWindow::on_settingsButton_clicked()
{
    UserSettingsWindow *userSettingsView = new UserSettingsWindow();
    this->hide();
    userSettingsView->exec();
    this->show();
}

void MenuWindow::on_explanationButton_clicked()
{

}

void MenuWindow::on_exitButton_clicked()
{
    this->close();
}
