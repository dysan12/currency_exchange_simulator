#include "menuwindow.h"
#include "ui_menuwindow.h"


MenuWindow::MenuWindow(QWidget *parent, UserModel *user) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow),
    user(user)
{
    ui->setupUi(this);
    QString greetingTxt = QString::fromStdString("Hello " + this->user->getLogin() + "!");
    ui->greeting->setText(greetingTxt);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_stockStatusButton_clicked()
{
    StockWindow *stockView = new StockWindow();
    this->hide();
    stockView->exec();
    this->show();
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
    ExplanationWindow *explanationView = new ExplanationWindow();
    this->hide();
    explanationView->exec();
    this->show();
}

void MenuWindow::on_exitButton_clicked()
{
    this->close();
}
