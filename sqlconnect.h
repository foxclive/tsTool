#ifndef SQLCONNECT_H
#define SQLCONNECT_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QtDebug>
#include <QDate>

class SQLconnect : public QObject
{
    Q_OBJECT
public:
    explicit SQLconnect(QObject *parent = nullptr);

signals:

public:
    QSqlDatabase msdb;
    bool sqlSelectDB(QString db);
    QVector<QString>  sqlQuery_chkBom(QString query);
    int connectMSsql();
    int sqlQuery_resetBom(QString query);


};

#endif // SQLCONNECT_H
