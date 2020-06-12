#include "widget.h"
#include "ui_widget.h"
#include "sqlconnect.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    SQLconnect *sqlCon= new SQLconnect();
    //main layout
    QVBoxLayout *mainLayout = new QVBoxLayout();

    //选择数据库 widgets
//    DBComboxBox = new QComboBox();
//    QString *DBstr= new QString();
//    DBComboxBox->addItem(DBstr);

    //物料 widgets
    checkBomBtn = new QPushButton("查询料号");
    QRegExp matNumRegExp("[1-9+S]{1}[0-9+B+R]{1}[0-9]{3}[-]{1}[0-9]{4,5}");
    QLabel *labelMatNum = new QLabel("料号:");
    lineEditMatNum = new QLineEdit();
    lineEditMatNum->setValidator(new QRegExpValidator(matNumRegExp,this));
    QHBoxLayout *matLayout= new QHBoxLayout();
    matLayout->addWidget(labelMatNum);
    matLayout->addWidget(lineEditMatNum);
    matLayout->addWidget(checkBomBtn);


    //审核 widgets
    QLabel *chkLabel =new QLabel("审核:");
    chkManLabel =new QLabel("审核人");
    chkDateLabel =new QLabel("审核日期");
    QHBoxLayout *chkLayout = new QHBoxLayout();
    chkLayout->addWidget(chkLabel);
    chkLayout->addWidget(chkManLabel);
    chkLayout->addWidget(chkDateLabel);

    //用户 widgets
    QLabel *usrLabel=new QLabel("用户:");
    usrLabel->setAlignment(Qt::AlignLeft);
    usrManLabel= new QLabel("申请人");
    usrDateLabel=new QLabel("创建日期");

    QHBoxLayout *usrLayout=new QHBoxLayout();
    usrLayout->addWidget(usrLabel);
    usrLayout->addWidget(usrManLabel);
    usrLayout->addWidget(usrDateLabel);

    //执行 widgets
    execBtn = new QPushButton("重置所有信息");
    QHBoxLayout *execLayout = new QHBoxLayout();
    execLayout->addWidget(execBtn);


    //layout
    mainLayout->addLayout(matLayout);

    mainLayout->addLayout(chkLayout);
    mainLayout->addLayout(usrLayout);
    mainLayout->addLayout(execLayout);
//    mainLayout->setStretchFactor(matLayout,1);
//    mainLayout->setStretchFactor(chkLayout,1);
//    mainLayout->setStretchFactor(usrLayout,1);
//    mainLayout->setStretchFactor(execLayout,5);

    //set style
    setFixedSize(400,150);


    chkLabel->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    usrLabel->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

    chkManLabel->setAlignment(Qt::AlignCenter);
    chkDateLabel->setAlignment(Qt::AlignCenter);
    usrManLabel->setAlignment(Qt::AlignCenter);
    usrDateLabel->setAlignment(Qt::AlignCenter);

//    chkManLabel->setStyleSheet("border:1px solid #fff7e6;");
//    chkDateLabel->setStyleSheet("border:1px solid #fff7e6;");
//    usrManLabel->setStyleSheet("border:1px solid #fff7e6;");

    qDebug()<<geometry().width();
    qDebug()<<geometry().height();

    labelMatNum->setFixedSize(geometry().width()*1/5,geometry().height()/4);//料号

    chkManLabel->setFixedSize(geometry().width()*2/5,geometry().height()/4);//审核人
    chkDateLabel->setFixedSize(geometry().width()*2/5,geometry().height()/4);//审核日期
    usrManLabel->setFixedSize(geometry().width()*2/5,geometry().height()/4);//用户
    usrDateLabel->setFixedSize(geometry().width()*2/5,geometry().height()/4);//创建日期


    execBtn->setFixedSize(350,25);


    //main layout

    setLayout(mainLayout);

}

Widget::~Widget()
{
    delete ui;
}

