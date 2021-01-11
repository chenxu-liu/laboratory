#ifndef DELETE_STUDENT_H
#define DELETE_STUDENT_H

#include <QMainWindow>

namespace Ui {
class delete_student;
}

class delete_student : public QMainWindow
{
    Q_OBJECT

public:
    explicit delete_student(QWidget *parent = 0);
    ~delete_student();

private slots:
    void on_pushButton_clicked();

private:
    Ui::delete_student *ui;
};

#endif // DELETE_STUDENT_H
