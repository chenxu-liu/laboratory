#ifndef STUDENT_H
#define STUDENT_H

#include <QMainWindow>

namespace Ui {
class student;
}

class student : public QMainWindow
{
    Q_OBJECT

public:
    explicit student(QWidget *parent = 0);
    ~student();
    QString stuName;
    void interface_stu();
private slots:
    void on_pushButton_search_teacher_clicked();


    void on_pushButton_lab_clicked();

    void on_pushButton_clicked();

private:
    Ui::student *ui;
};

#endif // STUDENT_H
