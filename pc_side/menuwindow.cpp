#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "loginwindow.h"
#include "investmentswindow.h"
#include "usersettings.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    LoginWindow *login=new LoginWindow();
    login->exec();
    ui->setupUi(this);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_exitButton_clicked()
{
    this->close();
}

void MenuWindow::on_investmentsButton_clicked()
{
    InvestmentsWindow *inv=new InvestmentsWindow();
    this->hide();
    inv->exec();
    this->show();
}

void MenuWindow::on_settingsButton_clicked()
{
    UserSettings *usr=new UserSettings();
    this->hide();
    usr->exec();
    this->show();
}
