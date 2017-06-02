#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "loginwindow.h"

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
