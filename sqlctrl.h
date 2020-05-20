#ifndef SQLCTRL_H
#define SQLCTRL_H

#include <QObject>
#include "widget.h"
#include "sqlconnect.h"

class sqlCtrl : public QObject
{
    Q_OBJECT
public:
    explicit sqlCtrl(QObject *parent = nullptr);

signals:

//public:
//    sqlCtrl();
//    ~sqlCtrl();

};

#endif // SQLCTRL_H
