/********************************************************************************
** Form generated from reading UI file 'addinvestment.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDINVESTMENT_H
#define UI_ADDINVESTMENT_H

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

class Ui_AddInvestment
{
public:
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_8;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_2;
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

    void setupUi(QDialog *AddInvestment)
    {
        if (AddInvestment->objectName().isEmpty())
            AddInvestment->setObjectName(QStringLiteral("AddInvestment"));
        AddInvestment->resize(729, 472);
        label_9 = new QLabel(AddInvestment);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(440, 220, 81, 21));
        label_7 = new QLabel(AddInvestment);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(440, 320, 81, 21));
        label_5 = new QLabel(AddInvestment);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 370, 81, 21));
        label_10 = new QLabel(AddInvestment);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(440, 170, 81, 21));
        label_6 = new QLabel(AddInvestment);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(440, 370, 81, 21));
        label = new QLabel(AddInvestment);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 170, 81, 21));
        label_8 = new QLabel(AddInvestment);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(440, 270, 81, 21));
        label_3 = new QLabel(AddInvestment);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 270, 81, 21));
        label_4 = new QLabel(AddInvestment);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 320, 81, 21));
        label_2 = new QLabel(AddInvestment);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 220, 81, 21));
        label_11 = new QLabel(AddInvestment);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(180, 140, 51, 21));
        label_12 = new QLabel(AddInvestment);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(580, 140, 51, 21));
        lineEdit = new QLineEdit(AddInvestment);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 170, 113, 21));
        lineEdit_2 = new QLineEdit(AddInvestment);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 220, 113, 21));
        lineEdit_3 = new QLineEdit(AddInvestment);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(140, 270, 113, 21));
        lineEdit_4 = new QLineEdit(AddInvestment);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(140, 320, 113, 21));
        lineEdit_5 = new QLineEdit(AddInvestment);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(140, 370, 113, 21));
        lineEdit_6 = new QLineEdit(AddInvestment);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(540, 170, 113, 21));
        lineEdit_7 = new QLineEdit(AddInvestment);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(540, 270, 113, 21));
        lineEdit_8 = new QLineEdit(AddInvestment);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(540, 220, 113, 21));
        lineEdit_9 = new QLineEdit(AddInvestment);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(540, 370, 113, 21));
        lineEdit_10 = new QLineEdit(AddInvestment);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(540, 320, 113, 21));
        label_13 = new QLabel(AddInvestment);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 20, 101, 21));
        nameField = new QLineEdit(AddInvestment);
        nameField->setObjectName(QStringLiteral("nameField"));
        nameField->setGeometry(QRect(20, 50, 231, 21));
        addButton = new QPushButton(AddInvestment);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(440, 40, 141, 41));
        currentAmount = new QLabel(AddInvestment);
        currentAmount->setObjectName(QStringLiteral("currentAmount"));
        currentAmount->setGeometry(QRect(60, 100, 581, 21));
        backButton = new QPushButton(AddInvestment);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(320, 410, 81, 41));

        retranslateUi(AddInvestment);

        QMetaObject::connectSlotsByName(AddInvestment);
    } // setupUi

    void retranslateUi(QDialog *AddInvestment)
    {
        AddInvestment->setWindowTitle(QApplication::translate("AddInvestment", "Dialog", Q_NULLPTR));
        label_9->setText(QApplication::translate("AddInvestment", "Currency #9", Q_NULLPTR));
        label_7->setText(QApplication::translate("AddInvestment", "Currency #7", Q_NULLPTR));
        label_5->setText(QApplication::translate("AddInvestment", "Currency #5", Q_NULLPTR));
        label_10->setText(QApplication::translate("AddInvestment", "Currency #10", Q_NULLPTR));
        label_6->setText(QApplication::translate("AddInvestment", "Currency #6", Q_NULLPTR));
        label->setText(QApplication::translate("AddInvestment", "Currency #1", Q_NULLPTR));
        label_8->setText(QApplication::translate("AddInvestment", "Currency #8", Q_NULLPTR));
        label_3->setText(QApplication::translate("AddInvestment", "Currency #3", Q_NULLPTR));
        label_4->setText(QApplication::translate("AddInvestment", "Currency #4", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddInvestment", "Currency #2", Q_NULLPTR));
        label_11->setText(QApplication::translate("AddInvestment", "Amount", Q_NULLPTR));
        label_12->setText(QApplication::translate("AddInvestment", "Amount", Q_NULLPTR));
        label_13->setText(QApplication::translate("AddInvestment", "Investment Name", Q_NULLPTR));
        addButton->setText(QApplication::translate("AddInvestment", "Add Investment", Q_NULLPTR));
        currentAmount->setText(QApplication::translate("AddInvestment", "Available PLN: ", Q_NULLPTR));
        backButton->setText(QApplication::translate("AddInvestment", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddInvestment: public Ui_AddInvestment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDINVESTMENT_H
