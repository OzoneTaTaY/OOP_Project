#ifndef DRIVER_H
#define DRIVER_H
#include "person.h"

class Driver:public Person
{
public:
    Driver();
    Driver(QString driverLisenceType, QString driverLisenceTime, int id, QString firstName, QString secondName, int age, int salary);
    void set_Lisence(QString driverLisenceType, QString driverLisenceTime);
    QString get_dlTime();
    QString get_dlType();

private:
    QString driverLisenceType;
    QString driverLisenceTime;
};

#endif // DRIVER_H
