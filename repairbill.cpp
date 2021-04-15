#include "repairbill.h"

RepairBill::RepairBill()
{}

RepairBill::RepairBill(unsigned int cost, QString describtion,int idBill, QString gosNomerBus)
    :Bill(idBill, gosNomerBus){
    this->cost = cost;
    this->describtion = describtion;
}
int RepairBill::get_cost(){
    return this->cost;
}
QString RepairBill::get_describtion(){
    return this->describtion;
}
