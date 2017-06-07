#ifndef STOCKWINDOW_H
#define STOCKWINDOW_H

#include <QDialog>

namespace Ui {
class StockWindow;
}

class StockWindow : public QDialog
{
    Q_OBJECT
public:
    explicit StockWindow(QWidget *parent = 0);
    ~StockWindow();

private slots:

private:
    Ui::StockWindow *ui;
};

#endif // STOCKWINDOW_H
