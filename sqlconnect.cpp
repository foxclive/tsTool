#include "sqlconnect.h"
using namespace std;
SQLconnect::SQLconnect(QObject *parent) : QObject(parent)
{
    connectMSsql();
}
int SQLconnect::connectMSsql(){

    msdb=QSqlDatabase::addDatabase("QODBC");
    qDebug()<<"ODBC driver?"<<msdb.isValid();
    QString dsn = QString::fromLocal8Bit("ERP");
    msdb.setHostName("10.1.9.16");
    msdb.setPort(1433);
    msdb.setDatabaseName(dsn);
    msdb.setUserName("sa");
    msdb.setPassword("system");
    if(!msdb.open()){
        qDebug()<<"连接失败"<<msdb.lastError().text();
        return 1;
    }else{
        qDebug()<<"连接成功"<<"connected to mssql";
        return 0;
    }
}

int SQLconnect::msdbQuery(QString query){
    QSqlQuery mssqlQuery(msdb);
    if(query==""){
        query="select * from sysdatabases";
        //query="show databases";
    }
    if(!mssqlQuery.exec(query)){
        qDebug()<<mssqlQuery.lastError();
        return 1;
    }else{
        while(mssqlQuery.next()){
            qDebug()<<mssqlQuery.value(0).toString();
            return 0;
        }
    }
    msdb.close();
    return 0;
}

void SQLconnect::execPushbtnClicked(QString string){
    msdbQuery(string);
    //QMessageBox::about(NULL,"title","nihao");
}

int SQLconnect::testing(){
    while (1) {
        QMessageBox::about(NULL,"1","1");
    }
    return(1);
}
