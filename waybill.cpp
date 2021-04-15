#include "waybill.h"
WayBill::WayBill(){}

WayBill::WayBill(int idBill, QString gosNomerBus, int idDriver, int idConductor, unsigned int fare):Bill(idBill, gosNomerBus){
    this->idDriver = idDriver;
    this->idConductor = idConductor;
    this->fare = fare;
}
int WayBill::get_idDriver(){
    return this->idDriver;
}
int WayBill::get_idConductor(){
    return this->idConductor;
}

void WayBill::set_numberOfPassengers(unsigned int num){
    this->numberOfPassengers=num;
}
int WayBill::get_fare(){
    return this->fare;
}
int WayBill::get_numberOfPassengers(){
    return this->numberOfPassengers;

}
