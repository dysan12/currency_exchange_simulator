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
    src/connections/serverconnection.cpp \
    src/logger/logscreator.cpp \
    src/logger/logshandler.cpp \
    src/logger/errorslog.cpp \
    src/logger/warningslog.cpp \
    src/exceptions/exception.cpp \
    src/exceptions/datatoolongexception.cpp \
    src/exceptions/invalidcredentialsexception.cpp \
    src/exceptions/arrayssizeincompatibleexception.cpp \
    src/exceptions/nothandledmethodexception.cpp \
    src/exceptions/serverconnectionbrokenexception.cpp \
    src/exceptions/badrequestexception.cpp \
    src/exceptions/accessdeniedexception.cpp \
    src/exceptions/internalservererrorexception.cpp \
    src/exceptions/valuesoccupiedexception.cpp \
#VIEWS
    src/mv/views/menuwindow.cpp \
    src/mv/views/loginwindow.cpp \
    src/mv/views/registerwindow.cpp \
    src/mv/views/investmentswindow.cpp \
    src/mv/views/addinvestmentwindow.cpp \
    src/mv/views/modifyinvestmentwindow.cpp \
    src/mv/views/usersettingswindow.cpp \
    src/mv/views/explanationwindow.cpp \
    src/mv/views/stockwindow.cpp \
#MODELS
    src/mv/models/model.cpp \
    src/mv/models/modelConnection.cpp \
    src/mv/models/usermodel.cpp \
    src/mv/models/userhandlermodel.cpp \
    src/mv/models/investmentsmodel.cpp \
    src/mv/models/investment.cpp \
    src/mv/models/token.cpp \
    src/mv/models/responsehandler.cpp

HEADERS += \
        config.h \
#OTHER COMPONENTS
    src/connections/serverconnection.h \
    src/logger/logscreator.h \
    src/logger/logshandler.h \
    src/logger/errorslog.h \
    src/logger/warningslog.h \
    src/exceptions/exception.h \
    src/exceptions/datatoolongexception.h \
    src/exceptions/invalidcredentialsexception.h \
    src/exceptions/arrayssizeincompatibleexception.h \
    src/exceptions/nothandledmethodexception.h \
    src/exceptions/serverconnectionbrokenexception.h \
    src/exceptions/badrequestexception.h \
    src/exceptions/accessdeniedexception.h \
    src/exceptions/internalservererrorexception.h \
    src/exceptions/valuesoccupiedexception.h \
#VIEWS
    src/mv/views/menuwindow.h \
    src/mv/views/loginwindow.h \
    src/mv/views/addinvestmentwindow.h \
    src/mv/views/modifyinvestmentwindow.h \
    src/mv/views/usersettingswindow.h \
    src/mv/views/registerwindow.h \
    src/mv/views/investmentswindow.h \
    src/mv/views/explanationwindow.h \
    src/mv/views/stockwindow.h \
#MODELS
    src/mv/models/model.h \
    src/mv/models/modelConnection.h \
    src/mv/models/userhandlermodel.h \
    src/mv/models/usermodel.h \
    src/mv/models/investmentsmodel.h \
    src/mv/models/investment.h \
    src/mv/models/token.h \
    src/mv/models/responsehandler.h

INCLUDEPATH += src\exceptions \
            src\logger \
            src\mv\models \
            src\mv\views \
            src\mv\controllers \
            src\connections \
            libs\curl\include \
            libs\rapidjson\include


FORMS += \
        src/mv/views/menuwindow.ui \
    src/mv/views/loginwindow.ui \
    src/mv/views/registerwindow.ui \
    src/mv/views/investmentswindow.ui \
    src/mv/views/addinvestmentwindow.ui \
    src/mv/views/modifyinvestmentwindow.ui \
    src/mv/views/usersettingswindow.ui \
    src/mv/views/explanationwindow.ui \
    src/mv/views/stockwindow.ui

LIBS += \
        -L"C:/xampp/htdocs/currency_exchange_simulator/pc_side/libs/curl/bin" -lcurl
