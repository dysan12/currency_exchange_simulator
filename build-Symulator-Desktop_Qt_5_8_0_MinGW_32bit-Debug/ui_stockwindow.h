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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StockWindow
{
public:
    QPushButton *loginButton;
    QPushButton *registerButton;
    QLabel *loginLabel;
    QLabel *passwordLabel;
    QLineEdit *loginField;
    QLineEdit *passwordField;

    void setupUi(QDialog *StockWindow)
    {
        if (StockWindow->objectName().isEmpty())
            StockWindow->setObjectName(QStringLiteral("StockWindow"));
        StockWindow->resize(284, 303);
        loginButton = new QPushButton(StockWindow);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(140, 160, 80, 21));
        registerButton = new QPushButton(StockWindow);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(140, 240, 80, 21));
        loginLabel = new QLabel(StockWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        loginLabel->setGeometry(QRect(50, 60, 51, 16));
        passwordLabel = new QLabel(StockWindow);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setGeometry(QRect(50, 110, 51, 21));
        loginField = new QLineEdit(StockWindow);
        loginField->setObjectName(QStringLiteral("loginField"));
        loginField->setGeometry(QRect(120, 60, 113, 21));
        passwordField = new QLineEdit(StockWindow);
        passwordField->setObjectName(QStringLiteral("passwordField"));
        passwordField->setGeometry(QRect(120, 110, 113, 21));

        retranslateUi(StockWindow);

        QMetaObject::connectSlotsByName(StockWindow);
    } // setupUi

    void retranslateUi(QDialog *StockWindow)
    {
        StockWindow->setWindowTitle(QApplication::translate("StockWindow", "Dialog", Q_NULLPTR));
        loginButton->setText(QApplication::translate("StockWindow", "Log In", Q_NULLPTR));
        registerButton->setText(QApplication::translate("StockWindow", "Register", Q_NULLPTR));
        loginLabel->setText(QApplication::translate("StockWindow", "Login", Q_NULLPTR));
        passwordLabel->setText(QApplication::translate("StockWindow", "Password", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StockWindow: public Ui_StockWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKWINDOW_H
