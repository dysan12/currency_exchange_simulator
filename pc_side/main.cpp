#include "menuwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MenuWindow *menu=new MenuWindow();
    menu->show();

    return a.exec();
}
