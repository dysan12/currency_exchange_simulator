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

    InvestmentsModel *model = new InvestmentsModel();
    model->getRates();
    /* std::vector <Investment*> investments; znajduje sie w klasie investmentswindow.h */
    this->investments = model->getInvestments("dysan12" /*user->getLogin()*/);
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
    InvestmentsModel *model=new InvestmentsModel();
    model->deleteInvestment(user, ui->invesmentsList->currentText().toStdString());

    this->investments = model->getInvestments("dysan12" /*user->getLogin()*/);
    for(int index = 0;index < investments.size();index++)
        ui->invesmentsList->removeItem(index);

    Investment *inv;
    for(int index = 0; index < investments.size(); index++){
        inv = investments[index];
        ui->invesmentsList->addItem(QString::fromStdString(inv->getName()));
    }
}

void InvestmentsWindow::on_addButton_clicked()
{
    AddInvestmentWindow *addNewInv = new AddInvestmentWindow(0, user);
    addNewInv->exec();

    InvestmentsModel *model = new InvestmentsModel();
    this->investments = model->getInvestments("dysan12" /*user->getLogin()*/);
    for(int index = 0;index < investments.size();index++)
        ui->invesmentsList->removeItem(index);
    Investment *inv;

    for(int index = 0; index < investments.size(); index++){
        inv = investments[index];
        ui->invesmentsList->addItem(QString::fromStdString(inv->getName()));
    }
}

void InvestmentsWindow::on_modifyButton_clicked()
{
    Investment *inv = investments[ui->invesmentsList->currentIndex()];
    ModifyInvestmentWindow *modifyInv = new ModifyInvestmentWindow(0, inv);
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
