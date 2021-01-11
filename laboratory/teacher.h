#ifndef TEACHER_H
#define TEACHER_H

#include <QMainWindow>
#include "change_student.h"
#include "delete_student.h"
#include "add_student.h"
namespace Ui {
class teacher;
}

class teacher : public QMainWindow
{
    Q_OBJECT

public:
    explicit teacher(QWidget *parent = 0);
    void init();
    QString teacher_lab;
    ~teacher();

private slots:
    void on_pushButton_clicked();
     void find();
     void on_pushButton_4_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_5_clicked();

     void on_pushButton_3_clicked();

private:
    Ui::teacher *ui;

    change_student * cstu;
    delete_student * dstu;
    add_student * astu;
};

#endif // TEACHER_H
