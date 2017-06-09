#include "investmentswindow.h"
#include "investmentsmodel.h"
#include "ui_investmentswindow.h"
#include "addinvestmentwindow.h"
#include "modifyinvestmentwindow.h"

InvestmentsWindow::InvestmentsWindow(QWidget *parent, UserModel *user) :
    QDialog(parent),
    ui(new Ui::InvestmentsWindow),
    user(user)
{
    ui->setupUi(this);

    invModel = new InvestmentsModel(user);
    invModel->getRates();
    /* std::vector <Investment*> investments; znajduje sie w klasie investmentswindow.h */
    this->investments = invModel->getInvestments();
    Investment *inv;
    for(int index = 0; index < investments.size(); index++){
        inv = investments[index];
        ui->invesmentsList->addItem(QString::fromStdString(inv->getName()));
    }
    inv = investments[0];
    ui->usdAmount->setText(QString::number(inv->getUsd()));
    ui->eurAmount->setText(QString::number(inv->getEur()));
    ui->jpyAmount->setText(QString::number(inv->getJpy()));
    ui->gbpAmount->setText(QString::number(inv->getGbp()));
    ui->czkAmount->setText(QString::number(inv->getCzk()));
    ui->audAmount->setText(QString::number(inv->getAud()));
    ui->brlAmount->setText(QString::number(inv->getBrl()));
    ui->dkkAmount->setText(QString::number(inv->getDkk()));
    ui->nokAmount->setText(QString::number(inv->getNok()));
    ui->rubAmount->setText(QString::number(inv->getRub()));
    ui->plnAmount->setText(QString::number(inv->getPln()));

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

InvestmentsWindow::~InvestmentsWindow()
{
    delete ui;
}

void InvestmentsWindow::on_backButton_clicked()
{
    this->close();
}

void InvestmentsWindow::on_deleteButton_clicked()
{
    this->investments = invModel->getInvestments();
    std::string nameToDelete = ui->invesmentsList->currentText().toStdString();
    int i = 0;
    for(int index = 0;i < investments.size(); i++){
        ui->invesmentsList->removeItem(index);
    }

    invModel->deleteInvestment(nameToDelete);

    this->investments = invModel->getInvestments();

    Investment *inv;
    for(unsigned int index = 0; index < investments.size(); index++){
        inv = investments[index];
        ui->invesmentsList->addItem(QString::fromStdString(inv->getName()));
    }
}

void InvestmentsWindow::on_addButton_clicked()
{
    this->investments = invModel->getInvestments();
    int i = 0;
    for(int index = 0; i < investments.size(); i++){
        ui->invesmentsList->removeItem(index);
    }

    AddInvestmentWindow *addNewInv = new AddInvestmentWindow(0, invModel);
    addNewInv->exec();

    this->investments = invModel->getInvestments();

    Investment *inv;

    for(unsigned int index = 0; index < investments.size(); index++){
        inv = investments[index];
        ui->invesmentsList->addItem(QString::fromStdString(inv->getName()));
    }
}

void InvestmentsWindow::on_modifyButton_clicked()
{
    Investment *inv = investments[ui->invesmentsList->currentIndex()];
    ModifyInvestmentWindow *modifyInv = new ModifyInvestmentWindow(0, inv, invModel);
    modifyInv->exec();
    ui->usdAmount->setText(QString::number(inv->getUsd()));
    ui->eurAmount->setText(QString::number(inv->getEur()));
    ui->jpyAmount->setText(QString::number(inv->getJpy()));
    ui->gbpAmount->setText(QString::number(inv->getGbp()));
    ui->czkAmount->setText(QString::number(inv->getCzk()));
    ui->audAmount->setText(QString::number(inv->getAud()));
    ui->brlAmount->setText(QString::number(inv->getBrl()));
    ui->dkkAmount->setText(QString::number(inv->getDkk()));
    ui->nokAmount->setText(QString::number(inv->getNok()));
    ui->rubAmount->setText(QString::number(inv->getRub()));
    ui->plnAmount->setText(QString::number(inv->getPln()));
}

void InvestmentsWindow::on_invesmentsList_currentIndexChanged(int index)//zmiana investycji w oknie
{
    Investment *inv = investments[index];
    ui->usdAmount->setText(QString::number(inv->getUsd()));
    ui->eurAmount->setText(QString::number(inv->getEur()));
    ui->jpyAmount->setText(QString::number(inv->getJpy()));
    ui->gbpAmount->setText(QString::number(inv->getGbp()));
    ui->czkAmount->setText(QString::number(inv->getCzk()));
    ui->audAmount->setText(QString::number(inv->getAud()));
    ui->brlAmount->setText(QString::number(inv->getBrl()));
    ui->dkkAmount->setText(QString::number(inv->getDkk()));
    ui->nokAmount->setText(QString::number(inv->getNok()));
    ui->rubAmount->setText(QString::number(inv->getRub()));
    ui->plnAmount->setText(QString::number(inv->getPln()));
}
