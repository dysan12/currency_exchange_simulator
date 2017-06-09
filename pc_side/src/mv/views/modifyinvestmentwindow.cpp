#include "modifyinvestmentwindow.h"
#include "ui_modifyinvestmentwindow.h"

ModifyInvestmentWindow::ModifyInvestmentWindow(QWidget *parent, Investment *inv, InvestmentsModel *invModel) :
    QDialog(parent),
    ui(new Ui::ModifyInvestmentWindow)
{
    this->invModel = invModel;
    this->inv=inv;
    ui->setupUi(this);
    ui->nameField->setText(QString::fromStdString(inv->getName()));
    ui->usdField->setText(QString::number(inv->getUsd()));
    ui->eurField->setText(QString::number(inv->getEur()));
    ui->jpyField->setText(QString::number(inv->getJpy()));
    ui->gbpField->setText(QString::number(inv->getGbp()));
    ui->czkField->setText(QString::number(inv->getCzk()));
    ui->audField->setText(QString::number(inv->getAud()));
    ui->brlField->setText(QString::number(inv->getBrl()));
    ui->dkkField->setText(QString::number(inv->getDkk()));
    ui->nokField->setText(QString::number(inv->getNok()));
    ui->rubField->setText(QString::number(inv->getRub()));
    ui->currentAmount->setText(QString::number(inv->getPln()));

    invModel->getRates();

    ui->usdLabel->setText("USD("+QString::number(invModel->getConvertedRate(0)) +")");
    ui->eurLabel->setText("Euro("+QString::number(invModel->getConvertedRate(1)) +")");
    ui->jpyLabel->setText("Yen("+QString::number(invModel->getConvertedRate(2)) +")");
    ui->gbpLabel->setText("Pound("+QString::number(invModel->getConvertedRate(3)) +")");
    ui->czkLabel->setText("Czech koruna("+QString::number(invModel->getConvertedRate(4)) +")");
    ui->audLabel->setText("Australian dolar("+QString::number(invModel->getConvertedRate(5)) +")");
    ui->brlLabel->setText("Brazilian real("+QString::number(invModel->getConvertedRate(6)) +")");
    ui->dkkLabel->setText("Danish krone("+QString::number(invModel->getConvertedRate(7)) +")");
    ui->nokLabel->setText("Norwegian krone("+QString::number(invModel->getConvertedRate(8)) +")");
    ui->rubLabel->setText("Russian ruble("+QString::number(invModel->getConvertedRate(9)) +")");
}

ModifyInvestmentWindow::~ModifyInvestmentWindow()
{
    delete ui;
}

void ModifyInvestmentWindow::on_backButton_clicked()
{
    this->close();
}

void ModifyInvestmentWindow::on_modifyButton_clicked()
{
    inv->setUsd(std::stod(ui->usdField->text().toStdString()));
    inv->setEur(std::stod(ui->eurField->text().toStdString()));
    inv->setJpy(std::stod(ui->jpyField->text().toStdString()));
    inv->setGbp(std::stod(ui->gbpField->text().toStdString()));
    inv->setCzk(std::stod(ui->czkField->text().toStdString()));
    inv->setAud(std::stod(ui->audField->text().toStdString()));
    inv->setBrl(std::stod(ui->brlField->text().toStdString()));
    inv->setDkk(std::stod(ui->dkkField->text().toStdString()));
    inv->setNok(std::stod(ui->nokField->text().toStdString()));
    inv->setRub(std::stod(ui->rubField->text().toStdString()));
    invModel->modifyInvestment(this->inv);
    this->close();
}
