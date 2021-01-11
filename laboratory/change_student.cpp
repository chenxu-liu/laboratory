#include "change_student.h"
#include "ui_change_student.h"
#include<QSqlQueryModel>
#include<QDebug>
#include<QMessageBox>
#include <QSqlQuery>
change_student::change_student(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::change_student)
{
    ui->setupUi(this);
}

change_student::~change_student()
{
    delete ui;
}

void change_student::on_pushButton_clicked()
{
    QString number,no;
    no=ui->lineEdit->text();
    number=ui->lineEdit_2->text();
    QString sql3;
    QSqlQuery query2;
    sql3="select  * from student_information where S_no='"+no+"'";
    query2.exec(sql3);
    if(query2.next())
    {    QString sql2;
        QSqlQueryModel *model2=new QSqlQueryModel;

        if(number!=nullptr){
            sql2="update student_information set S_number='"+number+"' where S_no='"+no+"'";
             model2->setQuery(sql2);
        }
        QMessageBox::about(NULL,"提示","成绩修改成功");

    }
    else
    {   QMessageBox::about(NULL,"警告","系统中没有这位学生");

    }

}
