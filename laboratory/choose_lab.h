#ifndef CHOOSE_LAB_H
#define CHOOSE_LAB_H

#include <QMainWindow>

namespace Ui {
class choose_lab;
}

class choose_lab : public QMainWindow
{
    Q_OBJECT

public:
    explicit choose_lab(QWidget *parent = 0);
    QString studentname;
    ~choose_lab();

private slots:
    void on_pushButton_clicked();

private:
    Ui::choose_lab *ui;
};

#endif // CHOOSE_LAB_H
