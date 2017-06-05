/********************************************************************************
** Form generated from reading UI file 'investmentswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVESTMENTSWINDOW_H
#define UI_INVESTMENTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InvestmentsWindow
{
public:
    QPushButton *backButton;
    QLabel *loggedUserLabel;
    QComboBox *invesmentsList;
    QLabel *pathLabel;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QPushButton *modifyButton;
    QLabel *currentAmount;

    void setupUi(QDialog *InvestmentsWindow)
    {
        if (InvestmentsWindow->objectName().isEmpty())
            InvestmentsWindow->setObjectName(QStringLiteral("InvestmentsWindow"));
        InvestmentsWindow->resize(726, 604);
        backButton = new QPushButton(InvestmentsWindow);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(540, 550, 81, 41));
        loggedUserLabel = new QLabel(InvestmentsWindow);
        loggedUserLabel->setObjectName(QStringLiteral("loggedUserLabel"));
        loggedUserLabel->setGeometry(QRect(30, 10, 231, 21));
        invesmentsList = new QComboBox(InvestmentsWindow);
        invesmentsList->setObjectName(QStringLiteral("invesmentsList"));
        invesmentsList->setGeometry(QRect(30, 110, 661, 22));
        pathLabel = new QLabel(InvestmentsWindow);
        pathLabel->setObjectName(QStringLiteral("pathLabel"));
        pathLabel->setGeometry(QRect(40, 80, 141, 21));
        addButton = new QPushButton(InvestmentsWindow);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(90, 150, 141, 41));
        deleteButton = new QPushButton(InvestmentsWindow);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setGeometry(QRect(490, 150, 141, 41));
        label = new QLabel(InvestmentsWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 290, 81, 21));
        label_3 = new QLabel(InvestmentsWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(70, 390, 81, 21));
        label_4 = new QLabel(InvestmentsWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 440, 81, 21));
        label_5 = new QLabel(InvestmentsWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(70, 490, 81, 21));
        label_6 = new QLabel(InvestmentsWindow);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(460, 490, 81, 21));
        label_2 = new QLabel(InvestmentsWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 340, 81, 21));
        label_7 = new QLabel(InvestmentsWindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(460, 440, 81, 21));
        label_8 = new QLabel(InvestmentsWindow);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(460, 390, 81, 21));
        label_9 = new QLabel(InvestmentsWindow);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(460, 340, 81, 21));
        label_10 = new QLabel(InvestmentsWindow);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(460, 290, 81, 21));
        label_11 = new QLabel(InvestmentsWindow);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(210, 290, 81, 21));
        label_12 = new QLabel(InvestmentsWindow);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(210, 340, 81, 21));
        label_13 = new QLabel(InvestmentsWindow);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(210, 390, 81, 21));
        label_14 = new QLabel(InvestmentsWindow);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(210, 440, 81, 21));
        label_15 = new QLabel(InvestmentsWindow);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(210, 490, 81, 21));
        label_16 = new QLabel(InvestmentsWindow);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(610, 290, 81, 21));
        label_17 = new QLabel(InvestmentsWindow);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(610, 340, 81, 21));
        label_18 = new QLabel(InvestmentsWindow);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(610, 390, 81, 21));
        label_19 = new QLabel(InvestmentsWindow);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(610, 440, 81, 21));
        label_20 = new QLabel(InvestmentsWindow);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(610, 490, 81, 21));
        modifyButton = new QPushButton(InvestmentsWindow);
        modifyButton->setObjectName(QStringLiteral("modifyButton"));
        modifyButton->setGeometry(QRect(290, 150, 141, 41));
        currentAmount = new QLabel(InvestmentsWindow);
        currentAmount->setObjectName(QStringLiteral("currentAmount"));
        currentAmount->setGeometry(QRect(80, 230, 581, 21));

        retranslateUi(InvestmentsWindow);

        QMetaObject::connectSlotsByName(InvestmentsWindow);
    } // setupUi

    void retranslateUi(QDialog *InvestmentsWindow)
    {
        InvestmentsWindow->setWindowTitle(QApplication::translate("InvestmentsWindow", "Dialog", Q_NULLPTR));
        backButton->setText(QApplication::translate("InvestmentsWindow", "Back", Q_NULLPTR));
        loggedUserLabel->setText(QApplication::translate("InvestmentsWindow", "loggedUserLabel", Q_NULLPTR));
        invesmentsList->setCurrentText(QString());
        pathLabel->setText(QApplication::translate("InvestmentsWindow", "List of your investments:", Q_NULLPTR));
        addButton->setText(QApplication::translate("InvestmentsWindow", "Add new investment", Q_NULLPTR));
        deleteButton->setText(QApplication::translate("InvestmentsWindow", "Delete investment", Q_NULLPTR));
        label->setText(QApplication::translate("InvestmentsWindow", "Currency #1", Q_NULLPTR));
        label_3->setText(QApplication::translate("InvestmentsWindow", "Currency #3", Q_NULLPTR));
        label_4->setText(QApplication::translate("InvestmentsWindow", "Currency #4", Q_NULLPTR));
        label_5->setText(QApplication::translate("InvestmentsWindow", "Currency #5", Q_NULLPTR));
        label_6->setText(QApplication::translate("InvestmentsWindow", "Currency #6", Q_NULLPTR));
        label_2->setText(QApplication::translate("InvestmentsWindow", "Currency #2", Q_NULLPTR));
        label_7->setText(QApplication::translate("InvestmentsWindow", "Currency #7", Q_NULLPTR));
        label_8->setText(QApplication::translate("InvestmentsWindow", "Currency #8", Q_NULLPTR));
        label_9->setText(QApplication::translate("InvestmentsWindow", "Currency #9", Q_NULLPTR));
        label_10->setText(QApplication::translate("InvestmentsWindow", "Currency #10", Q_NULLPTR));
        label_11->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        label_12->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        label_13->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        label_14->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        label_15->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        label_16->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        label_17->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        label_18->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        label_19->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        label_20->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        modifyButton->setText(QApplication::translate("InvestmentsWindow", "Modify investment", Q_NULLPTR));
        currentAmount->setText(QApplication::translate("InvestmentsWindow", "Global value of investments (current amount of PLN only): ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InvestmentsWindow: public Ui_InvestmentsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVESTMENTSWINDOW_H
