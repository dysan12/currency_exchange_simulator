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
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLabel *label_13;
    QLineEdit *nameField;
    QPushButton *addButton;
    QLabel *currentAmount;
    QPushButton *backButton;
    QLabel *eurLabel;
    QLabel *gbpLabel;
    QLabel *czkLabel;
    QLabel *jpyLabel;
    QLabel *usdLabel;
    QLabel *brlLabel;
    QLabel *rubLabel;
    QLabel *dkkLabel;
    QLabel *nokLabel;
    QLabel *audLabel;

    void setupUi(QDialog *AddInvestmentWindow)
    {
        if (AddInvestmentWindow->objectName().isEmpty())
            AddInvestmentWindow->setObjectName(QStringLiteral("AddInvestmentWindow"));
        AddInvestmentWindow->resize(729, 472);
        label_11 = new QLabel(AddInvestmentWindow);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(240, 140, 51, 21));
        label_12 = new QLabel(AddInvestmentWindow);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(610, 140, 51, 21));
        lineEdit = new QLineEdit(AddInvestmentWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(200, 170, 113, 21));
        lineEdit_2 = new QLineEdit(AddInvestmentWindow);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 220, 113, 21));
        lineEdit_3 = new QLineEdit(AddInvestmentWindow);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(200, 270, 113, 21));
        lineEdit_4 = new QLineEdit(AddInvestmentWindow);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(200, 320, 113, 21));
        lineEdit_5 = new QLineEdit(AddInvestmentWindow);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(200, 370, 113, 21));
        lineEdit_6 = new QLineEdit(AddInvestmentWindow);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(570, 170, 113, 21));
        lineEdit_7 = new QLineEdit(AddInvestmentWindow);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(570, 270, 113, 21));
        lineEdit_8 = new QLineEdit(AddInvestmentWindow);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(570, 220, 113, 21));
        lineEdit_9 = new QLineEdit(AddInvestmentWindow);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(570, 370, 113, 21));
        lineEdit_10 = new QLineEdit(AddInvestmentWindow);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(570, 320, 113, 21));
        label_13 = new QLabel(AddInvestmentWindow);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 20, 101, 21));
        nameField = new QLineEdit(AddInvestmentWindow);
        nameField->setObjectName(QStringLiteral("nameField"));
        nameField->setGeometry(QRect(20, 50, 231, 21));
        addButton = new QPushButton(AddInvestmentWindow);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(440, 40, 141, 41));
        currentAmount = new QLabel(AddInvestmentWindow);
        currentAmount->setObjectName(QStringLiteral("currentAmount"));
        currentAmount->setGeometry(QRect(60, 100, 581, 21));
        backButton = new QPushButton(AddInvestmentWindow);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(320, 410, 81, 41));
        eurLabel = new QLabel(AddInvestmentWindow);
        eurLabel->setObjectName(QStringLiteral("eurLabel"));
        eurLabel->setGeometry(QRect(40, 220, 131, 21));
        gbpLabel = new QLabel(AddInvestmentWindow);
        gbpLabel->setObjectName(QStringLiteral("gbpLabel"));
        gbpLabel->setGeometry(QRect(40, 320, 131, 21));
        czkLabel = new QLabel(AddInvestmentWindow);
        czkLabel->setObjectName(QStringLiteral("czkLabel"));
        czkLabel->setGeometry(QRect(40, 370, 131, 21));
        jpyLabel = new QLabel(AddInvestmentWindow);
        jpyLabel->setObjectName(QStringLiteral("jpyLabel"));
        jpyLabel->setGeometry(QRect(40, 270, 131, 21));
        usdLabel = new QLabel(AddInvestmentWindow);
        usdLabel->setObjectName(QStringLiteral("usdLabel"));
        usdLabel->setGeometry(QRect(40, 170, 131, 21));
        brlLabel = new QLabel(AddInvestmentWindow);
        brlLabel->setObjectName(QStringLiteral("brlLabel"));
        brlLabel->setGeometry(QRect(410, 220, 141, 21));
        rubLabel = new QLabel(AddInvestmentWindow);
        rubLabel->setObjectName(QStringLiteral("rubLabel"));
        rubLabel->setGeometry(QRect(410, 370, 141, 21));
        dkkLabel = new QLabel(AddInvestmentWindow);
        dkkLabel->setObjectName(QStringLiteral("dkkLabel"));
        dkkLabel->setGeometry(QRect(410, 270, 141, 21));
        nokLabel = new QLabel(AddInvestmentWindow);
        nokLabel->setObjectName(QStringLiteral("nokLabel"));
        nokLabel->setGeometry(QRect(410, 320, 141, 21));
        audLabel = new QLabel(AddInvestmentWindow);
        audLabel->setObjectName(QStringLiteral("audLabel"));
        audLabel->setGeometry(QRect(410, 170, 141, 21));

        retranslateUi(AddInvestmentWindow);

        QMetaObject::connectSlotsByName(AddInvestmentWindow);
    } // setupUi

    void retranslateUi(QDialog *AddInvestmentWindow)
    {
        AddInvestmentWindow->setWindowTitle(QApplication::translate("AddInvestmentWindow", "Dialog", Q_NULLPTR));
        label_11->setText(QApplication::translate("AddInvestmentWindow", "Amount", Q_NULLPTR));
        label_12->setText(QApplication::translate("AddInvestmentWindow", "Amount", Q_NULLPTR));
        label_13->setText(QApplication::translate("AddInvestmentWindow", "Investment Name", Q_NULLPTR));
        addButton->setText(QApplication::translate("AddInvestmentWindow", "Add Investment", Q_NULLPTR));
        currentAmount->setText(QApplication::translate("AddInvestmentWindow", "Available PLN: ", Q_NULLPTR));
        backButton->setText(QApplication::translate("AddInvestmentWindow", "Back", Q_NULLPTR));
        eurLabel->setText(QApplication::translate("AddInvestmentWindow", "Euro", Q_NULLPTR));
        gbpLabel->setText(QApplication::translate("AddInvestmentWindow", "Pound", Q_NULLPTR));
        czkLabel->setText(QApplication::translate("AddInvestmentWindow", "Czech koruna", Q_NULLPTR));
        jpyLabel->setText(QApplication::translate("AddInvestmentWindow", "Yen", Q_NULLPTR));
        usdLabel->setText(QApplication::translate("AddInvestmentWindow", "USD", Q_NULLPTR));
        brlLabel->setText(QApplication::translate("AddInvestmentWindow", "Brazilian real", Q_NULLPTR));
        rubLabel->setText(QApplication::translate("AddInvestmentWindow", "Russian ruble", Q_NULLPTR));
        dkkLabel->setText(QApplication::translate("AddInvestmentWindow", "Danish krone", Q_NULLPTR));
        nokLabel->setText(QApplication::translate("AddInvestmentWindow", "Norwegian krone", Q_NULLPTR));
        audLabel->setText(QApplication::translate("AddInvestmentWindow", "Australian dolar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddInvestmentWindow: public Ui_AddInvestmentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDINVESTMENTWINDOW_H
