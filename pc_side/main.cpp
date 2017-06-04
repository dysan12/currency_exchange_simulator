#include "config.h"
//#include "serverconnection.h"
#include "menuwindow.h"
#include <QApplication>

#include "logscreator.h"
#include "exception.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //LOGGER TEST
    /*
    LogsCreator logCr;
    LogsHandler * logger = logCr.create("ErrorsLog");

    Exception *exc = new Exception("jakas wiadomosc");

    logger->saveLog("jakis modul", exc);
*/
    MenuWindow *menu=new MenuWindow();
    menu->show();

    return a.exec();
}
