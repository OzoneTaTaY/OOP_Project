#ifndef PERSONREPOSITORY_H
#define PERSONREPOSITORY_H
#include <QVector>
#include "driver.h"
#include "conductor.h"

class PersonRepository
{
public:
    PersonRepository();
    bool addDriver(QString driverLisenceType, QString driverLisenceTime, int id, QString firstName, QString secondName, int age, int salary);
    bool addConductor(unsigned int levelOfQualification, int id, QString firstName, QString secondName, int age, int salary);
    bool deleteDriver(int id);
    bool deleteConductor(int id);
    QString get_drivers();
    QString get_conductors();
    QString get_chill_persons();
    bool driver_vacation(int id);
    bool conductor_vacation(int id);
    bool driver_work(int id, bool flagok);
    bool conductor_work(int id, bool flagok);
private:
    QVector <Driver> driverRepos;
    QVector <Conductor> conductorRepos;
};

#endif // PERSONREPOSITORY_H

