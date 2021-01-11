#include "teacher.h"
#include "ui_teacher.h"
#include<QSqlQueryModel>
#include<QDebug>

#include<QMessageBox>
#include <QSqlQuery>
//#pragma execution_character_set("utf-8")

teacher::teacher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::teacher)
{
    ui->setupUi(this);
    cstu = new change_student;
    dstu = new delete_student;
    astu = new add_student;
    connect(ui->lineEdit_findname,SIGNAL(textChanged(QString)),this,SLOT(find()));//将字符变化的事件，与某函数连接
}

teacher::~teacher()
{
    delete ui;
}

void teacher::find()
{
    QSqlQueryModel *modell=new QSqlQueryModel;
    QString find,sql0;
    find=ui->lineEdit_findname->text();
    if(ui->comboBox->currentText()=="学号")
    {
        sql0="select S_no as 学号,S_name as 姓名 ,S_age as 年龄 ,S_grade as 年级, S_sex as 性别,S_sdept as 专业,S_lab as 实验室,S_number as 成绩 from student_information where  S_lab = '"+this->teacher_lab+"' and S_no LIKE '%"+find+"%'";
    }
    else if(ui->comboBox->currentText()=="姓名")
    {
         sql0="select S_no as 学号,S_name as 姓名 ,S_age as 年龄 ,S_grade as 年级, S_sex as 性别,S_sdept as 专业,S_lab as 实验室 ,S_number as 成绩 from student_information where  S_lab = '"+this->teacher_lab+"' and S_name LIKE '%"+find+"%'";
    }
    else if(ui->comboBox->currentText()=="成绩")
    {
         sql0="select S_no as 学号,S_name as 姓名 ,S_age as 年龄 ,S_grade as 年级, S_sex as 性别,S_sdept as 专业,S_lab as 实验室,S_number as 成绩  from student_information where  S_lab = '"+this->teacher_lab+"' and S_number LIKE '%"+find+"%'";
    }
    //sql0="select S_no as 学号,S_name as 姓名 ,S_age as 年龄 ,S_grade as 年级, S_sex as 性别,S_sdept as 专业,S_lab as 实验室 ,S_number as 成绩 from student_information where S_name LIKE '%"+find+"%'";
    modell->setQuery(sql0);
    ui->tableView->setModel(modell);

}
void teacher::on_pushButton_clicked()
{
    astu->lab_no = teacher_lab;
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    sql="select S_no as 学号,S_name as 姓名 ,S_age as 年龄 ,S_grade as 年级, S_sex as 男,S_sdept as 专业,S_lab as 实验室,S_number as 成绩 from student_information where S_lab = '"+this->teacher_lab+"'";
    model->setQuery(sql);
    ui->tableView->setModel(model);
}

void teacher::on_pushButton_4_clicked()
{
    QSqlQueryModel *modell=new QSqlQueryModel;
    QString find,sql0;
    if(ui->checkBox->isChecked())
    {
        if(ui->comboBox_2->currentText()=="学号")
        {
            sql0="select S_no as 学号,S_name as 姓名 ,S_age as 年龄 ,S_grade as 年级, S_sex as 男,S_sdept as 专业,S_lab as 实验室,S_number as 成绩  from student_information  where  S_lab = '"+this->teacher_lab+"'  order by S_no desc";
        }
        else if(ui->comboBox_2->currentText()=="年龄")
        {
           sql0="select S_no as 学号,S_name as 姓名 ,S_age as 年龄 ,S_grade as 年级, S_sex as 男,S_sdept as 专业,S_lab as 实验室,S_number as 成绩  from student_information   where  S_lab = '"+this->teacher_lab+"'  order by S_age desc";
        }
        else if(ui->comboBox_2->currentText()=="成绩")
        {
             sql0="select S_no as 学号,S_name as 姓名 ,S_age as 年龄 ,S_grade as 年级, S_sex as 男,S_sdept as 专业,S_lab as 实验室 ,S_number as 成绩 from student_information  where  S_lab = '"+this->teacher_lab+"'  order by S_number desc";
        }
    }
    else
    {
        if(ui->comboBox_2->currentText()=="学号")
        {
            sql0="select S_no as 学号,S_name as 姓名 ,S_age as 年龄 ,S_grade as 年级, S_sex as 男,S_sdept as 专业,S_lab as 实验室 ,S_number as 成绩 from student_information  where  S_lab = '"+this->teacher_lab+"' order by S_no";
        }
        else if(ui->comboBox_2->currentText()=="年龄")
        {
           sql0="select S_no as 学号,S_name as 姓名 ,S_age as 年龄 ,S_grade as 年级, S_sex as 男,S_sdept as 专业,S_lab as 实验室 ,S_number as 成绩 from student_information where  S_lab = '"+this->teacher_lab+"'  order by S_age";
        }
        else if(ui->comboBox_2->currentText()=="成绩")
        {
             sql0="select S_no as 学号,S_name as 姓名 ,S_age as 年龄 ,S_grade as 年级, S_sex as 男,S_sdept as 专业,S_lab as 实验室,S_number as 成绩  from student_information  where  S_lab = '"+this->teacher_lab+"' order by S_number";
        }
    }
    modell->setQuery(sql0);
    ui->tableView->setModel(modell);
}

void teacher::on_pushButton_2_clicked()
{
    cstu->show();
}

void teacher::on_pushButton_5_clicked()
{
   astu->show();
}

void teacher::on_pushButton_3_clicked()
{
    dstu->show();
}
