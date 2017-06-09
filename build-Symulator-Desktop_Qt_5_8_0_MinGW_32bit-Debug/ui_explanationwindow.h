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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ExplanationWindow
{
public:
    QLabel *label;
    QPushButton *backButton;

    void setupUi(QDialog *ExplanationWindow)
    {
        if (ExplanationWindow->objectName().isEmpty())
            ExplanationWindow->setObjectName(QStringLiteral("ExplanationWindow"));
        ExplanationWindow->resize(758, 401);
        label = new QLabel(ExplanationWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 70, 301, 131));
        backButton = new QPushButton(ExplanationWindow);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(320, 290, 81, 41));

        retranslateUi(ExplanationWindow);

        QMetaObject::connectSlotsByName(ExplanationWindow);
    } // setupUi

    void retranslateUi(QDialog *ExplanationWindow)
    {
        ExplanationWindow->setWindowTitle(QApplication::translate("ExplanationWindow", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ExplanationWindow", "WORKSPACE, PLEASE DISPEARSE!!!!", Q_NULLPTR));
        backButton->setText(QApplication::translate("ExplanationWindow", "RUN", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ExplanationWindow: public Ui_ExplanationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPLANATIONWINDOW_H
