#ifndef SQLCONNECT_H
#define SQLCONNECT_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QtDebug>

class SQLconnect : public QObject
{
    Q_OBJECT
public:
    explicit SQLconnect(QObject *parent = nullptr);

signals:

public:
    QSqlDatabase msdb;

    QString  msdbQuery(QString query);
    int connectMSsql();
    int testing();
public slots:
    void execPushbtnClicked();

};

#endif // SQLCONNECT_H
