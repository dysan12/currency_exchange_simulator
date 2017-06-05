#include "investmentswindow.h"
#include "investmentsmodel.h"
#include "ui_investmentswindow.h"
#include "addinvestment.h"
#include "modifyinvestment.h"

InvestmentsWindow::InvestmentsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InvestmentsWindow)
{
    ui->setupUi(this);

    InvestmentsModel *mod=new InvestmentsModel();
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

    AddInvestment *addNewInv=new AddInvestment();
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

    ModifyInvestment *modifyInv=new ModifyInvestment();
    modifyInv->exec();

    invAmnt=invMod->investmentsAmount();
    for(invNo=0;invNo<invAmnt;invNo++){
        ui->invesmentsList->addItem("Investment no " + QString::number(invNo+1));
    }//
}
