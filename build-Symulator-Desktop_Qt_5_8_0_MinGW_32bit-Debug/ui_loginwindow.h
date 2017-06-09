/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

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

class Ui_LoginWindow
{
public:
    QPushButton *loginButton;
    QPushButton *registerButton;
    QLabel *loginLabel;
    QLabel *passwordLabel;
    QLineEdit *loginField;
    QLineEdit *passwordField;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(284, 303);
        loginButton = new QPushButton(LoginWindow);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(140, 160, 80, 21));
        registerButton = new QPushButton(LoginWindow);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(140, 240, 80, 21));
        loginLabel = new QLabel(LoginWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        loginLabel->setGeometry(QRect(50, 60, 51, 16));
        passwordLabel = new QLabel(LoginWindow);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setGeometry(QRect(50, 110, 51, 21));
        loginField = new QLineEdit(LoginWindow);
        loginField->setObjectName(QStringLiteral("loginField"));
        loginField->setGeometry(QRect(120, 60, 113, 21));
        passwordField = new QLineEdit(LoginWindow);
        passwordField->setObjectName(QStringLiteral("passwordField"));
        passwordField->setGeometry(QRect(120, 110, 113, 21));
        passwordField->setEchoMode(QLineEdit::Password);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "Dialog", Q_NULLPTR));
        loginButton->setText(QApplication::translate("LoginWindow", "Log In", Q_NULLPTR));
        registerButton->setText(QApplication::translate("LoginWindow", "Register", Q_NULLPTR));
        loginLabel->setText(QApplication::translate("LoginWindow", "Login", Q_NULLPTR));
        passwordLabel->setText(QApplication::translate("LoginWindow", "Password", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
