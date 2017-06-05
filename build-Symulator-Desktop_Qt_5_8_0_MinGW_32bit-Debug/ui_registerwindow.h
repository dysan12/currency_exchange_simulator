/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

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

class Ui_RegisterWindow
{
public:
    QLabel *loginLabel;
    QLabel *passwordLabel;
    QLabel *emailLabel;
    QLabel *nameLabel;
    QLineEdit *loginField;
    QLineEdit *passwordField;
    QLineEdit *emailField;
    QLineEdit *nameField;
    QLabel *infoLabel;
    QPushButton *registerButton;
    QPushButton *backButton;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName(QStringLiteral("RegisterWindow"));
        RegisterWindow->resize(350, 239);
        loginLabel = new QLabel(RegisterWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        loginLabel->setGeometry(QRect(70, 30, 51, 21));
        passwordLabel = new QLabel(RegisterWindow);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setGeometry(QRect(70, 60, 51, 21));
        emailLabel = new QLabel(RegisterWindow);
        emailLabel->setObjectName(QStringLiteral("emailLabel"));
        emailLabel->setGeometry(QRect(70, 90, 51, 21));
        nameLabel = new QLabel(RegisterWindow);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(70, 120, 51, 21));
        loginField = new QLineEdit(RegisterWindow);
        loginField->setObjectName(QStringLiteral("loginField"));
        loginField->setGeometry(QRect(150, 30, 113, 21));
        passwordField = new QLineEdit(RegisterWindow);
        passwordField->setObjectName(QStringLiteral("passwordField"));
        passwordField->setGeometry(QRect(150, 60, 113, 21));
        emailField = new QLineEdit(RegisterWindow);
        emailField->setObjectName(QStringLiteral("emailField"));
        emailField->setGeometry(QRect(150, 90, 113, 21));
        nameField = new QLineEdit(RegisterWindow);
        nameField->setObjectName(QStringLiteral("nameField"));
        nameField->setGeometry(QRect(150, 120, 113, 21));
        infoLabel = new QLabel(RegisterWindow);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));
        infoLabel->setGeometry(QRect(190, 140, 81, 16));
        QFont font;
        font.setPointSize(7);
        infoLabel->setFont(font);
        registerButton = new QPushButton(RegisterWindow);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(170, 170, 80, 21));
        backButton = new QPushButton(RegisterWindow);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(290, 210, 51, 21));

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QApplication::translate("RegisterWindow", "Dialog", Q_NULLPTR));
        loginLabel->setText(QApplication::translate("RegisterWindow", "Login", Q_NULLPTR));
        passwordLabel->setText(QApplication::translate("RegisterWindow", "Password", Q_NULLPTR));
        emailLabel->setText(QApplication::translate("RegisterWindow", "Email", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("RegisterWindow", "Name", Q_NULLPTR));
        infoLabel->setText(QApplication::translate("RegisterWindow", "Name is optional", Q_NULLPTR));
        registerButton->setText(QApplication::translate("RegisterWindow", "Register", Q_NULLPTR));
        backButton->setText(QApplication::translate("RegisterWindow", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
