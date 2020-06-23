#include "sqlctrl.h"

sqlCtrl::sqlCtrl(QObject *parent) : QObject(parent)
{
    sqlCon= new SQLconnect();
    w = new Widget();
//    connect(w->execPushbtn,&QPushButton::clicked,sqlCon,&SQLconnect::execPushbtnClicked);//直接连接sqlCon, 无法传递参数, 测试.
    connect(w->checkBomBtn,&QPushButton::clicked,this,&sqlCtrl::bomBtnClicked);
    connect(w->execBtn,&QPushButton::clicked, this, &sqlCtrl::execBtnClicked);
    connect(w->DBComboxBox, &QComboBox::currentTextChanged, this, &sqlCtrl::selectDB);

    w->show();
}

int sqlCtrl::bomBtnClicked(){
//    QString str = QString("%1").arg(w->lineEditMatNum->text());
    QString str = QString("select top 1 * from mf_bom where bom_no='%1->'").arg(w->lineEditMatNum->text());
    qDebug()<<"在widget的数据为:" <<w->lineEditMatNum->text()<<endl;
    if(w){
        qDebug()<<str;
        //sqlCon->msdbQuery(w->lineEditMatNum->text());
    }else{
        qDebug()<<"野指针w";
    }
    if(sqlCon){
        //qDebug()<<w->lineEditMatNum->text();
        QVector <QString> bomResult=sqlCon->sqlQuery_chkBom(str);
        //更新UI显示
        w->chkManLabel->setText(bomResult[1]);
        w->chkDateLabel->setText(bomResult[2].left(10));
        w->usrManLabel->setText(bomResult[0]);
        w->usrDateLabel->setText(bomResult[3].left(10));

        for(int i=0;i<bomResult.count();i++){
            qDebug()<<bomResult[i];
        }
    }else{
        qDebug()<<"野指针sqlCon";
    }
    return 0;
//    sqlCon->msdbQuery(w->lineEditMatNum->text());//select * from sysdatabases
}
int sqlCtrl::execBtnClicked(){
    QString str_update_MF_BOM = QString("update mf_bom set usr='E001', eff_dd=null,chk_man=null where bom_no='%1->'").arg(w->lineEditMatNum->text());
    QString str_delete_WF_FLOW_INST = QString("delete  wf_flow_inst where bil_no='%1->'").arg(w->lineEditMatNum->text());
    QString res="";
    qDebug()<<"execBtnClicked";
    if(sqlCon){
        int i = sqlCon->sqlQuery_resetBom(str_update_MF_BOM);
        int j = sqlCon->sqlQuery_resetBom(str_delete_WF_FLOW_INST);
        bomBtnClicked();
        return i+j;
        }else{
            qDebug()<<"野指针sqlCon";
            return 1;
        }
}

int sqlCtrl::selectDB(){
    QString text= w->DBComboxBox->currentText();
    if(text=="惠州"){
        int i = sqlCon->sqlSelectDB("JHX");
        qDebug()<<"selectDB JHX";
        return i;
    }else if(text=="安徽"){
        int j = sqlCon->sqlSelectDB("MAS");
        qDebug()<<"selectDB MAS";
        return j;
    }else{
        qDebug()<<"ELES";
        return 1;
    }
}
