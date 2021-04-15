#include "busrepository.h"
BusRepository::BusRepository(){

}
bool BusRepository::addBus(QString gosnomer, Bus::BusType busType){
    bool flag =true;
    Bus::BusStatus busStatus = Bus::inPark;
    Bus bus = Bus(gosnomer, busType, busStatus);
    if (this->busRepos.size() > 0)
        for (int i=0; i < this->busRepos.size(); i++){
            if (this->busRepos[i].get_gosnomer() == gosnomer)
                flag = false;
        }
    if (flag){
        this->busRepos.push_back(bus);
        return true;
    }
    return false;
}

Bus* BusRepository::findBus(QString gosnomer){
    if (this->busRepos.size() > 0)
        for (int i=0; i < this->busRepos.size(); i++){
            if (this->busRepos[i].get_gosnomer() == gosnomer){
                Bus *a = &this->busRepos[i];
                return a;
            }
        }
    return nullptr;
}

bool BusRepository::deleteBus(QString gosnomer){
    if (this->busRepos.size() > 0)
        for (int i=0; i < this->busRepos.size(); i++){
            if (this->busRepos[i].get_gosnomer() == gosnomer){
                busRepos.remove(i);
                return true;
            }
        }
    return false;
}

QString BusRepository::get_fullBusRepos(){
    QString data;
     if (this->busRepos.size() == 0)
         return "В парке нет автобусов";
     else
         for (int i=0; i < this->busRepos.size(); i++)
         {
             data+=busRepos[i].get_gosnomer()+" | ";
             if (busRepos[i].get_busType() == Bus::MAZ){
                data+="МАЗ ";
             }
             else if (busRepos[i].get_busType() == Bus::LIAZ){
                 data+="ЛИАЗ ";
             }
             data+=" | ";
             if (busRepos[i].get_busStatus() == Bus::inPark){
                data+="В парке";
                data+='\n';
             }
             else if (busRepos[i].get_busStatus() == Bus::inRoad){
                 data+="На маршруте";
                 data+='\n';
              }
             else if (busRepos[i].get_busStatus() == Bus::inService){
                 data+="На ремонте";
                 data+='\n';
              }
         }
     return data;
}
bool BusRepository::changeStatusWorkPark(QString gosnomer, bool flagok){
    if (this->busRepos.size() == 0)
        return false;
    else
        for (int i=0; i < this->busRepos.size(); i++){
            if (busRepos[i].get_gosnomer()==gosnomer){
                if (busRepos[i].get_busStatus() == Bus::inPark && flagok == false){
                    busRepos[i].set_BusStatus(Bus::inRoad);
                    return true;
                }
                else if (busRepos[i].get_busStatus() == Bus::inRoad && flagok == true){
                        busRepos[i].set_BusStatus(Bus::inPark);
                        return true;
                }
            }
        }
    return false;
}
bool BusRepository::changeStatusRepairPark(QString gosnomer, bool flagok){
    if (this->busRepos.size() == 0)
        return false;
    else
        for (int i=0; i < this->busRepos.size(); i++){
            if (busRepos[i].get_gosnomer()==gosnomer){
                if (busRepos[i].get_busStatus() == Bus::inPark && flagok == false){
                    busRepos[i].set_BusStatus(Bus::inService);
                    return true;
                }
                else if (busRepos[i].get_busStatus() == Bus::inService && flagok == true){
                        busRepos[i].set_BusStatus(Bus::inPark);
                        return true;
                }
            }
        }
    return false;
}
