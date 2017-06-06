#ifndef ADDINVESTMENTWINDOW_H
#define ADDINVESTMENTWINDOW_H

#include <QDialog>

namespace Ui {
class AddInvestmentWindow;
}

class AddInvestmentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddInvestmentWindow(QWidget *parent = 0);
    ~AddInvestmentWindow();

private slots:
    void on_addButton_clicked();

    void on_backButton_clicked();

private:
    Ui::AddInvestmentWindow *ui;
};

#endif // ADDINVESTMENTWINDOW_H
