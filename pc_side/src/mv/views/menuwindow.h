#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "usermodel.h"

#include "stockwindow.h"
#include "investmentswindow.h"
#include "usersettingswindow.h"
#include "explanationwindow.h"


namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MenuWindow *ui;
    UserModel *user;
public:
    explicit MenuWindow(QWidget *parent, UserModel *user);
    ~MenuWindow();

private slots:
    void on_stockStatusButton_clicked();

    void on_investmentsButton_clicked();

    void on_settingsButton_clicked();

    void on_explanationButton_clicked();

    void on_exitButton_clicked();


};

#endif // MENUWINDOW_H
