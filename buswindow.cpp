#include "buswindow.h"
#include "ui_buswindow.h"

BusWindow::BusWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BusWindow)
{
    ui->setupUi(this);

}

BusWindow::~BusWindow()
{
    delete ui;
}
BusRepository *BusWindow::get_currBusRepository(){
    return &buses;
}

void BusWindow::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}

void BusWindow::on_pushButton_2_clicked()
{
    QString gosNomer = this->ui->lineEditGos->text();
    QString type = this->ui->comboBox->currentText();
    Bus::BusType inp_type;
    if (type == "МАЗ")
        inp_type=Bus::MAZ;
    else if (type == "ЛИАЗ")
        inp_type=Bus::LIAZ;


    if (!buses.addBus(gosNomer, inp_type))
        QMessageBox::warning(this, "Что-то пошло не так", "Данная запись не была добавлена. \n Попробуйте другой госномер.");
    ui->textBrowser->setText(buses.get_fullBusRepos());
}

void BusWindow::on_pushButton_3_clicked()
{
    QString gosNomer = this->ui->lineEditGos->text();
    if (!buses.deleteBus(gosNomer))
        QMessageBox::warning(this, "Что-то пошло не так", "Такой записи нет. \n Попробуйте другой госномер.");
    ui->textBrowser->setText(buses.get_fullBusRepos());
}

void BusWindow::on_pushButton_4_clicked()
{
    ui->textBrowser->setText(buses.get_fullBusRepos());
}
