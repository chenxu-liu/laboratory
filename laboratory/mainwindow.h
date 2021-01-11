#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"student.h"
#include "teacher.h"
#include "admin.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_student_login_clicked();

    void on_pushButton_admin_login_clicked();

    void on_pushButton_techer_login_clicked();

private:
    Ui::MainWindow *ui;
    student * stu;
    teacher * teac;
    admin* ad;
};

#endif // MAINWINDOW_H
