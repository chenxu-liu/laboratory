#ifndef MTEACHER_H
#define MTEACHER_H

#include <QMainWindow>

namespace Ui {
class mteacher;
}

class mteacher : public QMainWindow
{
    Q_OBJECT

public:
    explicit mteacher(QWidget *parent = 0);
    ~mteacher();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::mteacher *ui;
};

#endif // MTEACHER_H
