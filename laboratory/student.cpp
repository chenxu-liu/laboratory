#include "student.h"
#include "ui_student.h"
#include "search_techer.h"
#include "choose_lab.h"
#include<QSqlQueryModel>
#include<QDebug>
#include<QMessageBox>
#include <QSqlQuery>
student::student(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::student)
{
    ui->setupUi(this);
}

student::~student()
{
    delete ui;
}
void student::interface_stu(){
    //qDebug()<<stuName;
    QString sql_stu;
    sql_stu="select Lab_no as 实验室号, Lab_loc as 实验室位置, Lab_type as 实验室类型,Lab_task as 实验室课题,T_no as 负责教师号 from lab_information";
    QSqlQueryModel *modelx=new QSqlQueryModel;

    modelx->setQuery(sql_stu);
    ui->tableView->setModel(modelx);
}



void student::on_pushButton_search_teacher_clicked()
{
    search_techer* tec=new search_techer;

    tec->show();

}


void student::on_pushButton_lab_clicked()
{
    choose_lab * lab = new choose_lab;
    lab->studentname=this->stuName;//将登陆的学生信息读取出来
    lab->show();
}

void student::on_pushButton_clicked()
{
    close();
}
