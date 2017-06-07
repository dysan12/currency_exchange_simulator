/********************************************************************************
** Form generated from reading UI file 'usersettingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSETTINGSWINDOW_H
#define UI_USERSETTINGSWINDOW_H

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

class Ui_UserSettingsWindow
{
public:
    QLineEdit *password;
    QLineEdit *email;
    QLabel *loginLabel;
    QLabel *loginLabel_2;
    QLabel *loginLabel_3;
    QLabel *loginLabel_4;
    QLineEdit *name;
    QPushButton *changeButton;
    QPushButton *backButton;
    QLabel *loginLabel_5;
    QLineEdit *passwordConfirmed;
    QLineEdit *passwordOld;
    QLabel *loginLabel_6;
    QLineEdit *login;

    void setupUi(QDialog *UserSettingsWindow)
    {
        if (UserSettingsWindow->objectName().isEmpty())
            UserSettingsWindow->setObjectName(QStringLiteral("UserSettingsWindow"));
        UserSettingsWindow->resize(336, 399);
        password = new QLineEdit(UserSettingsWindow);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(160, 140, 113, 21));
        password->setEchoMode(QLineEdit::Password);
        email = new QLineEdit(UserSettingsWindow);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(160, 240, 113, 21));
        loginLabel = new QLabel(UserSettingsWindow);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        loginLabel->setGeometry(QRect(70, 40, 91, 16));
        loginLabel_2 = new QLabel(UserSettingsWindow);
        loginLabel_2->setObjectName(QStringLiteral("loginLabel_2"));
        loginLabel_2->setGeometry(QRect(70, 140, 91, 16));
        loginLabel_3 = new QLabel(UserSettingsWindow);
        loginLabel_3->setObjectName(QStringLiteral("loginLabel_3"));
        loginLabel_3->setGeometry(QRect(70, 240, 91, 16));
        loginLabel_4 = new QLabel(UserSettingsWindow);
        loginLabel_4->setObjectName(QStringLiteral("loginLabel_4"));
        loginLabel_4->setGeometry(QRect(70, 290, 91, 16));
        name = new QLineEdit(UserSettingsWindow);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(160, 290, 113, 21));
        changeButton = new QPushButton(UserSettingsWindow);
        changeButton->setObjectName(QStringLiteral("changeButton"));
        changeButton->setGeometry(QRect(90, 340, 141, 41));
        backButton = new QPushButton(UserSettingsWindow);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(240, 340, 81, 41));
        loginLabel_5 = new QLabel(UserSettingsWindow);
        loginLabel_5->setObjectName(QStringLiteral("loginLabel_5"));
        loginLabel_5->setGeometry(QRect(70, 190, 91, 16));
        passwordConfirmed = new QLineEdit(UserSettingsWindow);
        passwordConfirmed->setObjectName(QStringLiteral("passwordConfirmed"));
        passwordConfirmed->setGeometry(QRect(160, 190, 113, 21));
        passwordConfirmed->setEchoMode(QLineEdit::Password);
        passwordOld = new QLineEdit(UserSettingsWindow);
        passwordOld->setObjectName(QStringLiteral("passwordOld"));
        passwordOld->setGeometry(QRect(160, 90, 113, 21));
        passwordOld->setEchoMode(QLineEdit::Password);
        loginLabel_6 = new QLabel(UserSettingsWindow);
        loginLabel_6->setObjectName(QStringLiteral("loginLabel_6"));
        loginLabel_6->setGeometry(QRect(70, 90, 91, 16));
        login = new QLineEdit(UserSettingsWindow);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(160, 40, 113, 21));
        password->raise();
        email->raise();
        loginLabel->raise();
        loginLabel_2->raise();
        loginLabel_3->raise();
        loginLabel_4->raise();
        name->raise();
        changeButton->raise();
        backButton->raise();
        loginLabel_5->raise();
        passwordConfirmed->raise();
        login->raise();
        passwordOld->raise();
        loginLabel_6->raise();

        retranslateUi(UserSettingsWindow);

        QMetaObject::connectSlotsByName(UserSettingsWindow);
    } // setupUi

    void retranslateUi(QDialog *UserSettingsWindow)
    {
        UserSettingsWindow->setWindowTitle(QApplication::translate("UserSettingsWindow", "Dialog", Q_NULLPTR));
        loginLabel->setText(QApplication::translate("UserSettingsWindow", "Llogin", Q_NULLPTR));
        loginLabel_2->setText(QApplication::translate("UserSettingsWindow", "New password", Q_NULLPTR));
        loginLabel_3->setText(QApplication::translate("UserSettingsWindow", "Email", Q_NULLPTR));
        loginLabel_4->setText(QApplication::translate("UserSettingsWindow", "Name", Q_NULLPTR));
        changeButton->setText(QApplication::translate("UserSettingsWindow", "Change User's Data", Q_NULLPTR));
        backButton->setText(QApplication::translate("UserSettingsWindow", "Back", Q_NULLPTR));
        loginLabel_5->setText(QApplication::translate("UserSettingsWindow", "Confirm password", Q_NULLPTR));
        passwordConfirmed->setText(QString());
        loginLabel_6->setText(QApplication::translate("UserSettingsWindow", "Old password", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserSettingsWindow: public Ui_UserSettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSETTINGSWINDOW_H
