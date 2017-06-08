#ifndef INVESTMENTSWINDOW_H
#define INVESTMENTSWINDOW_H

#include <QDialog>

#include "usermodel.h"
#include "investmentsmodel.h"
#include "investment.h"

namespace Ui {
class InvestmentsWindow;
}

class InvestmentsWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::InvestmentsWindow *ui;
    UserModel *user;
public:
    explicit InvestmentsWindow(QWidget *parent, UserModel *user);
    ~InvestmentsWindow();

private slots:
    void on_backButton_clicked();

    void on_deleteButton_clicked();

    void on_addButton_clicked();

    void on_modifyButton_clicked();


};

#endif // INVESTMENTSWINDOW_H
