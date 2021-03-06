#ifndef ADDINVESTMENTWINDOW_H
#define ADDINVESTMENTWINDOW_H
#include "investment.h"
#include "investmentsmodel.h"
#include  "usermodel.h"

#include <QDialog>

namespace Ui {
class AddInvestmentWindow;
}

class AddInvestmentWindow : public QDialog
{
    Q_OBJECT
    InvestmentsModel *invMod;
public:
    explicit AddInvestmentWindow(QWidget *parent, InvestmentsModel *invMod);
    ~AddInvestmentWindow();

private slots:
    void on_addButton_clicked();

    void on_backButton_clicked();

private:
    Ui::AddInvestmentWindow *ui;
};

#endif // ADDINVESTMENTWINDOW_H
