#ifndef BUSREPOSITORY_H
#define BUSREPOSITORY_H
#include "QVector"
#include "bus.h"
class BusRepository
{
public:
    BusRepository();
    bool addBus(QString gosnomer, Bus::BusType busType);
    bool deleteBus(QString gosnomer);
    Bus* findBus(QString gosnomer);
    QString get_fullBusRepos();
    bool changeStatusWorkPark(QString gosnomer, bool flagok);
    bool changeStatusRepairPark(QString gosnomer,bool flagok);
private:
    QVector <Bus> busRepos;
};

#endif // BUSREPOSITORY_H
