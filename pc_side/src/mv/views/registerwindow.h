#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include <QMessageBox>

#include "usermodel.h"
#include "datatoolongexception.h"

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT
private:
    UserModel *userModel;
public:
    explicit RegisterWindow(QWidget *parent = 0);
    ~RegisterWindow();

private slots:
    void on_registerButton_clicked();

    void on_backButton_clicked();

private:
    Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
