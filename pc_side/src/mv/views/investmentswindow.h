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
    std::vector <Investment*> investments;    
    InvestmentsModel *invModel;
public:
    explicit InvestmentsWindow(QWidget *parent, UserModel *user);
    ~InvestmentsWindow();

private slots:
    void on_backButton_clicked();

    void on_deleteButton_clicked();

    void on_addButton_clicked();

    void on_modifyButton_clicked();

    void on_invesmentsList_currentIndexChanged(int index);
};

#endif // INVESTMENTSWINDOW_H
