#include "addinvestmentwindow.h"
#include "ui_addinvestmentwindow.h"

AddInvestmentWindow::AddInvestmentWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddInvestmentWindow)
{
    ui->setupUi(this);
}

AddInvestmentWindow::~AddInvestmentWindow()
{
    delete ui;
}

void AddInvestmentWindow::on_addButton_clicked()
{
    //DODANIE INVESTMENT
}

void AddInvestmentWindow::on_backButton_clicked()
{
    this->close();
}
