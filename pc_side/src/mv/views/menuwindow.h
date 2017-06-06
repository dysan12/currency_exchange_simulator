#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtDebug>

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = 0);
    ~MenuWindow();

private slots:
    void on_stockStatusButton_clicked();

    void on_investmentsButton_clicked();

    void on_settingsButton_clicked();

    void on_explanationButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::MenuWindow *ui;

};

#endif // MENUWINDOW_H
