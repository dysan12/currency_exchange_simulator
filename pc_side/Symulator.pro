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
#OTHER COMPONENTS
    src/logger/logscreator.cpp \
    src/logger/logshandler.cpp \
    src/logger/errorslog.cpp \
    src/logger/warningslog.cpp \
    src/exceptions/exception.cpp \
#VIEWS
    src/mvc/views/menuwindow.cpp \
    src/mvc/views/loginwindow.cpp \
    src/mvc/views/registerwindow.cpp \
    src/mvc/views/investmentswindow.cpp \
    src/mvc/views/addinvestment.cpp \
    src/mvc/views/modifyinvestment.cpp \
    src/mvc/views/usersettings.cpp \
#MODELS
    src/mvc/models/model.cpp \
    src/mvc/models/loginmodel.cpp \
    src/mvc/models/investmentsmodel.cpp \
    src/mvc/models/registermodel.cpp \    
#CONTROLLERS
    src/mvc/controllers/controller.cpp \
    src/mvc/controllers/logincontroller.cpp

HEADERS += \
        config.h \
#OTHER COMPONENTS
    src/logger/logscreator.h \
    src/logger/logshandler.h \
    src/logger/errorslog.h \
    src/logger/warningslog.h \
    src/exceptions/exception.h \
    src/exceptions/datatoolongexception.h \
#VIEWS
    src/mvc/views/menuwindow.h \
    src/mvc/views/loginwindow.h \
    src/mvc/views/addinvestment.h \
    src/mvc/views/modifyinvestment.h \
    src/mvc/views/usersettings.h \
    src/mvc/views/registerwindow.h \
    src/mvc/views/investmentswindow.h \
#MODELS
    src/mvc/models/model.h \
    src/mvc/models/loginmodel.h \
    src/mvc/models/registermodel.h \
    src/mvc/models/investmentsmodel.h \    
#CONTROLLERS
    src/mvc/controllers/controller.h \
    src/mvc/controllers/logincontroller.h

INCLUDEPATH += src\exceptions \
            src\logger \
            src\mvc\models \
            src\mvc\views \
            src\mvc\controllers


FORMS += \
        src/mvc/views/menuwindow.ui \
    src/mvc/views/loginwindow.ui \
    src/mvc/views/registerwindow.ui \
    src/mvc/views/investmentswindow.ui \
    src/mvc/views/addinvestment.ui \
    src/mvc/views/modifyinvestment.ui \
    src/mvc/views/usersettings.ui

