#ifndef USERSETTINGSWINDOW_H
#define USERSETTINGSWINDOW_H

#include <QDialog>
#include <QMessageBox>

#include "usermodel.h"

namespace Ui {
class UserSettingsWindow;
}

class UserSettingsWindow : public QDialog
{
    Q_OBJECT

private:
    Ui::UserSettingsWindow *ui;
    UserModel *user;

public:
    explicit UserSettingsWindow(QWidget *parent, UserModel *user);
    ~UserSettingsWindow();

private slots:
    void on_backButton_clicked();

    void on_changeButton_clicked();

};

#endif // USERSETTINGSWINDOW_H
