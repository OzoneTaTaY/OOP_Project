#ifndef WAYBILL_H
#define WAYBILL_H
#include "bill.h"

class WayBill : public Bill
{
public:
    WayBill();
    WayBill(int idBill, QString gosNomerBus,int idDriver, int idConductor,unsigned int fare);
    int get_idDriver();
    int get_idConductor();
    int get_fare();
    int get_numberOfPassengers();
    void set_numberOfPassengers(unsigned int num);
private:
    int idDriver;
    int idConductor;
    unsigned int numberOfPassengers;
    unsigned int fare;
};

#endif // WAYBILL_H

//НАДО ДОДЕЛАТЬ КОГДА ДОПИШУ PERSON
