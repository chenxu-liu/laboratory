#include "delete_student.h"
#include "ui_delete_student.h"
#include<QSqlQueryModel>
#include<QDebug>
#include<QMessageBox>
#include <QSqlQuery>
delete_student::delete_student(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::delete_student)
{
    ui->setupUi(this);
}

delete_student::~delete_student()
{
    delete ui;
}

void delete_student::on_pushButton_clicked()
{

    QString no,sql,sql2,lab;
    lab="";
    no=ui->lineEdit->text();
    sql2="select * from student_information where S_no='"+no+"'";
    QSqlQuery query;
    query.exec(sql2);
    if(query.next())
    {

        sql2="update student_information set S_lab='"+lab+"' where S_no='"+no+"'";
         query.exec(sql2);
        QMessageBox::about(NULL,"提示","成功将该学生从本实验室删除");

    }
    else
    {
        QMessageBox::about(NULL,"警告","系统中并无此人");
    }
}
