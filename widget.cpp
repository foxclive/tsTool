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

    //material widgets
    checkBomBtn = new QPushButton("查询料号");
    QLabel *labelMatNum = new QLabel("料号");
    lineEditMatNum = new QLineEdit();
    QHBoxLayout *matLayout= new QHBoxLayout();
    matLayout->addWidget(labelMatNum);
    matLayout->addWidget(lineEditMatNum);
    matLayout->addWidget(checkBomBtn);


    //check widgets
    QLabel *chkLabel =new QLabel("审核");
    chkLabel->setAlignment(Qt::AlignLeft);
    QLabel *chkManLabel =new QLabel("审核人");
    chkManLabel->setStyleSheet("border:1px solid black;");
    QLabel *chkDateLabel =new QLabel("审核日期");
    chkDateLabel->setStyleSheet("border:1px solid black;");
    QHBoxLayout *chkLayout = new QHBoxLayout();
    chkLayout->addWidget(chkLabel);
    chkLayout->addWidget(chkManLabel);
    chkLayout->addWidget(chkDateLabel);

    //user widgets
    QLabel *usrLabel=new QLabel("申请人");
    usrLabel->setAlignment(Qt::AlignLeft);
    QLabel *usrManLabel= new QLabel("用户");
    QHBoxLayout *usrLayout=new QHBoxLayout();
    usrLayout->addWidget(usrLabel);
    usrLayout->addWidget(usrManLabel);

    //exec widgets
    execBtn = new QPushButton("重置所有信息");
    execBtn->setFixedSize(350,20);

    QHBoxLayout *execLayout = new QHBoxLayout();
    execLayout->addWidget(execBtn);


    //layout
    mainLayout->addLayout(matLayout);
//    QSplitter *matLine =new QSplitter(Qt::Horizontal);
//    mainLayout->addWidget(matLine);
    QFrame *matLine=new QFrame();
    matLine->setStyleSheet("border:none;background-color:#000000; max-height : 1px;");
    mainLayout->addWidget(matLine);
    mainLayout->addLayout(chkLayout);
//    QLine *chkLine =new QLine();
    mainLayout->addLayout(usrLayout);
//    QLine *usrLine =new QLine();
    mainLayout->addLayout(execLayout);
//    mainLayout->setStretchFactor(matLayout,1);
//    mainLayout->setStretchFactor(chkLayout,1);
//    mainLayout->setStretchFactor(usrLayout,1);
//    mainLayout->setStretchFactor(execLayout,5);



    //main layout
    setFixedSize(400,200);
    setLayout(mainLayout);
    
}

Widget::~Widget()
{
    delete ui;
}

