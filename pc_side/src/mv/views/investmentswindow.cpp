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
    std::vector <Investment*> investments = model->getInvestments("dysan12" /*user->getLogin()*/);
    Investment *inv = investments[0];
    inv;

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

    int invNo, invAmnt = model->investmentsAmount();

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
