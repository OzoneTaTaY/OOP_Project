#include "bill.h"

Bill::Bill(){}

Bill::Bill(int idBill, QString gosNomerBus){
    this->idBill = idBill;
    this->gosNomerBus = gosNomerBus;
    this->startTime = QTime::currentTime();
    this->startDate = QDate::currentDate();
    this->statusBill = false;
}

void Bill::finishBill(){
    this->finishTime = QTime::currentTime();
    this->finishDate = QDate::currentDate();
    this->statusBill = true;
}

int Bill::get_idBill(){
    return this->idBill;
}
QString Bill::get_gosNomerBus(){
    return this->gosNomerBus;
}
bool Bill::get_statusBill(){
    return this->statusBill;
}
QString Bill::get_stringStartDateTime(){
    QString data;
    data=this->startDate.toString()+" "+this->startTime.toString();
    return data;
}
QString Bill::get_stringFinishDateTime(){
    QString data;
    data=this->finishDate.toString()+" "+this->finishTime.toString();
    return data;
}
