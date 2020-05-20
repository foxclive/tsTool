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
        msdbQuery("use db_demo");    //预先选择数据库
        return 0;
    }
}

QString  SQLconnect::msdbQuery(QString query){
    //return list:
    //404 空数据
    QSqlQuery mssqlQuery(msdb);
    qDebug()<<"传入的sql语句为:"<<query;
    if(query==""){
        qDebug()<<"传入空数据";
        return ("404");
        //query="select * from sysdatabases";
        //query="show databases";
    }
    if(!mssqlQuery.exec(query)){
        qDebug()<<mssqlQuery.lastError();
        return QString('1');
    }else{
        QString matResult[3];
        while(mssqlQuery.next()){
            //qDebug()<<mssqlQuery.value(0).toString();
            matResult[0]=mssqlQuery.value(24).toString();
            matResult[1]=mssqlQuery.value(25).toString();
            matResult[2]=mssqlQuery.value(28).toString();
            //return 0;
            }
    }
    //msdb.close();
    return(matResult);//复制还是原本对象的问题
}

void SQLconnect::execPushbtnClicked(){
//清除所有BOM信息


//    msdbQuery("use db_demo");
//    this->msdbQuery("select * from sysdatabases");
    //QMessageBox::about(NULL,"title","nihao");
}

int SQLconnect::testing(){
    while (1) {
        QMessageBox::about(NULL,"1","1");
        return 0;
    }
}
