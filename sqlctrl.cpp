#include "sqlctrl.h"

sqlCtrl::sqlCtrl(QObject *parent) : QObject(parent)
{
    SQLconnect *sqlCon= new SQLconnect();
    Widget *w = new Widget();
    sqlCon->msdbQuery("");

    connect(w->execPushbtn,&QPushButton::clicked,sqlCon,&SQLconnect::execPushbtnClicked);



    w->show();
}
