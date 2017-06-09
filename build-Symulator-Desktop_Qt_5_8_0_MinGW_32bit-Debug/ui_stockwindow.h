/********************************************************************************
** Form generated from reading UI file 'stockwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKWINDOW_H
#define UI_STOCKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_StockWindow
{
public:
    QPushButton *backButton;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *StockWindow)
    {
        if (StockWindow->objectName().isEmpty())
            StockWindow->setObjectName(QStringLiteral("StockWindow"));
        StockWindow->resize(1130, 616);
        backButton = new QPushButton(StockWindow);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(530, 550, 81, 41));
        textBrowser = new QTextBrowser(StockWindow);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 20, 1091, 521));

        retranslateUi(StockWindow);

        QMetaObject::connectSlotsByName(StockWindow);
    } // setupUi

    void retranslateUi(QDialog *StockWindow)
    {
        StockWindow->setWindowTitle(QApplication::translate("StockWindow", "Dialog", Q_NULLPTR));
        backButton->setText(QApplication::translate("StockWindow", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StockWindow: public Ui_StockWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKWINDOW_H
