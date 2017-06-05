#-------------------------------------------------
#
# Project created by QtCreator 2017-05-31T15:31:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Symulator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
        main.cpp \
        menuwindow.cpp \
    loginwindow.cpp \
    loginmodel.cpp \
    registerwindow.cpp \
    registermodel.cpp \
    logincontroller.cpp \
    investmentswindow.cpp \
    investmentsmodel.cpp \
    addinvestment.cpp \
    modifyinvestment.cpp \
    usersettings.cpp \
    windowmodel.cpp \
    src/logger/logscreator.cpp \
    src/logger/logshandler.cpp \
    src/logger/errorslog.cpp \
    src/exceptions/exception.cpp

HEADERS += \
        menuwindow.h \
    loginwindow.h \
    loginmodel.h \
    registerwindow.h \
    registermodel.h \
    config.h \
    logincontroller.h \
    investmentswindow.h \
    investmentsmodel.h \
    addinvestment.h \
    modifyinvestment.h \
    usersettings.h \
    windowmodel.h \
    exceptions/arrayssizeincompatible.h \
    src/logger/logscreator.h \
    src/logger/logshandler.h \
    src/logger/errorslog.h \
    src/exceptions/exception.h

INCLUDEPATH += src\exceptions \
            src\logger


FORMS += \
        menuwindow.ui \
    loginwindow.ui \
    registerwindow.ui \
    investmentswindow.ui \
    addinvestment.ui \
    modifyinvestment.ui \
    usersettings.ui

