#ifndef EXPLANATIONWINDOW_H
#define EXPLANATIONWINDOW_H

#include <QDialog>


namespace Ui {
class ExplanationWindow;
}

class ExplanationWindow : public QDialog
{
    Q_OBJECT
public:
    explicit ExplanationWindow(QWidget *parent = 0);
    ~ExplanationWindow();

private slots:

private:
    Ui::ExplanationWindow *ui;
};

#endif // EXPLANATIONWINDOW_H
