#include "stockwindow.h"
#include "ui_stockwindow.h"

StockWindow::StockWindow(QWidget *parent) : QDialog(parent), ui(new Ui::StockWindow)
{   
    ui->setupUi(this);
}

StockWindow::~StockWindow()
{
    delete ui;
}

