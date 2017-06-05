/********************************************************************************
** Form generated from reading UI file 'usersettings.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSETTINGS_H
#define UI_USERSETTINGS_H

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

class Ui_UserSettings
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *loginLabel;
    QLabel *loginLabel_2;
    QLabel *loginLabel_3;
    QLabel *loginLabel_4;
    QLineEdit *lineEdit_4;
    QLabel *label;
    QPushButton *changeButton;
    QPushButton *backButton;

    void setupUi(QDialog *UserSettings)
    {
        if (UserSettings->objectName().isEmpty())
            UserSettings->setObjectName(QStringLiteral("UserSettings"));
        UserSettings->resize(336, 399);
        lineEdit = new QLineEdit(UserSettings);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(160, 60, 113, 21));
        lineEdit_2 = new QLineEdit(UserSettings);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(160, 110, 113, 21));
        lineEdit_3 = new QLineEdit(UserSettings);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(160, 160, 113, 21));
        loginLabel = new QLabel(UserSettings);
        loginLabel->setObjectName(QStringLiteral("loginLabel"));
        loginLabel->setGeometry(QRect(70, 60, 91, 16));
        loginLabel_2 = new QLabel(UserSettings);
        loginLabel_2->setObjectName(QStringLiteral("loginLabel_2"));
        loginLabel_2->setGeometry(QRect(70, 110, 91, 16));
        loginLabel_3 = new QLabel(UserSettings);
        loginLabel_3->setObjectName(QStringLiteral("loginLabel_3"));
        loginLabel_3->setGeometry(QRect(70, 160, 91, 16));
        loginLabel_4 = new QLabel(UserSettings);
        loginLabel_4->setObjectName(QStringLiteral("loginLabel_4"));
        loginLabel_4->setGeometry(QRect(70, 210, 91, 16));
        lineEdit_4 = new QLineEdit(UserSettings);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(160, 210, 113, 21));
        label = new QLabel(UserSettings);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 250, 181, 20));
        QFont font;
        font.setPointSize(7);
        label->setFont(font);
        changeButton = new QPushButton(UserSettings);
        changeButton->setObjectName(QStringLiteral("changeButton"));
        changeButton->setGeometry(QRect(100, 290, 141, 41));
        backButton = new QPushButton(UserSettings);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(240, 340, 81, 41));

        retranslateUi(UserSettings);

        QMetaObject::connectSlotsByName(UserSettings);
    } // setupUi

    void retranslateUi(QDialog *UserSettings)
    {
        UserSettings->setWindowTitle(QApplication::translate("UserSettings", "Dialog", Q_NULLPTR));
        loginLabel->setText(QApplication::translate("UserSettings", "New login", Q_NULLPTR));
        loginLabel_2->setText(QApplication::translate("UserSettings", "New password", Q_NULLPTR));
        loginLabel_3->setText(QApplication::translate("UserSettings", "New email", Q_NULLPTR));
        loginLabel_4->setText(QApplication::translate("UserSettings", "New name", Q_NULLPTR));
        label->setText(QApplication::translate("UserSettings", "Leave blank space to keep old information", Q_NULLPTR));
        changeButton->setText(QApplication::translate("UserSettings", "Change User's Data", Q_NULLPTR));
        backButton->setText(QApplication::translate("UserSettings", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UserSettings: public Ui_UserSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSETTINGS_H
