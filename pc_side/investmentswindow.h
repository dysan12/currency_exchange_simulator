#ifndef INVESTMENTSWINDOW_H
#define INVESTMENTSWINDOW_H
#include "investmentsmodel.h"

#include <QDialog>

namespace Ui {
class InvestmentsWindow;
}

class InvestmentsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit InvestmentsWindow(QWidget *parent = 0);
    ~InvestmentsWindow();

private slots:
    void on_backButton_clicked();

    void on_deleteButton_clicked();

    void on_addButton_clicked();

    void on_modifyButton_clicked();

private:
    Ui::InvestmentsWindow *ui;
};

#endif // INVESTMENTSWINDOW_H
