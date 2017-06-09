#include "addinvestmentwindow.h"
#include "ui_addinvestmentwindow.h"

AddInvestmentWindow::AddInvestmentWindow(QWidget *parent, InvestmentsModel *invMod) :
    QDialog(parent),
    ui(new Ui::AddInvestmentWindow),
    invMod(invMod)
{
    ui->setupUi(this);
    ui->currentAmount->setText("100000");
}

AddInvestmentWindow::~AddInvestmentWindow()
{
    delete ui;
}

void AddInvestmentWindow::on_addButton_clicked()
{
    std::string name= ui->nameField->text().toStdString();
    invMod->addInvestment(name);
    this->close();
}

void AddInvestmentWindow::on_backButton_clicked()
{
    this->close();
}
