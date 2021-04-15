#include "driver.h"

Driver::Driver(){}

Driver::Driver(QString driverLisenceType, QString driverLisenceTime, int id, QString firstName, QString secondName, int age, int salary)
    :Person(id, firstName, secondName, age, salary){
    this->driverLisenceTime=driverLisenceTime;
    this->driverLisenceType=driverLisenceType;
}
void Driver::set_Lisence(QString driverLisenceType, QString driverLisenceTime){
    this->driverLisenceTime=driverLisenceTime;
    this->driverLisenceType=driverLisenceType;
}

QString Driver::get_dlTime(){
    return this->driverLisenceTime;
}
QString Driver::get_dlType(){
    return this->driverLisenceType;
}
