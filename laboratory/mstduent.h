#ifndef MSTDUENT_H
#define MSTDUENT_H

#include <QMainWindow>

namespace Ui {
class mstduent;
}

class mstduent : public QMainWindow
{
    Q_OBJECT

public:
    explicit mstduent(QWidget *parent = 0);
    ~mstduent();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::mstduent *ui;
};

#endif // MSTDUENT_H
