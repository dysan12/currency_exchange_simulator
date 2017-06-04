#include "addinvestment.h"
#include "ui_addinvestment.h"

AddInvestment::AddInvestment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddInvestment)
{
    ui->setupUi(this);
}

AddInvestment::~AddInvestment()
{
    delete ui;
}

void AddInvestment::on_addButton_clicked()
{
    //DODANIE INVESTMENT
}

void AddInvestment::on_backButton_clicked()
{
    this->close();
}
