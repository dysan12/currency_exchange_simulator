#include "modifyinvestment.h"
#include "ui_modifyinvestment.h"

ModifyInvestment::ModifyInvestment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyInvestment)
{
    ui->setupUi(this);
}

ModifyInvestment::~ModifyInvestment()
{
    delete ui;
}

void ModifyInvestment::on_backButton_clicked()
{
    this->close();
}
