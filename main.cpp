//#include "widget.h"
#include "sqlctrl.h"


#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QApplication::addLibraryPath("strPluginsPath");
    QApplication::addLibraryPath("./plugins");
    sqlCtrl x;// = new sqlCtrl();
//    Widget w;
//    w.show();

    return a.exec();
}
