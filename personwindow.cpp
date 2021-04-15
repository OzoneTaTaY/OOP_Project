#include "personwindow.h"
#include "ui_personwindow.h"

PersonWindow::PersonWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonWindow)
{
    ui->setupUi(this);
}

PersonWindow::~PersonWindow()
{
    delete ui;
}
PersonRepository* PersonWindow::get_currPersonRepository(){
    return &persons;
}

void PersonWindow::on_pushButton_clicked()//к главной форме
{
    this->close();
    emit firstWindow();
}

void PersonWindow::on_pushButton_2_clicked()//добавление водителя
{
    QString stringID = ui->lineEdit_id->text();
    int id = stringID.toInt();
    QString name = ui->lineEdit_name->text();
    QString secName = ui->lineEdit_sec_n->text();
    QString stringAge = ui->lineEdit_age->text();
    int age = stringAge.toInt();
    QString stringSalary = ui->lineEdit_zp->text();
    int salary = stringSalary.toInt();
    QString dltype = ui->lineEdit_kat->text();
    QString dltime = ui->lineEdit_7->text();
    if ( !persons.addDriver(dltype,dltime,id,name,secName,age,salary)){
         QMessageBox::warning(this, "Что-то пошло не так", "Запись не была добавлена. \n Попробуйте другой ID.");
    }
    ui->textBrowser_d->setText(persons.get_drivers());
}

void PersonWindow::on_pushButton_3_clicked()//удалить водителя
{
    QString stringID = ui->lineEdit_id->text();
    int id = stringID.toInt();
    if ( !persons.deleteDriver(id)){
         QMessageBox::warning(this, "Что-то пошло не так", "Такой записи нет. \n Попробуйте другой ID.");
    }
    ui->textBrowser_d->setText(persons.get_drivers());
}

void PersonWindow::on_pushButton_5_clicked()//добавить кондуктора
{
    QString stringID = ui->lineEdit_id->text();
    int id = stringID.toInt();
    QString name = ui->lineEdit_name->text();
    QString secName = ui->lineEdit_sec_n->text();
    QString stringAge = ui->lineEdit_age->text();
    int age = stringAge.toInt();
    QString stringSalary = ui->lineEdit_zp->text();
    int salary = stringSalary.toInt();
    QString stringL = ui->lineEdit_8->text();
    unsigned int lisense = stringL.toInt();
    if ( !persons.addConductor(lisense,id,name,secName,age,salary)){
         QMessageBox::warning(this, "Что-то пошло не так", "Запись не была добавлена. \n Попробуйте другой ID.");
    }
    ui->textBrowser_c->setText(persons.get_conductors());
}


void PersonWindow::on_pushButton_6_clicked()//удалить кондуктора
{
    QString stringID = ui->lineEdit_id->text();
    int id = stringID.toInt();
    if ( !persons.deleteConductor(id)){
         QMessageBox::warning(this, "Что-то пошло не так", "Такой записи нет. \n Попробуйте другой ID.");
    }
    ui->textBrowser_c->setText(persons.get_conductors());
}

void PersonWindow::on_pushButton_4_clicked()//водитель каникулы
{
    QString stringID = ui->lineEdit_id->text();
    int id = stringID.toInt();
    if ( !persons.driver_vacation(id)){
         QMessageBox::warning(this, "Что-то пошло не так", "Такой записи нет. \n Попробуйте другой ID.");
    }
    ui->textBrowser_d->setText(persons.get_drivers());
    ui->textBrowser_v->setText(persons.get_chill_persons());
}

void PersonWindow::on_pushButton_7_clicked()//кондуктор каникулы
{
    QString stringID = ui->lineEdit_id->text();
    int id = stringID.toInt();
    if ( !persons.conductor_vacation(id)){
         QMessageBox::warning(this, "Что-то пошло не так", "Такой записи нет. \n Попробуйте другой ID.");
    }
    ui->textBrowser_c->setText(persons.get_conductors());
    ui->textBrowser_v->setText(persons.get_chill_persons());
}

void PersonWindow::on_pushButton_8_clicked()//обновить
{
    ui->textBrowser_d->setText(persons.get_drivers());
    ui->textBrowser_c->setText(persons.get_conductors());
    ui->textBrowser_v->setText(persons.get_chill_persons());
}
