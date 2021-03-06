#ifndef PERSONWINDOW_H
#define PERSONWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include "personrepository.h"
namespace Ui {
class PersonWindow;
}

class PersonWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PersonWindow(QWidget *parent = nullptr);
    ~PersonWindow();
    PersonRepository* get_currPersonRepository();

signals:
    void firstWindow();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::PersonWindow *ui;
    PersonRepository persons;
};

#endif // PERSONWINDOW_H
