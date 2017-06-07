#include "investmentswindow.h"
#include "investmentsmodel.h"
#include "ui_investmentswindow.h"
#include "addinvestmentwindow.h"
#include "modifyinvestmentwindow.h"

InvestmentsWindow::InvestmentsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InvestmentsWindow)
{
    ui->setupUi(this);

    InvestmentsModel *mod=new InvestmentsModel();
    ui->usdLabel->setText("USD("+QString::number(mod->getConvertedRate(0)) +")");
    ui->eurLabel->setText("Euro("+QString::number(mod->getConvertedRate(1)) +")");
    ui->jpyLabel->setText("Yen("+QString::number(mod->getConvertedRate(2)) +")");
    ui->gbpLabel->setText("Pound("+QString::number(mod->getConvertedRate(3)) +")");
    ui->czkLabel->setText("Czech koruna("+QString::number(mod->getConvertedRate(4)) +")");
    ui->audLabel->setText("Australian dolar("+QString::number(mod->getConvertedRate(5)) +")");
    ui->brlLabel->setText("Brazilian real("+QString::number(mod->getConvertedRate(6)) +")");
    ui->dkkLabel->setText("Danish krone("+QString::number(mod->getConvertedRate(7)) +")");
    ui->nokLabel->setText("Norwegian krone("+QString::number(mod->getConvertedRate(8)) +")");
    ui->rubLabel->setText("Russian ruble("+QString::number(mod->getConvertedRate(9)) +")");

    int invNo, invAmnt=mod->investmentsAmount();

    for(invNo=0;invNo<invAmnt;invNo++){//
        ui->invesmentsList->addItem("Investment no " + QString::number(invNo+1));
    }//
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
    InvestmentsModel *invMod=new InvestmentsModel();
    int i=invMod->deleteInvestment();
    ui->invesmentsList->removeItem(i);
}

void InvestmentsWindow::on_addButton_clicked()
{
    InvestmentsModel *invMod=new InvestmentsModel();
    int invNo, invAmnt=invMod->investmentsAmount();
    for(invNo=0;invNo!=invAmnt;invAmnt--){//
        ui->invesmentsList->removeItem(0);
    }

    AddInvestmentWindow *addNewInv=new AddInvestmentWindow();
    addNewInv->exec();

    invAmnt=invMod->investmentsAmount();
    for(invNo=0;invNo<invAmnt;invNo++){
        ui->invesmentsList->addItem("Investment no " + QString::number(invNo+1));
    }//
}

void InvestmentsWindow::on_modifyButton_clicked()
{
    InvestmentsModel *invMod=new InvestmentsModel(ui->invesmentsList->currentText());
    int invNo, invAmnt=invMod->investmentsAmount();
    for(invNo=0;invNo!=invAmnt;invAmnt--){//
        ui->invesmentsList->removeItem(0);
    }

    ModifyInvestmentWindow *modifyInv=new ModifyInvestmentWindow();
    modifyInv->exec();

    invAmnt=invMod->investmentsAmount();
    for(invNo=0;invNo<invAmnt;invNo++){
        ui->invesmentsList->addItem("Investment no " + QString::number(invNo+1));
    }//
}
