#include "stockwindow.h"
#include "ui_stockwindow.h"

StockWindow::StockWindow(QWidget *parent) : QDialog(parent), ui(new Ui::StockWindow)
{   
    ui->setupUi(this);
    ui->textBrowser->setText("1. Currency Exchange allows you to play with virtual money that can be divided to other currencies in infinite possibilities."
                             "\nAs it is not only single-path simulator, you can simulate up to 10 paths for your virtual money. "
                             "\nYou can add, delete and modify any of your investments (paths) anytime."
                             "\n\n2. Each currency has its tendency. Fall tendency means that if you are owner of any amount of this currency, you note loss. "
                             "\nAccordingly, for rise tendency if you are owner of any amount of this currency, you note profit."
                             "\nTendencies are updated daily, so you will be able to see any changes only after rates update."
                             "\n\n3. To add an investment, go to 'User's Investments'. In newly appeared window you can see list of your investments as dropdown menu."
                             "\nIf you have any investment already, you can pick if from the list and modify as you want to, by clicking 'Modify investment' button."
                             "\nTo add new investment, click 'Add new investment' button."
                             "\nAs new window appeared, you can now pick a name of your new investment (to recognize it easily) and pick exact amount of any currency from 10 available."
                             "\nHowever, you cannot pick amounts that are over your global cash available."
                             "\nWhen everything is set, click 'Add Investment' to add new path. It is now shown in list of your investments!");
}

StockWindow::~StockWindow()
{
    delete ui;
}


void StockWindow::on_backButton_clicked()
{
    this->close();
}
