#ifndef SEARCH_TECHER_H
#define SEARCH_TECHER_H

#include <QMainWindow>

namespace Ui {
class search_techer;
}

class search_techer : public QMainWindow
{
    Q_OBJECT

public:
    explicit search_techer(QWidget *parent = 0);
    ~search_techer();
     QString techerName;
private slots:
     void on_pushButton_clicked();

private:
    Ui::search_techer *ui;
};

#endif // SEARCH_TECHER_H
