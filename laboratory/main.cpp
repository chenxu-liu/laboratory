#include "mainwindow.h"
#include <QApplication>
#include<QDebug>
#include<QSqlDatabase>
bool opendatabase();
int main(int argc, char *argv[])
{
    opendatabase();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
bool opendatabase()
{   QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");      //连接数据库主机
    db.setPort(3306);                 //连接数据库端口号，与设置一致
    db.setDatabaseName("laboratory");      //连接数据库名，与设置一致
    db.setUserName("root");          //数据库用户名
    db.setPassword("123");    //数据库密码，与设置一致
    db.open();
    if(db.open())
    {
        qDebug()<<"open success";
        return true;
    }
    else
    {
        qDebug()<<"open failed";
        return false;
    }
}
