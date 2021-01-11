#include "mteacher.h"
#include "ui_mteacher.h"
#include<QSqlQueryModel>
#include<QDebug>
#include<QMessageBox>
#include <QSqlQuery>
mteacher::mteacher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mteacher)
{
    ui->setupUi(this);
}

mteacher::~mteacher()
{
    delete ui;
}

void mteacher::on_pushButton_clicked()
{
    QString name,no,age,sex,phone,lab,password,role;
    no=ui->lineEdit->text();
    name=ui->lineEdit_2->text();
    age=ui->lineEdit_4->text();
    phone=ui->lineEdit_5->text();
    sex=ui->lineEdit_3->text();
    //sdept=ui->lineEdit_6->text();
    lab=ui->lineEdit_6->text();
    password = ui->lineEdit_7->text();
    role = "教师";
    if(ui->radioButton_add->isChecked())
    {
        QString sql1;
        sql1="select * from teacher_information where T_no='"+no+"'";
        QSqlQuery query;

        query.exec(sql1);

        if(query.next())
        {
            QMessageBox::about(NULL,"警告","系统中已有这位学生");
        }
        else
        {
            QString sql2,sql3;
            QSqlQueryModel *model2=new QSqlQueryModel;
            sql2="insert into teacher_information values ('"+no+"','"+name+"','"+sex+"','"+age+"','"+phone+"','"+lab+"')";
            model2->setQuery(sql2);
            QSqlQuery query;
            sql3 = "insert into user_information values ('"+no+"','"+password+"','"+name+"','"+role+"')";

            query.exec(sql3);
            QMessageBox::about(NULL,"提示","系统信息添加成功");
        }

    }
    else if(ui->radioButton_change->isChecked())
    {
        QString sql3;
        QSqlQuery query2;
        sql3="select  * from teacher_information where T_no='"+no+"'";
        query2.exec(sql3);


        if(query2.next())
        {    QString sql2;
            QSqlQueryModel *model2=new QSqlQueryModel;
            if(name!=nullptr){
                sql2="update teacher_information set T_name='"+name+"' where T_no='"+no+"'";
                 model2->setQuery(sql2);
                 sql2="update user_information set user_name='"+name+"' where user_id='"+no+"'";
                  model2->setQuery(sql2);
            }
            if(age!=nullptr){
                sql2="update teacher_information set T_age='"+age+"' where T_no='"+no+"'";
                 model2->setQuery(sql2);
            }

            if(sex!=nullptr){
                sql2="update teacher_information set T_sex='"+sex+"' where T_no='"+no+"'";
                 model2->setQuery(sql2);
            }

            if(lab!=nullptr){
                sql2="update teacher_information set Lab_no='"+lab+"' where  T_no='"+no+"'";
                 model2->setQuery(sql2);
            }
            if(password!=nullptr){
                sql2="update user_information set user_password='"+password+"' where user_id='"+no+"'";
                 model2->setQuery(sql2);
            }
            if(phone!=nullptr){
                sql2="update teacher_information set T_phone='"+phone+"' where  T_no='"+no+"'";
                 model2->setQuery(sql2);
            }
            QMessageBox::about(NULL,"提示","系统信息修改成功");

        }
        else
        {   QMessageBox::about(NULL,"警告","系统中没有这位学生");

        }

    }
    else if(ui->radioButton_delete->isChecked())
    {
        QString no,sql,sql2;
        no=ui->lineEdit->text();
        sql2="select * from teacher_information where T_no='"+no+"'";
        QSqlQuery query;
        query.exec(sql2);
        if(query.next())
        {
            sql="delete from teacher_information where T_no='"+no+"'";
             query.exec(sql);
             sql="delete from user_information where user_id='"+no+"'";
              query.exec(sql);
            QMessageBox::about(NULL,"提示","删除成功");

        }
        else
        {
            QMessageBox::about(NULL,"警告","系统中并无此人");
        }

    }
    else
    {
        QMessageBox::about(NULL,"警告","请选择你要进行的操作");//两个radio btn必须要选择一个
    }
}

void mteacher::on_pushButton_2_clicked()
{
    close();
}
