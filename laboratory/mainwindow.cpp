#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSqlQueryModel>
#include<QDebug>
#include<QMessageBox>
#include <QSqlQuery>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stu=new student;
    //teac =new teacher;
    ad = new admin;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_student_login_clicked()
{
    QString sql1,sql2;
    QString sql3;

    QString inputName=ui->lineEdit->text();
    QString inputPassword=ui->lineEdit_2->text();
     qDebug()<<inputName << inputPassword;
     QSqlQuery query;
     sql1="select * from user_information where user_id='"+inputName+"'";
     query.exec(sql1);
     if(query.next()){
         if(inputPassword==query.value(1).toString()&&query.value(3).toString() == "学生")
         {  qDebug()<<inputName;
             QMessageBox::about(NULL,"提示","用户登录成功");
             //student* stu=new student;
             stu->stuName=inputName;//将登陆的学生信息读取出来
             stu->show();
             stu->interface_stu();
         }
         else
         {   qDebug()<<"1";
             QMessageBox::about(NULL,"提示","用户名或密码错误");

         }
     }
}

void MainWindow::on_pushButton_admin_login_clicked()
{
    QString sql1,sql2;
    QString sql3;

    QString inputName=ui->lineEdit->text();
    QString inputPassword=ui->lineEdit_2->text();
     qDebug()<<inputName << inputPassword;
     QSqlQuery query;
     sql1="select * from user_information where user_id='"+inputName+"'";
     query.exec(sql1);
     if(query.next()){
         if(inputPassword==query.value(1).toString()&&query.value(3).toString() == "管理员")
         {  qDebug()<<inputName;
             QMessageBox::about(NULL,"提示","用户登录成功");
             //student* stu=new student;

             ad->adminname=inputName;
             ad->show();

         }
         else
         {   qDebug()<<"1";
             QMessageBox::about(NULL,"提示","用户名或密码错误");

         }
     }
}

void MainWindow::on_pushButton_techer_login_clicked()
{
    QString sql1,sql2;
    QString sql3;

    QString inputName=ui->lineEdit->text();
    QString inputPassword=ui->lineEdit_2->text();
     qDebug()<<inputName << inputPassword;
     QSqlQuery query,query2;
     sql1="select * from user_information where user_id='"+inputName+"'";
     query.exec(sql1);
     if(query.next()){
         if(inputPassword==query.value(1).toString()&&query.value(3).toString() == "教师")
         {  qDebug()<<inputName;
             QMessageBox::about(NULL,"提示","用户登录成功");
             //student* stu=new student;
               sql1="select * from teacher_information where T_no='"+inputName+"'";
               qDebug()<<sql1;
             query2.exec(sql1);
              teac =new teacher;
             if(query2.next()){
                  teac->teacher_lab=query2.value(5).toString();
             }
             //sql1="select S_no as 学号,S_name as 姓名 ,S_age as 年龄 ,S_grade as 年级, S_sex as 性别,S_sdept as 专业,S_lab as 实验室  from student_information where S_lab = '"+teac->teacher_lab+"'";
             qDebug()<<teac->teacher_lab;
             //teac->teacher_id=inputName;//将登陆的教师信息读取出来
             teac->show();
             //teac->interface_stu();
         }
         else
         {
             QMessageBox::about(NULL,"提示","用户名或密码错误");

         }
     }
}
