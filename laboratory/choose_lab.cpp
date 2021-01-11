#include "choose_lab.h"
#include "ui_choose_lab.h"
#include<QSqlQueryModel>
#include<QDebug>
#include<QMessageBox>
#include <QSqlQuery>
choose_lab::choose_lab(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::choose_lab)
{
    ui->setupUi(this);
}

choose_lab::~choose_lab()
{
    delete ui;
}

void choose_lab::on_pushButton_clicked()
{
    QString pushlab=ui->lineEdit->text();
    QString sql_stu,sql_lab,sql1;
    QSqlQuery query2;
    sql1="select * from lab_information where Lab_no ='"+pushlab+"'";
    query2.exec(sql1);
    if(query2.next()){
        QSqlQuery query;
       sql_lab = "update student_information set S_lab="+pushlab+" WHERE S_no="+studentname;
       query.exec(sql_lab);

       sql_stu="select S_no as 学号, S_name as 姓名,S_age as 年龄, S_grade as 年龄,S_sex as 性别,S_sdept as 专业,S_lab as 实验室号 from student_information where S_no='"+studentname+"'";
       QSqlQueryModel *modely=new QSqlQueryModel;

       modely->setQuery(sql_stu);
       ui->tableView->setModel(modely);

    }else{
         QMessageBox::about(NULL,"提示","实验室不存在");
    }
}
