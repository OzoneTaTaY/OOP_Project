#include "bus.h"

Bus::Bus(){}
Bus::Bus(QString gosnomer, BusType busType, BusStatus busStatus){
    this->gosnomer = gosnomer;
    this->busType = busType;
    this->busStatus = busStatus;
}
//сеттеры
void Bus::set_gosnomer(QString gosnomer){
    this->gosnomer = gosnomer;
}
void Bus::set_BusType(BusType busType){
    this->busType = busType;
}
void Bus::set_BusStatus(BusStatus busStatus){
    this->busStatus = busStatus;
}
//геттеры
QString Bus::get_gosnomer(){
    return this->gosnomer;
}
Bus::BusType Bus::get_busType(){
    return this->busType;
}
Bus::BusStatus Bus::get_busStatus(){
    return this->busStatus;
}
