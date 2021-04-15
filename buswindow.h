#ifndef BUSWINDOW_H
#define BUSWINDOW_H

#include <QWidget>
#include <QString>
#include <QMessageBox>
#include <busrepository.h>
namespace Ui {
class BusWindow;
}

class BusWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BusWindow(QWidget *parent = nullptr);
    ~BusWindow();
    BusRepository* get_currBusRepository();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::BusWindow *ui;
    BusRepository buses;
};

#endif // BUSWINDOW_H
