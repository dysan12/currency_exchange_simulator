#include "addinvestmentwindow.h"
#include "ui_addinvestmentwindow.h"

AddInvestmentWindow::AddInvestmentWindow(QWidget *parent, UserModel *user) :
    QDialog(parent),
    ui(new Ui::AddInvestmentWindow),
    user(user)
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
    InvestmentsModel *model = new InvestmentsModel();
    std::string name= ui->nameField->text().toStdString();
    model->addInvestment(user, name);
    this->close();
}

void AddInvestmentWindow::on_backButton_clicked()
{
    this->close();
}
