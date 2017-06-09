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
    QLabel *usdLabel;
    QLabel *jpyLabel;
    QLabel *gbpLabel;
    QLabel *czkLabel;
    QLabel *rubLabel;
    QLabel *eurLabel;
    QLabel *nokLabel;
    QLabel *dkkLabel;
    QLabel *brlLabel;
    QLabel *audLabel;
    QLabel *usdAmount;
    QLabel *eurAmount;
    QLabel *jpyAmount;
    QLabel *gbpAmount;
    QLabel *czkAmount;
    QLabel *audAmount;
    QLabel *brlAmount;
    QLabel *dkkAmount;
    QLabel *nokAmount;
    QLabel *rubAmount;
    QPushButton *modifyButton;
    QLabel *valueInfoLabel;
    QLabel *plnAmount;

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
        usdLabel = new QLabel(InvestmentsWindow);
        usdLabel->setObjectName(QStringLiteral("usdLabel"));
        usdLabel->setGeometry(QRect(70, 290, 131, 21));
        jpyLabel = new QLabel(InvestmentsWindow);
        jpyLabel->setObjectName(QStringLiteral("jpyLabel"));
        jpyLabel->setGeometry(QRect(70, 390, 131, 21));
        gbpLabel = new QLabel(InvestmentsWindow);
        gbpLabel->setObjectName(QStringLiteral("gbpLabel"));
        gbpLabel->setGeometry(QRect(70, 440, 131, 21));
        czkLabel = new QLabel(InvestmentsWindow);
        czkLabel->setObjectName(QStringLiteral("czkLabel"));
        czkLabel->setGeometry(QRect(70, 490, 131, 21));
        rubLabel = new QLabel(InvestmentsWindow);
        rubLabel->setObjectName(QStringLiteral("rubLabel"));
        rubLabel->setGeometry(QRect(460, 490, 141, 21));
        eurLabel = new QLabel(InvestmentsWindow);
        eurLabel->setObjectName(QStringLiteral("eurLabel"));
        eurLabel->setGeometry(QRect(70, 340, 131, 21));
        nokLabel = new QLabel(InvestmentsWindow);
        nokLabel->setObjectName(QStringLiteral("nokLabel"));
        nokLabel->setGeometry(QRect(460, 440, 141, 21));
        dkkLabel = new QLabel(InvestmentsWindow);
        dkkLabel->setObjectName(QStringLiteral("dkkLabel"));
        dkkLabel->setGeometry(QRect(460, 390, 141, 21));
        brlLabel = new QLabel(InvestmentsWindow);
        brlLabel->setObjectName(QStringLiteral("brlLabel"));
        brlLabel->setGeometry(QRect(460, 340, 141, 21));
        audLabel = new QLabel(InvestmentsWindow);
        audLabel->setObjectName(QStringLiteral("audLabel"));
        audLabel->setGeometry(QRect(460, 290, 141, 21));
        usdAmount = new QLabel(InvestmentsWindow);
        usdAmount->setObjectName(QStringLiteral("usdAmount"));
        usdAmount->setGeometry(QRect(210, 290, 81, 21));
        eurAmount = new QLabel(InvestmentsWindow);
        eurAmount->setObjectName(QStringLiteral("eurAmount"));
        eurAmount->setGeometry(QRect(210, 340, 81, 21));
        jpyAmount = new QLabel(InvestmentsWindow);
        jpyAmount->setObjectName(QStringLiteral("jpyAmount"));
        jpyAmount->setGeometry(QRect(210, 390, 81, 21));
        gbpAmount = new QLabel(InvestmentsWindow);
        gbpAmount->setObjectName(QStringLiteral("gbpAmount"));
        gbpAmount->setGeometry(QRect(210, 440, 81, 21));
        czkAmount = new QLabel(InvestmentsWindow);
        czkAmount->setObjectName(QStringLiteral("czkAmount"));
        czkAmount->setGeometry(QRect(210, 490, 81, 21));
        audAmount = new QLabel(InvestmentsWindow);
        audAmount->setObjectName(QStringLiteral("audAmount"));
        audAmount->setGeometry(QRect(610, 290, 81, 21));
        brlAmount = new QLabel(InvestmentsWindow);
        brlAmount->setObjectName(QStringLiteral("brlAmount"));
        brlAmount->setGeometry(QRect(610, 340, 81, 21));
        dkkAmount = new QLabel(InvestmentsWindow);
        dkkAmount->setObjectName(QStringLiteral("dkkAmount"));
        dkkAmount->setGeometry(QRect(610, 390, 81, 21));
        nokAmount = new QLabel(InvestmentsWindow);
        nokAmount->setObjectName(QStringLiteral("nokAmount"));
        nokAmount->setGeometry(QRect(610, 440, 81, 21));
        rubAmount = new QLabel(InvestmentsWindow);
        rubAmount->setObjectName(QStringLiteral("rubAmount"));
        rubAmount->setGeometry(QRect(610, 490, 81, 21));
        modifyButton = new QPushButton(InvestmentsWindow);
        modifyButton->setObjectName(QStringLiteral("modifyButton"));
        modifyButton->setGeometry(QRect(290, 150, 141, 41));
        valueInfoLabel = new QLabel(InvestmentsWindow);
        valueInfoLabel->setObjectName(QStringLiteral("valueInfoLabel"));
        valueInfoLabel->setGeometry(QRect(80, 230, 281, 21));
        plnAmount = new QLabel(InvestmentsWindow);
        plnAmount->setObjectName(QStringLiteral("plnAmount"));
        plnAmount->setGeometry(QRect(420, 230, 161, 21));

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
        usdLabel->setText(QApplication::translate("InvestmentsWindow", "USD", Q_NULLPTR));
        jpyLabel->setText(QApplication::translate("InvestmentsWindow", "Yen", Q_NULLPTR));
        gbpLabel->setText(QApplication::translate("InvestmentsWindow", "Pound", Q_NULLPTR));
        czkLabel->setText(QApplication::translate("InvestmentsWindow", "Czech koruna", Q_NULLPTR));
        rubLabel->setText(QApplication::translate("InvestmentsWindow", "Russian ruble", Q_NULLPTR));
        eurLabel->setText(QApplication::translate("InvestmentsWindow", "Euro", Q_NULLPTR));
        nokLabel->setText(QApplication::translate("InvestmentsWindow", "Norwegian krone", Q_NULLPTR));
        dkkLabel->setText(QApplication::translate("InvestmentsWindow", "Danish krone", Q_NULLPTR));
        brlLabel->setText(QApplication::translate("InvestmentsWindow", "Brazilian real", Q_NULLPTR));
        audLabel->setText(QApplication::translate("InvestmentsWindow", "Australian dolar", Q_NULLPTR));
        usdAmount->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        eurAmount->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        jpyAmount->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        gbpAmount->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        czkAmount->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        audAmount->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        brlAmount->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        dkkAmount->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        nokAmount->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        rubAmount->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
        modifyButton->setText(QApplication::translate("InvestmentsWindow", "Modify investment", Q_NULLPTR));
        valueInfoLabel->setText(QApplication::translate("InvestmentsWindow", "Global value of investments (current amount of PLN only): ", Q_NULLPTR));
        plnAmount->setText(QApplication::translate("InvestmentsWindow", "Amount", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InvestmentsWindow: public Ui_InvestmentsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVESTMENTSWINDOW_H
