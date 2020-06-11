#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QSplitter>
#include <QLabel>
#include <QHBoxLayout>
#include <QObject>
#include <QRegExp>
#include <QRegExpValidator>
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public:
//    QRegExp *matNumRegExp;
    QComboBox *DBComboxBox; //选择数据库
    QPushButton *checkBomBtn;//查询料号按钮
    QLineEdit *lineEditMatNum;//料号输入框
    QLabel *chkManLabel;//审核人标签
    QLabel *chkDateLabel;//审核日期
    QLabel *usrManLabel;//用户标签
    QLabel *usrDateLabel;//创建日期
    QPushButton *execBtn;//执行按钮

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
