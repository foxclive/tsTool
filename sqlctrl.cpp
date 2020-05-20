#include "sqlctrl.h"

sqlCtrl::sqlCtrl(QObject *parent) : QObject(parent)
{
    sqlCon= new SQLconnect();
    w = new Widget();


//    connect(w->execPushbtn,&QPushButton::clicked,sqlCon,&SQLconnect::execPushbtnClicked);//直接连接sqlCon, 无法传递参数, 测试.
    connect(w->checkBomBtn,&QPushButton::clicked,this,&sqlCtrl::checkBomBtnClicked);
    connect(w->execBtn,&QPushButton::clicked, this, &sqlCtrl::execBtnClicked);



    w->show();
}

int sqlCtrl::checkBomBtnClicked(){
//    QString str = QString("%1").arg(w->lineEditMatNum->text());
    QString str = QString("select top 1 * from mf_bom where bom_no='%1->'").arg(w->lineEditMatNum->text());
    qDebug()<<"在widget的数据为:" <<w->lineEditMatNum->text()<<endl;
    qDebug()<<"进入SLOT;";
    if(w){
        qDebug()<<str;
        //sqlCon->msdbQuery(w->lineEditMatNum->text());
    }else{
        qDebug()<<"野指针w";
    }
    if(sqlCon){
        //qDebug()<<w->lineEditMatNum->text();
        QString checkBomResult=sqlCon->msdbQuery(str);
        if(checkBomResult.count()>1){
            //更新标签
            for(int i=0;i<checkBomResult.count();i++){
                qDebug()<<checkBomResult[i];
            }
        }
    }else{
        qDebug()<<"野指针sqlCon";
    }


    return 0;
//    sqlCon->msdbQuery(w->lineEditMatNum->text());//select * from sysdatabases

}
int sqlCtrl::execBtnClicked(){
    qDebug()<<"execBtnClicked";
    return 0;
}
