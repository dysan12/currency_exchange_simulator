#ifndef MODIFYINVESTMENT_H
#define MODIFYINVESTMENT_H

#include <QDialog>

namespace Ui {
class ModifyInvestment;
}

class ModifyInvestment : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyInvestment(QWidget *parent = 0);
    ~ModifyInvestment();

private slots:
    void on_backButton_clicked();

private:
    Ui::ModifyInvestment *ui;
};

#endif // MODIFYINVESTMENT_H
