#include "modifyinvestmentwindow.h"
#include "ui_modifyinvestmentwindow.h"

ModifyInvestmentWindow::ModifyInvestmentWindow(QWidget *parent, Investment *inv) :
    QDialog(parent),
    ui(new Ui::ModifyInvestmentWindow)
{
    ui->setupUi(this);
    ui->usdAmount->setText(inv->getUsd());
    ui->eurAmount->setText(inv->getEur());
    ui->jpyAmount->setText(inv->getJpy());
    ui->gbpAmount->setText(inv->getGbp());
    ui->czkAmount->setText(inv->getCzk());
    ui->audAmount->setText(inv->getAud());
    ui->brlAmount->setText(inv->getBrl());
    ui->dkkAmount->setText(inv->getDkk());
    ui->nokAmount->setText(inv->getNok());
    ui->rubAmount->setText(inv->getRub());
    ui->plnAmount->setText(inv->getPln());

    InvestmentsModel *model = new InvestmentsModel();
    model->getRates();

    ui->usdLabel->setText("USD("+QString::number(model->getConvertedRate(0)) +")");
    ui->eurLabel->setText("Euro("+QString::number(model->getConvertedRate(1)) +")");
    ui->jpyLabel->setText("Yen("+QString::number(model->getConvertedRate(2)) +")");
    ui->gbpLabel->setText("Pound("+QString::number(model->getConvertedRate(3)) +")");
    ui->czkLabel->setText("Czech koruna("+QString::number(model->getConvertedRate(4)) +")");
    ui->audLabel->setText("Australian dolar("+QString::number(model->getConvertedRate(5)) +")");
    ui->brlLabel->setText("Brazilian real("+QString::number(model->getConvertedRate(6)) +")");
    ui->dkkLabel->setText("Danish krone("+QString::number(model->getConvertedRate(7)) +")");
    ui->nokLabel->setText("Norwegian krone("+QString::number(model->getConvertedRate(8)) +")");
    ui->rubLabel->setText("Russian ruble("+QString::number(model->getConvertedRate(9)) +")");
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

}
