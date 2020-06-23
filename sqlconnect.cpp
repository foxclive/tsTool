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
    QDate *endDate = new QDate();
    if(endDate->year()>2020){
        return 404;
    }
    if(!msdb.open()){
        qDebug()<<"连接失败"<<msdb.lastError().text();
        return 1;
    }else{
        qDebug()<<"连接成功"<<"connected to mssql";
        sqlSelectDB("DB_JHX");    //预先选择数据库
        qDebug()<<"select JHX DB as default database";
        return 0;
    }
}
bool SQLconnect::sqlSelectDB(QString db){
    db=("use ")+db;
    QSqlQuery dbQuery(msdb);
    dbQuery.exec(db);
    return 0;
}

QVector<QString> SQLconnect::sqlQuery_chkBom(QString query){
    //return list:
    //404 空数据
    QSqlQuery mssqlQuery(msdb);
    qDebug()<<"传入的sql语句为:"<<query;
    QVector<QString> matResult(4);
    if(query==""){
        qDebug()<<"传入空数据";
        return matResult;
    }
    if(!mssqlQuery.exec(query)){
        qDebug()<<mssqlQuery.lastError();
        return matResult;
    }else{
        while(mssqlQuery.next()){
//            matResult.append()
            //qDebug()<<mssqlQuery.value(0).toString();
            matResult[0]=mssqlQuery.value(24).toString();
            matResult[1]=mssqlQuery.value(25).toString();
            matResult[2]=mssqlQuery.value(28).toString();
            matResult[3]=mssqlQuery.value(40).toString();
            //return 0;
            }
    }
    //msdb.close();
    return matResult;
}

int SQLconnect::sqlQuery_resetBom(QString query){
        QSqlQuery mssqlQuery(msdb);
        qDebug()<<"传入的sql语句为:"<<query;
         return mssqlQuery.exec(query);
//清除所有BOM信息


//    msdbQuery("use db_demo");
//    this->msdbQuery("select * from sysdatabases");
    //QMessageBox::about(NULL,"title","nihao");
}

//int SQLconnect::testing(){
//    while (1) {
//        QMessageBox::about(NULL,"1","1");
//        return 0;
//    }
//}
