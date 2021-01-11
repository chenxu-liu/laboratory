#include "add_student.h"
#include "ui_add_student.h"
#include<QSqlQueryModel>
#include<QDebug>
#include<QMessageBox>
#include <QSqlQuery>
add_student::add_student(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::add_student)
{
    ui->setupUi(this);
}

add_student::~add_student()
{
    delete ui;
}

void add_student::on_pushButton_clicked()
{   QString no;
    no=ui->lineEdit->text();
    QString sql1;
    sql1="select * from student_information where S_no='"+no+"'";
    QSqlQuery query;

    query.exec(sql1);
    if(query.next())
    {
        QString sql2,sql3;
        QSqlQueryModel *model2=new QSqlQueryModel;
        sql2="update student_information set S_lab='"+this->lab_no+"' where S_no='"+no+"'";
         model2->setQuery(sql2);
        QMessageBox::about(NULL,"提示","添加学生成功");
    }
    else
    {
         QMessageBox::about(NULL,"警告","系统中没有这位学生");

    }
}
