#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    buswindow = new BusWindow();
    connect(buswindow, &BusWindow::firstWindow, this, &MainWindow::show);
    personwindow = new PersonWindow();
    connect(personwindow, &PersonWindow::firstWindow, this, &MainWindow::show);
    otchetwindow = new Otchet();
    connect(otchetwindow, &Otchet::firstWindow, this,&MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    buswindow->show();
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    personwindow->show();
    this->close();
}

void MainWindow::on_pushButton_3_clicked()//открыть путевую
{
     QString stringIdBill = ui->lineEdit_id->text();
     int idBill = stringIdBill.toInt();
     QString gosnomer = ui->lineEdit_gosnomer->text();
     int fare = ui->lineEdit_fare->text().toInt();
     int idDriver = ui->lineEdit_idD->text().toInt();
     int idConductor = ui->lineEdit_idC->text().toInt();
     PersonRepository* persons = personwindow->get_currPersonRepository();
     BusRepository* buses = buswindow->get_currBusRepository();
     if (!persons->driver_work(idDriver, false)){
         QMessageBox::warning(this, "Что-то пошло не так", "Запись не была добавлена. \n Попробуйте другой ID Водителя.");
     }else if (!persons->conductor_work(idConductor,false)){
         QMessageBox::warning(this, "Что-то пошло не так", "Запись не была добавлена. \n Попробуйте другой ID Кондуктора.");
         persons->driver_work(idDriver, true);
     }else if (!buses->changeStatusWorkPark(gosnomer,false)){
         QMessageBox::warning(this, "Что-то пошло не так", "Запись не была добавлена. \n Попробуйте другой госномер.");
         persons->driver_work(idDriver, true);
         persons->conductor_work(idConductor,true);
     }else if (!bills.addNewWayBill(idBill, gosnomer,idDriver,idConductor,fare)){
         QMessageBox::warning(this, "Что-то пошло не так", "Запись не была добавлена. \n Попробуйте другой ID накладной.");
         persons->driver_work(idDriver, true);
         persons->conductor_work(idConductor,true);
         buses->changeStatusWorkPark(gosnomer,true);
     }
     ui->textBrowser->setText(bills.get_openBills());


}

void MainWindow::on_pushButton_4_clicked()//открыть ремонтную
{
    QString stringIdBill = ui->lineEdit_id->text();
    int idBill = stringIdBill.toInt();
    QString gosnomer = ui->lineEdit_gosnomer->text();
    int cost = ui->lineEdit_cost->text().toInt();
    QString descrb = ui->textEdit->toPlainText();
    BusRepository* buses = buswindow->get_currBusRepository();
    if (!buses->changeStatusRepairPark(gosnomer,false)){
             QMessageBox::warning(this, "Что-то пошло не так", "Запись не была добавлена. \n Попробуйте другой госномер.");
    }else if (!bills.addNewRepairBill(cost,descrb,idBill, gosnomer)){
        QMessageBox::warning(this, "Что-то пошло не так", "Запись не была добавлена. \n Попробуйте другой ID накладной.");
        buses->changeStatusRepairPark(gosnomer,true);
    }
    ui->textBrowser->setText(bills.get_openBills());
}

void MainWindow::on_pushButton_5_clicked()//закрыть путевую
{
    PersonRepository* persons = personwindow->get_currPersonRepository();
    BusRepository* buses = buswindow->get_currBusRepository();
    QString stringIdBill = ui->lineEdit_id->text();
    int idBill = stringIdBill.toInt();
    int nums = ui->lineEdit_num->text().toInt();
    int idDriver = bills.get_idDriver(idBill);
    int idConductor = bills.get_idConductor(idBill);
    QString gosnomer = bills.get_gosnomerWay(idBill);
    if (gosnomer == NULL) {
        QMessageBox::warning(this, "Что-то пошло не так", "Накладная не была закрыта. \n Попробуйте другой ID накладной.");
    }else if (idDriver==-1){
        QMessageBox::warning(this, "Что-то пошло не так", "Накладная не была закрыта. \n Попробуйте другой ID накладной.");
    }else if (idConductor==-1){
        QMessageBox::warning(this, "Что-то пошло не так", "Накладная не была закрыта. \n Попробуйте другой ID накладной.");
    }else if (!bills.finishWayBill(idBill,nums)){
        QMessageBox::warning(this, "Что-то пошло не так", "Накладная не была закрыта. \n Попробуйте другой ID накладной.");
    }else{
        if (!buses->changeStatusWorkPark(gosnomer, true)){
            QMessageBox::warning(this, "Что-то пошло не так", "Накладная закрыта. \n Но статус автобуса не поменялся.");
        }
        if(!persons->driver_work(idDriver, true)){
            QMessageBox::warning(this, "Что-то пошло не так", "Накладная закрыта. \n Но статус водителя не поменялся.");
        }
        if(!persons->conductor_work(idConductor,true)){
            QMessageBox::warning(this, "Что-то пошло не так", "Накладная закрыта. \n Но статус кондуктора не поменялся.");
        }
    }
    ui->textBrowser->setText(bills.get_openBills());
    ui->textBrowser_2->setText(bills.get_finishedBills());

}

void MainWindow::on_pushButton_6_clicked()//закрыть ремонтную
{
     BusRepository* buses = buswindow->get_currBusRepository();
     QString stringIdBill = ui->lineEdit_id->text();
     int idBill = stringIdBill.toInt();
      QString gosnomer = bills.get_gosnomerRepair(idBill);
      if (gosnomer == NULL) {
          QMessageBox::warning(this, "Что-то пошло не так", "Накладная не была закрыта. \n Попробуйте другой ID накладной.");
      }else if (!bills.finishRepairBill(idBill)){
          QMessageBox::warning(this, "Что-то пошло не так", "Накладная не была закрыта. \n Попробуйте другой ID накладной.");
      }
      if (!buses->changeStatusRepairPark(gosnomer,true)){
           QMessageBox::warning(this, "Что-то пошло не так", "Накладная закрыта. \n Но статус автобуса не поменялся.");
      }
      ui->textBrowser->setText(bills.get_openBills());
      ui->textBrowser_2->setText(bills.get_finishedBills());
}

void MainWindow::on_pushButton_7_clicked()
{
    QString data = bills.full_otchet();
    if (data == NULL)
        QMessageBox::warning(this, "Данных нет", "Недостаточно данных.\nОтсутствуют завершенные накладные.");
    else
        {
            otchetwindow->set_data(data);
            otchetwindow->show();
            this->close();
        }
}
