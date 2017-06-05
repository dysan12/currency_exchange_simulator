/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWindow
{
public:
    QWidget *centralWidget;
    QPushButton *stockStatusButton;
    QLabel *loggedUserLabel;
    QPushButton *investmentsButton;
    QPushButton *settingsButton;
    QPushButton *explanationButton;
    QPushButton *exitButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MenuWindow)
    {
        if (MenuWindow->objectName().isEmpty())
            MenuWindow->setObjectName(QStringLiteral("MenuWindow"));
        MenuWindow->resize(500, 484);
        centralWidget = new QWidget(MenuWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stockStatusButton = new QPushButton(centralWidget);
        stockStatusButton->setObjectName(QStringLiteral("stockStatusButton"));
        stockStatusButton->setGeometry(QRect(180, 50, 141, 41));
        loggedUserLabel = new QLabel(centralWidget);
        loggedUserLabel->setObjectName(QStringLiteral("loggedUserLabel"));
        loggedUserLabel->setGeometry(QRect(10, 10, 201, 21));
        investmentsButton = new QPushButton(centralWidget);
        investmentsButton->setObjectName(QStringLiteral("investmentsButton"));
        investmentsButton->setGeometry(QRect(180, 110, 141, 41));
        settingsButton = new QPushButton(centralWidget);
        settingsButton->setObjectName(QStringLiteral("settingsButton"));
        settingsButton->setGeometry(QRect(180, 170, 141, 41));
        explanationButton = new QPushButton(centralWidget);
        explanationButton->setObjectName(QStringLiteral("explanationButton"));
        explanationButton->setGeometry(QRect(180, 230, 141, 41));
        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(210, 380, 81, 41));
        MenuWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MenuWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 500, 20));
        MenuWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MenuWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MenuWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MenuWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MenuWindow->setStatusBar(statusBar);

        retranslateUi(MenuWindow);

        QMetaObject::connectSlotsByName(MenuWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MenuWindow)
    {
        MenuWindow->setWindowTitle(QApplication::translate("MenuWindow", "MenuWindow", Q_NULLPTR));
        stockStatusButton->setText(QApplication::translate("MenuWindow", "Exchange Stock Condition", Q_NULLPTR));
        loggedUserLabel->setText(QApplication::translate("MenuWindow", "There shows Logged User Info", Q_NULLPTR));
        investmentsButton->setText(QApplication::translate("MenuWindow", "User's Investments", Q_NULLPTR));
        settingsButton->setText(QApplication::translate("MenuWindow", "User Settings", Q_NULLPTR));
        explanationButton->setText(QApplication::translate("MenuWindow", "Stock Explanation / Help", Q_NULLPTR));
        exitButton->setText(QApplication::translate("MenuWindow", "Exit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MenuWindow: public Ui_MenuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
