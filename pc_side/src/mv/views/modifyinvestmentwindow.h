#ifndef MODIFYINVESTMENTWINDOW_H
#define MODIFYINVESTMENTWINDOW_H

#include <QDialog>

namespace Ui {
class ModifyInvestmentWindow;
}

class ModifyInvestmentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyInvestmentWindow(QWidget *parent = 0);
    ~ModifyInvestmentWindow();

private slots:
    void on_backButton_clicked();

private:
    Ui::ModifyInvestmentWindow *ui;
};

#endif // MODIFYINVESTMENTWINDOW_H
