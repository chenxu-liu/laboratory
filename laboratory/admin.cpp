#include "admin.h"
#include "ui_admin.h"

admin::admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin)
{
    mstu = new mstduent;
    mtea = new mteacher;
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_2_clicked()
{
    mstu->show();
}

void admin::on_pushButton_clicked()
{
    mtea->show();
}
