#include "explanationwindow.h"
#include "ui_explanationwindow.h"

ExplanationWindow::ExplanationWindow(QWidget *parent) : QDialog(parent), ui(new Ui::ExplanationWindow)
{
    ui->setupUi(this);
}

ExplanationWindow::~ExplanationWindow()
{
    delete ui;
}

void ExplanationWindow::on_backButton_clicked()
{
    this-close();
}
