#include <QApplication>


#include "config.h"
#include "loginwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginWindow *login = new LoginWindow();
    login->show();

    return a.exec();
}
/*
 * SAMPLE USE OF EXCPETIONS AND LOGS

    #include "logscreator.h"
    #include "exception.h"

    LogsCreator logCr;
    LogsHandler * logger = logCr.create("error");

    Exception *exc = new Exception("some message");

    logger->saveLog("some module", exc);
*/
