#ifndef REPAIRBILL_H
#define REPAIRBILL_H
#include "bill.h"

class RepairBill : public Bill
{
public:
    RepairBill();
    RepairBill(unsigned int cost, QString describtion,int idBill, QString gosNomerBus);
    int get_cost();
    QString get_describtion();
private:
    unsigned int cost;
    QString describtion;
};

#endif // REPAIRBILL_H
