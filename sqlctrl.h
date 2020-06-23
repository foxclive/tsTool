#ifndef SQLCTRL_H
#define SQLCTRL_H

#include <QObject>
#include "widget.h"
#include "sqlconnect.h"
#include <QDebug>
#include <QString>

class sqlCtrl : public QObject
{
    Q_OBJECT
public:
    explicit sqlCtrl(QObject *parent = nullptr);

public:
    Widget *w;
    SQLconnect *sqlCon;

signals:

public slots:
    int execBtnClicked();
    int bomBtnClicked();
    int selectDB();

//public:
//    sqlCtrl();
//    ~sqlCtrl();

};

#endif // SQLCTRL_H
