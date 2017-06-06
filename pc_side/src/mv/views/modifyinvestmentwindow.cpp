#include "modifyinvestmentwindow.h"
#include "ui_modifyinvestmentwindow.h"

ModifyInvestmentWindow::ModifyInvestmentWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyInvestmentWindow)
{
    ui->setupUi(this);
}

ModifyInvestmentWindow::~ModifyInvestmentWindow()
{
    delete ui;
}

void ModifyInvestmentWindow::on_backButton_clicked()
{
    this->close();
}
