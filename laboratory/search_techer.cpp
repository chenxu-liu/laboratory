#include "search_techer.h"
#include "ui_search_techer.h"
#include<QSqlQueryModel>
#include<QDebug>
#include<QMessageBox>
#include <QSqlQuery>
search_techer::search_techer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::search_techer)
{
    ui->setupUi(this);
}

search_techer::~search_techer()
{
    delete ui;
}

void search_techer::on_pushButton_clicked()
{
     QString pushid=ui->lineEdit->text();
     QString sql_tec,sql1;
     QSqlQuery query2;
     sql1="select * from teacher_information where T_no ='"+pushid+"'";
     query2.exec(sql1);
     if(query2.next()){
         sql_tec="select T_no as 教师号, T_name as 姓名, T_sex as 性别,T_age as 年龄,T_phone as 手机号,Lab_no as 实验室号 from teacher_information where T_no='"+pushid+"'";
         QSqlQueryModel *modely=new QSqlQueryModel;

         modely->setQuery(sql_tec);
         ui->tableView->setModel(modely);

     }else{
          QMessageBox::about(NULL,"提示","老师不存在");
     }

}
