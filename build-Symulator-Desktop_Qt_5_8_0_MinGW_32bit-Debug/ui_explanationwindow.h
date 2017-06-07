/********************************************************************************
** Form generated from reading UI file 'explanationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPLANATIONWINDOW_H
#define UI_EXPLANATIONWINDOW_H

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

class Ui_ExplanationWindow
{
public:
    QPushButton *loginButton;
    QPushButton *registerButton;
    QLabel *loginLabel;
    QLabel *passwordLabel;
    QLineEdit *loginField;
    QLineEdit *passwordField;

    void setupUi(QDialog *ExplanationWindow)
    {
        if (ExplanationWindow->objectName().isEmpty())
            ExplanationWindow->setObjectName(QStringLiteral("ExplanationWindow"));
        ExplanationWindow->resize(284, 303);
        loginButton = new QPushButton(ExplanationWindow);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(140, 160, 80, 21));
        registerButton = new QPushButton(ExplanationWindow);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(140, 240, 80, 21));
        loginLabel = new QLabel(ExplanationWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        loginLabel->setGeometry(QRect(50, 60, 51, 16));
        passwordLabel = new QLabel(ExplanationWindow);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setGeometry(QRect(50, 110, 51, 21));
        loginField = new QLineEdit(ExplanationWindow);
        loginField->setObjectName(QStringLiteral("loginField"));
        loginField->setGeometry(QRect(120, 60, 113, 21));
        passwordField = new QLineEdit(ExplanationWindow);
        passwordField->setObjectName(QStringLiteral("passwordField"));
        passwordField->setGeometry(QRect(120, 110, 113, 21));

        retranslateUi(ExplanationWindow);

        QMetaObject::connectSlotsByName(ExplanationWindow);
    } // setupUi

    void retranslateUi(QDialog *ExplanationWindow)
    {
        ExplanationWindow->setWindowTitle(QApplication::translate("ExplanationWindow", "Dialog", Q_NULLPTR));
        loginButton->setText(QApplication::translate("ExplanationWindow", "Log In", Q_NULLPTR));
        registerButton->setText(QApplication::translate("ExplanationWindow", "Register", Q_NULLPTR));
        loginLabel->setText(QApplication::translate("ExplanationWindow", "Login", Q_NULLPTR));
        passwordLabel->setText(QApplication::translate("ExplanationWindow", "Password", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExplanationWindow: public Ui_ExplanationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPLANATIONWINDOW_H
