#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include "mstduent.h"
#include "mteacher.h"
namespace Ui {
class admin;
}

class admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = 0);
    ~admin();
    QString adminname;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::admin *ui;
    mstduent * mstu;
    mteacher * mtea;
};

#endif // ADMIN_H
