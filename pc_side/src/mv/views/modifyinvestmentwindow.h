#ifndef MODIFYINVESTMENTWINDOW_H
#define MODIFYINVESTMENTWINDOW_H
#include "investment.h"
#include "investmentsmodel.h"

#include <QDialog>

namespace Ui {
class ModifyInvestmentWindow;
}

class ModifyInvestmentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyInvestmentWindow(QWidget *parent, Investment *inv, InvestmentsModel *invModel);
    ~ModifyInvestmentWindow();

private slots:
    void on_backButton_clicked();

    void on_modifyButton_clicked();

private:
    Ui::ModifyInvestmentWindow *ui;
    Investment *inv;
    InvestmentsModel *invModel;
};

#endif // MODIFYINVESTMENTWINDOW_H
