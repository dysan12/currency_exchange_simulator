/********************************************************************************
** Form generated from reading UI file 'addinvestmentwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDINVESTMENTWINDOW_H
#define UI_ADDINVESTMENTWINDOW_H

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

class Ui_AddInvestmentWindow
{
public:
    QLabel *label_13;
    QLineEdit *nameField;
    QPushButton *addButton;
    QLabel *currentAmount;
    QPushButton *backButton;

    void setupUi(QDialog *AddInvestmentWindow)
    {
        if (AddInvestmentWindow->objectName().isEmpty())
            AddInvestmentWindow->setObjectName(QStringLiteral("AddInvestmentWindow"));
        AddInvestmentWindow->resize(501, 216);
        label_13 = new QLabel(AddInvestmentWindow);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 20, 101, 21));
        nameField = new QLineEdit(AddInvestmentWindow);
        nameField->setObjectName(QStringLiteral("nameField"));
        nameField->setGeometry(QRect(20, 50, 231, 21));
        addButton = new QPushButton(AddInvestmentWindow);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(330, 40, 141, 41));
        currentAmount = new QLabel(AddInvestmentWindow);
        currentAmount->setObjectName(QStringLiteral("currentAmount"));
        currentAmount->setGeometry(QRect(40, 90, 381, 21));
        backButton = new QPushButton(AddInvestmentWindow);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(200, 140, 81, 41));

        retranslateUi(AddInvestmentWindow);

        QMetaObject::connectSlotsByName(AddInvestmentWindow);
    } // setupUi

    void retranslateUi(QDialog *AddInvestmentWindow)
    {
        AddInvestmentWindow->setWindowTitle(QApplication::translate("AddInvestmentWindow", "Dialog", Q_NULLPTR));
        label_13->setText(QApplication::translate("AddInvestmentWindow", "Investment Name", Q_NULLPTR));
        addButton->setText(QApplication::translate("AddInvestmentWindow", "Add Investment", Q_NULLPTR));
        currentAmount->setText(QApplication::translate("AddInvestmentWindow", "Available PLN: ", Q_NULLPTR));
        backButton->setText(QApplication::translate("AddInvestmentWindow", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddInvestmentWindow: public Ui_AddInvestmentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDINVESTMENTWINDOW_H
