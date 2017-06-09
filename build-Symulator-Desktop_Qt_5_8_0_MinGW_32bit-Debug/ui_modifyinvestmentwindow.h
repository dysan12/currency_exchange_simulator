/********************************************************************************
** Form generated from reading UI file 'modifyinvestmentwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYINVESTMENTWINDOW_H
#define UI_MODIFYINVESTMENTWINDOW_H

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

class Ui_ModifyInvestmentWindow
{
public:
    QLabel *label_13;
    QPushButton *modifyButton;
    QLabel *currentAmount;
    QPushButton *backButton;
    QLineEdit *brlField;
    QLabel *label_12;
    QLabel *usdLabel;
    QLineEdit *usdField;
    QLabel *eurLabel;
    QLabel *dkkLabel;
    QLabel *jpyLabel;
    QLineEdit *nokField;
    QLineEdit *dkkField;
    QLineEdit *czkField;
    QLabel *brlLabel;
    QLabel *audLabel;
    QLineEdit *audField;
    QLabel *label_11;
    QLineEdit *gbpField;
    QLineEdit *rubField;
    QLineEdit *jpyField;
    QLineEdit *eurField;
    QLabel *nokLabel;
    QLabel *czkLabel;
    QLabel *rubLabel;
    QLabel *gbpLabel;
    QLabel *nameField;

    void setupUi(QDialog *ModifyInvestmentWindow)
    {
        if (ModifyInvestmentWindow->objectName().isEmpty())
            ModifyInvestmentWindow->setObjectName(QStringLiteral("ModifyInvestmentWindow"));
        ModifyInvestmentWindow->resize(729, 472);
        label_13 = new QLabel(ModifyInvestmentWindow);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(50, 20, 101, 21));
        modifyButton = new QPushButton(ModifyInvestmentWindow);
        modifyButton->setObjectName(QStringLiteral("modifyButton"));
        modifyButton->setGeometry(QRect(440, 40, 141, 41));
        currentAmount = new QLabel(ModifyInvestmentWindow);
        currentAmount->setObjectName(QStringLiteral("currentAmount"));
        currentAmount->setGeometry(QRect(60, 100, 581, 21));
        backButton = new QPushButton(ModifyInvestmentWindow);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(320, 410, 81, 41));
        brlField = new QLineEdit(ModifyInvestmentWindow);
        brlField->setObjectName(QStringLiteral("brlField"));
        brlField->setGeometry(QRect(570, 220, 113, 21));
        label_12 = new QLabel(ModifyInvestmentWindow);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(610, 140, 51, 21));
        usdLabel = new QLabel(ModifyInvestmentWindow);
        usdLabel->setObjectName(QStringLiteral("usdLabel"));
        usdLabel->setGeometry(QRect(40, 170, 131, 21));
        usdField = new QLineEdit(ModifyInvestmentWindow);
        usdField->setObjectName(QStringLiteral("usdField"));
        usdField->setGeometry(QRect(200, 170, 113, 21));
        eurLabel = new QLabel(ModifyInvestmentWindow);
        eurLabel->setObjectName(QStringLiteral("eurLabel"));
        eurLabel->setGeometry(QRect(40, 220, 131, 21));
        dkkLabel = new QLabel(ModifyInvestmentWindow);
        dkkLabel->setObjectName(QStringLiteral("dkkLabel"));
        dkkLabel->setGeometry(QRect(410, 270, 141, 21));
        jpyLabel = new QLabel(ModifyInvestmentWindow);
        jpyLabel->setObjectName(QStringLiteral("jpyLabel"));
        jpyLabel->setGeometry(QRect(40, 270, 131, 21));
        nokField = new QLineEdit(ModifyInvestmentWindow);
        nokField->setObjectName(QStringLiteral("nokField"));
        nokField->setGeometry(QRect(570, 320, 113, 21));
        dkkField = new QLineEdit(ModifyInvestmentWindow);
        dkkField->setObjectName(QStringLiteral("dkkField"));
        dkkField->setGeometry(QRect(570, 270, 113, 21));
        czkField = new QLineEdit(ModifyInvestmentWindow);
        czkField->setObjectName(QStringLiteral("czkField"));
        czkField->setGeometry(QRect(200, 370, 113, 21));
        brlLabel = new QLabel(ModifyInvestmentWindow);
        brlLabel->setObjectName(QStringLiteral("brlLabel"));
        brlLabel->setGeometry(QRect(410, 220, 141, 21));
        audLabel = new QLabel(ModifyInvestmentWindow);
        audLabel->setObjectName(QStringLiteral("audLabel"));
        audLabel->setGeometry(QRect(410, 170, 141, 21));
        audField = new QLineEdit(ModifyInvestmentWindow);
        audField->setObjectName(QStringLiteral("audField"));
        audField->setGeometry(QRect(570, 170, 113, 21));
        label_11 = new QLabel(ModifyInvestmentWindow);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(240, 140, 51, 21));
        gbpField = new QLineEdit(ModifyInvestmentWindow);
        gbpField->setObjectName(QStringLiteral("gbpField"));
        gbpField->setGeometry(QRect(200, 320, 113, 21));
        rubField = new QLineEdit(ModifyInvestmentWindow);
        rubField->setObjectName(QStringLiteral("rubField"));
        rubField->setGeometry(QRect(570, 370, 113, 21));
        jpyField = new QLineEdit(ModifyInvestmentWindow);
        jpyField->setObjectName(QStringLiteral("jpyField"));
        jpyField->setGeometry(QRect(200, 270, 113, 21));
        eurField = new QLineEdit(ModifyInvestmentWindow);
        eurField->setObjectName(QStringLiteral("eurField"));
        eurField->setGeometry(QRect(200, 220, 113, 21));
        nokLabel = new QLabel(ModifyInvestmentWindow);
        nokLabel->setObjectName(QStringLiteral("nokLabel"));
        nokLabel->setGeometry(QRect(410, 320, 141, 21));
        czkLabel = new QLabel(ModifyInvestmentWindow);
        czkLabel->setObjectName(QStringLiteral("czkLabel"));
        czkLabel->setGeometry(QRect(40, 370, 131, 21));
        rubLabel = new QLabel(ModifyInvestmentWindow);
        rubLabel->setObjectName(QStringLiteral("rubLabel"));
        rubLabel->setGeometry(QRect(410, 370, 141, 21));
        gbpLabel = new QLabel(ModifyInvestmentWindow);
        gbpLabel->setObjectName(QStringLiteral("gbpLabel"));
        gbpLabel->setGeometry(QRect(40, 320, 131, 21));
        nameField = new QLabel(ModifyInvestmentWindow);
        nameField->setObjectName(QStringLiteral("nameField"));
        nameField->setGeometry(QRect(20, 50, 271, 21));

        retranslateUi(ModifyInvestmentWindow);

        QMetaObject::connectSlotsByName(ModifyInvestmentWindow);
    } // setupUi

    void retranslateUi(QDialog *ModifyInvestmentWindow)
    {
        ModifyInvestmentWindow->setWindowTitle(QApplication::translate("ModifyInvestmentWindow", "Dialog", Q_NULLPTR));
        label_13->setText(QApplication::translate("ModifyInvestmentWindow", "Investment Name", Q_NULLPTR));
        modifyButton->setText(QApplication::translate("ModifyInvestmentWindow", "Modify Investment", Q_NULLPTR));
        currentAmount->setText(QApplication::translate("ModifyInvestmentWindow", "Available PLN: ", Q_NULLPTR));
        backButton->setText(QApplication::translate("ModifyInvestmentWindow", "Back", Q_NULLPTR));
        label_12->setText(QApplication::translate("ModifyInvestmentWindow", "Amount", Q_NULLPTR));
        usdLabel->setText(QApplication::translate("ModifyInvestmentWindow", "USD", Q_NULLPTR));
        eurLabel->setText(QApplication::translate("ModifyInvestmentWindow", "Euro", Q_NULLPTR));
        dkkLabel->setText(QApplication::translate("ModifyInvestmentWindow", "Danish krone", Q_NULLPTR));
        jpyLabel->setText(QApplication::translate("ModifyInvestmentWindow", "Yen", Q_NULLPTR));
        brlLabel->setText(QApplication::translate("ModifyInvestmentWindow", "Brazilian real", Q_NULLPTR));
        audLabel->setText(QApplication::translate("ModifyInvestmentWindow", "Australian dolar", Q_NULLPTR));
        label_11->setText(QApplication::translate("ModifyInvestmentWindow", "Amount", Q_NULLPTR));
        nokLabel->setText(QApplication::translate("ModifyInvestmentWindow", "Norwegian krone", Q_NULLPTR));
        czkLabel->setText(QApplication::translate("ModifyInvestmentWindow", "Czech koruna", Q_NULLPTR));
        rubLabel->setText(QApplication::translate("ModifyInvestmentWindow", "Russian ruble", Q_NULLPTR));
        gbpLabel->setText(QApplication::translate("ModifyInvestmentWindow", "Pound", Q_NULLPTR));
        nameField->setText(QApplication::translate("ModifyInvestmentWindow", "Inv Name", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ModifyInvestmentWindow: public Ui_ModifyInvestmentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYINVESTMENTWINDOW_H
