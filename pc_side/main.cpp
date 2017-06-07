#include <QApplication>


#include "config.h"
#include "loginwindow.h"
#include "curl/curl.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    curl_global_init(CURL_GLOBAL_DEFAULT);

    LoginWindow *login=new LoginWindow();
    login->show();

    curl_global_cleanup();
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
