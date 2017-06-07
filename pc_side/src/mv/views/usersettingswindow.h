#ifndef USERSETTINGSWINDOW_H
#define USERSETTINGSWINDOW_H

#include <QDialog>

namespace Ui {
class UserSettingsWindow;
}

class UserSettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserSettingsWindow(QWidget *parent = 0);
    ~UserSettingsWindow();

private slots:
    void on_backButton_clicked();

    void on_changeButton_clicked();

private:
    Ui::UserSettingsWindow *ui;
};

#endif // USERSETTINGSWINDOW_H
