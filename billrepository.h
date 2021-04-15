#ifndef BILLREPOSITORY_H
#define BILLREPOSITORY_H
#include "waybill.h"
#include "repairbill.h"

class BillRepository
{
public:
    BillRepository();
    bool addNewWayBill(int idBill, QString gosNomerBus,int idDriver, int idConductor, unsigned int fare);
    bool addNewRepairBill(unsigned int cost, QString describtion,int idBill, QString gosNomerBus);
    bool deleteWayBill(int idBill);
    bool deleteRepairBill(int idBill);
    QString get_gosnomerWay(int idBill);//
    QString get_gosnomerRepair(int idBill);//
    int get_idDriver(int idBill);//
    int get_idConductor(int idBill);//
    QString get_openBills();
    QString get_finishedBills();
    bool finishWayBill(int idBill, unsigned int num);//
    bool finishRepairBill(int idBill);//
    QString full_otchet();
private:
    QVector <WayBill> wayBillRepos;
    QVector <RepairBill> repairBillRepos;
};

#endif // BILLREPOSITORY_H
