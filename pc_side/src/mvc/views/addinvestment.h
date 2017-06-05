#ifndef ADDINVESTMENT_H
#define ADDINVESTMENT_H

#include <QDialog>

namespace Ui {
class AddInvestment;
}

class AddInvestment : public QDialog
{
    Q_OBJECT

public:
    explicit AddInvestment(QWidget *parent = 0);
    ~AddInvestment();

private slots:
    void on_addButton_clicked();

    void on_backButton_clicked();

private:
    Ui::AddInvestment *ui;
};

#endif // ADDINVESTMENT_H
