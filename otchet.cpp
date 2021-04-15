#include "otchet.h"
#include "ui_otchet.h"

Otchet::Otchet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Otchet)
{
    ui->setupUi(this);
    ui->textBrowser->hide();
    ui->pushButton->hide();
}

Otchet::~Otchet()
{
    delete ui;
}

void Otchet::on_pushButton_clicked()
{
    ui->pushButton_2->show();
    ui->textBrowser->hide();
    ui->pushButton->hide();
    this->close();
    emit firstWindow();
}
void Otchet::set_data(QString data){
    this->data = data;
}
void Otchet::on_pushButton_2_clicked()
{
    ui->pushButton_2->hide();
    ui->textBrowser->show();
    ui->pushButton->show();
    ui->textBrowser->setText(data);
}
